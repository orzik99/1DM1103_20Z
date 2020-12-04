#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}


Przedmiot * wczytaj_przedmioty(FILE *fin)
 {
    char bufor[255];
    char ignor[255];
    int n, i, l;
    char *s;
    Przedmiot *last_student = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);   
    for(int k =0; k<n; k++)
    {
    fgets(bufor, 254, fin);
    }    
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &l); 

    for (i=0; i<l; i++)
    {
        Przedmiot *stud = (Przedmiot*) malloc(sizeof(Przedmiot));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->nr_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_przedmiotu, s);       

        s = strtok(NULL, ";");
        stud->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwa, s);

        s = strtok(NULL, "\n");
        stud->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->semestr, s);

        
    }

    return glowa;
}


Ocena * wczytaj_ocene(FILE *fin) {
    char bufor[255];
    int n, i, l, nn;
    char *s;
    Ocena *last_student = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for(int k =0; k<n; k++)
    {
    fgets(bufor, 254, fin);
    }    
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &l);

    for(int o = 0; o<l; o++)
    {
    fgets(bufor, 254, fin);
    }
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &nn); 

    for (i=0; i<nn; i++) {
        Ocena *stud = (Ocena*) malloc(sizeof(Ocena));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->kod_przedmiotu, s);
       

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, ";");        
        stud->ocena=atof(s);

        s = strtok(NULL, "\n");
        stud->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->komentarz, s);
    }

    return glowa;
}

SBaza * wczytaj_Sbaze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);

    fclose(fin);
    return baza;
}

PBaza * wczytaj_Pbaze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    PBaza *baza = (PBaza*) malloc( sizeof(PBaza) );
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);

    fclose(fin);
    return baza;
}
OBaza * wczytaj_Obaze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    OBaza *baza = (OBaza*) malloc( sizeof(OBaza) );
    baza->lista_ocen = wczytaj_ocene(fin);

    fclose(fin);
    return baza;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(PBaza *baza) {
    int n = 0;
    Przedmiot * stud = baza->lista_przedmiotow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_ocen(OBaza *baza) {
    int n = 0;
    Ocena * stud = baza->lista_ocen;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

Student * dodaj_studenta(SBaza *head, char  *imie, char  *nazwisko, char *numer, char  *email)
{
    printf("TEST 1 %s",imie);  
    Student *glowa = NULL;
    Student *nowy = (Student*) malloc(sizeof(Student));    
    strcpy(nowy->imie, imie);
    strcpy(nowy->nazwisko, nazwisko);
    strcpy(nowy->nr_albumu, numer);
    strcpy(nowy->email, email);   
    nowy->nast = head->lista_studentow;
    glowa = nowy;
    return glowa;
    
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_przedmioty(PBaza *baza) {
    Przedmiot * stud = baza->lista_przedmiotow;
    while (stud != NULL) {
        printf("%s %s %s \n", stud->nazwa, stud->nr_przedmiotu, stud->semestr);
        stud = stud->nast;
    }
}


void listuj_oceny(OBaza *baza) {
    Ocena * stud = baza->lista_ocen;
    while (stud != NULL) {
        printf("%s %s %f %s\n", stud->kod_przedmiotu, stud->nr_albumu, stud->ocena, stud->komentarz);
        stud = stud->nast;
    }
}