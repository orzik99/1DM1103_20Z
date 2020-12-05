#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct Student *nast;
} Student;

typedef struct _Przedmiot {
    char * nazwa;
    char * nr_przedmiotu;
    char * semestr;
    struct _Przedmiot *nast;
 } Przedmiot;


typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;
    float ocena;
    char * komentarz;

    struct _Ocena *nast;
 } Ocena;


typedef struct _SBaza {
    Student *lista_studentow; 
} SBaza;

typedef struct _PBaza {
    Student *lista_przedmiotow; 
} PBaza;

typedef struct _OBaza {
    Student *lista_ocen; 
} OBaza;


SBaza * wczytaj_Sbaze(char *nazwa_pliku);


PBaza * wczytaj_Pbaze(char *nazwa_pliku);


OBaza * wczytaj_Obaze(char *nazwa_pliku);


void listuj_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
void listuj_przedmioty(PBaza *baza);
void listuj_oceny(OBaza *baza);

int ile_przedmiotow(PBaza *baza);
int ile_ocen(OBaza *baza);
int ile_studentow(SBaza *baza);

Student * dodaj_studenta(SBaza *head, char  *imie, char  *nazwisko, char *numer, char  *email);

Przedmiot * dodaj_przedmiot(PBaza *head, char  *nazwa, char  *numer, char *semestr);

Ocena * dodaj_ocene(OBaza *head, char  *numer, char  *kod, char *ocena, char  *komentarz);

void zapisz_baze(char *nazwa_pliku,SBaza *sbaza,PBaza *pbaza, OBaza *obaza);

#endif