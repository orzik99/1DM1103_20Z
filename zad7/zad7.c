#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv)
 {
    SBaza *sbaza;
    sbaza = wczytaj_Sbaze(argv[1]);
    listuj_studentow(sbaza);
    
    PBaza *pbaza;
    pbaza = wczytaj_Pbaze(argv[1]);    
    listuj_przedmioty(pbaza);

    OBaza *obaza;
    obaza = wczytaj_Obaze(argv[1]);
    listuj_oceny(obaza);
   
    if (strcmp("add_student", argv[2]) == 0)
    {
        sbaza->lista_studentow = dodaj_studenta(sbaza, argv[3], argv[4], argv[5], argv[6]);
    }
    else if(strcmp("add_przedmiot", argv[2]) == 0)
    {
        pbaza->lista_przedmiotow = dodaj_przedmiot(pbaza, argv[3], argv[4], argv[5]); 
    }
    else if (strcmp("add_ocena", argv[2]) == 0)
    {
        obaza->lista_ocen = dodaj_ocene(obaza, argv[3], argv[4], argv[5], argv[6]);
    }
   

    listuj_studentow(sbaza);
    zapisz_baze(argv[1], sbaza, pbaza, obaza);
    return 0;
}
