#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "operacje_mat.h"
#include "operacje_plikowe.h"


int main(int argc, char *argv[])
{
    struct Macierz *A = (struct Macierz *)malloc(sizeof(struct Macierz));    
    wczytaj(&A,argv[2]);
    struct Macierz wynik;
    

    if (strcmp(argv[1],"sum") == 0)
    {   
        struct Macierz X;       
        wczytaj(&X,argv[3]);
        suma(&A,X,&wynik);
        printf("Wynik dodawania: \n");
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
        
    } 
    else if(strcmp(argv[1],"subtract") == 0)
    {   
        struct Macierz X;
        wczytaj(&X,argv[3]);
        odejmowanie(&A,X,&wynik);
        printf("Wynik odejmowania: \n");
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
    }
    else if(strcmp(argv[1],"prod") == 0)
    {
        struct Macierz X;
        wczytaj(&X,argv[3]);
        product(&A,X,&wynik);
        printf("Wynik mnożenia macierzy: \n");
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
    }
    else if(strcmp(argv[1],"multiply") == 0)
    {
        multiply(&A,&wynik,atof(argv[3]));
        printf("Wynik mnożenia przez skalar: [%f]: \n",atof(argv[3]));
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
    }
    else if(strcmp(argv[1],"norm") == 0)
    {   
        float w;
        w = norm(&A);
        printf("Norma macierzy A:[%f]\n",w);
        if (argc == 4)
            {
                FILE *fin;
                fin = fopen(argv[3], "w");
                fprintf(fin, "%f\n", w);
            }
    }
    else
    {
        printf("Podana komenda jest nieprawidłowa");
    }
    
    
    return 0;
}