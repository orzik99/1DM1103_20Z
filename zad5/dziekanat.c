#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dziekanat.h"




void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

   
    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

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





