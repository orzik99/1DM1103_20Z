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
        sbaza->lista_studentow = dodaj_studenta(sbaza, argv[3], argv[4], argv[5], argv[6]);

    listuj_studentow(sbaza);
    return 0;
}
