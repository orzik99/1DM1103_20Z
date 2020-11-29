#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacje_plikowe.h"

void wczytaj(struct Macierz *m, char *nazwa)
{
    int i;
    FILE *fin;
    fin = fopen(nazwa, "r");
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    m->tab = (float**) malloc(sizeof(float*) * m->r);

    for (i=0; i < m->r ;i++)
    {
     m->tab[i] = (float*) malloc(sizeof(float) * m->c);
    }       
    

    for (int w=0; w < m->r; w++) 
    {
        for (int g=0; g < m->c; g++)
        fscanf(fin, "%f", &m->tab[w][g]);
    }
   
}

void zapisz(struct Macierz m,char *nazwa)
{
    FILE *fin;
    fin = fopen(nazwa, "w");
    fprintf(fin, "%d\n%d\n", m.r, m.c);
    for (int i=0; i < m.r; i++) 
    {
        for (int j=0; j < m.c; j++)
        fprintf(fin, "%f ", m.tab[i][j]);

        if (i < (m.r-1))
        fprintf(fin,"\n");
    }

    
}

void wyswietl(struct Macierz m)
{   
    printf("[ ");
    for (int i=0; i < m.r; i++) 
    {
        for (int j=0; j < m.c; j++)
        printf(" %f ", m.tab[i][j]);
        if (i < (m.r-1))
        printf("\n");
    }
    printf("]\n");
}