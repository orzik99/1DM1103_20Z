// W pliku studenci.txt zmieniłem kod przedmiotu Mechanika,poniewaz miał taki sam kod jak programowanie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student;

int znajdz(char *szukany_nr, char nr_albumow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

int znajdz_przedmioty(char lista_przedmiotow[100][10], student dane[100], int n) {
    int ile_przedmiotow = 0;
    int i;

   for (int i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, lista_przedmiotow, ile_przedmiotow ) == -1) {
            strncpy(lista_przedmiotow[ile_przedmiotow], dane[i].kod_przed, 9); 
                   
            ile_przedmiotow++;
        }
    }
    return ile_przedmiotow;
}


void najlepszy_przedmiot(student dane[100],int ile_rekordow)
{
    char lista_przedmiotow[100][10];
    int ile_przedmiotow = 0;
    int pozycja;
    float suma_ocen[100];
    float srednia_ocen[100];
    int licznik[10];
    float najlepsza_srednia = 0;
    float najgorsza_srednia = 10;
    char nazwa_przedmiotu[100][100];
    char kod_przedmiotu[100][10];
    int najlepsza_pozycja;
    int najgorsza_pozycja;
    for(int i =0;i <10; i++)
        licznik[i] = 0;
    ile_przedmiotow = znajdz_przedmioty(lista_przedmiotow, dane, ile_rekordow);
   
    for(int j = 0; j < ile_rekordow; j++)
    {   
        pozycja = znajdz(dane[j].kod_przed, lista_przedmiotow, ile_przedmiotow);
        printf("%d \n", pozycja);
        suma_ocen[pozycja] += dane[j].ocena;
        strcpy(nazwa_przedmiotu[pozycja], dane[j].nazwa_przed);
        strcpy(kod_przedmiotu[pozycja],dane[j].kod_przed);
        licznik[pozycja] = licznik[pozycja] + 1;
    }       
    for (int i=0; i < ile_przedmiotow; i++) {
        if (najlepsza_srednia <suma_ocen[i] / licznik[i]) {
            najlepsza_srednia = suma_ocen[i] / licznik[i];
            najlepsza_pozycja = i;
        }
    }
    for (int i=0; i < ile_przedmiotow; i++) {
        if (najgorsza_srednia >suma_ocen[i] / licznik[i]) {
            najgorsza_srednia = suma_ocen[i] / licznik[i];
            najgorsza_pozycja = i;
        }
    }
    printf("Najlepsza średnia: %s - %s: %f\n",nazwa_przedmiotu[najlepsza_pozycja],kod_przedmiotu[najlepsza_pozycja],suma_ocen[najlepsza_pozycja]/licznik[najlepsza_pozycja]);
    printf("Najgorsza średnia: %s - %s: %f\n",nazwa_przedmiotu[najgorsza_pozycja],kod_przedmiotu[najgorsza_pozycja],suma_ocen[najgorsza_pozycja]/licznik[najgorsza_pozycja]);
}



int main(int argc, char *argv[])
{
    student dane[100];
    int ile;    
    ile = wczytaj(dane, argv[1]);    
    najlepszy_przedmiot(dane, ile);


    return 0;
}
