#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
#include "dziekanat.h"




int main(int argc, char *argv[])
{
    student dane[100];
    int ile;
    char nazwa[13];
    strncpy(nazwa,argv[1],13);   
    ile = wczytaj(dane, nazwa);

    if(strcmp(argv[2],"przedmioty") == 0)    
    najlepszy_przedmiot(dane, ile);

    if(strcmp(argv[2],"student") == 0)
    najlepszy_student(dane,ile);

    return 0;
}
