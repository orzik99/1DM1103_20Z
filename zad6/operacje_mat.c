#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "operacje_mat.h"

void suma(struct Macierz *a,struct Macierz x,struct Macierz *w)
{   
    w->c = a->c;
    w->r = a->r;
    float pom = 0;
    if((a->r != x.r) || (a->c != x.c))   
    {
           printf("Nie mozna dodac tych dwóch maciezy !\n");
           exit(-2);
    }

    else
   {
        for (int i=0; i < a->r; i++) 
        {
        for (int j=0; j < a->c; j++)
        {
        pom = a->tab[i][j] + x.tab[i][j];
        w->tab[i][j] = pom;
        pom = 0;
        }
        }
    }
    
}

void odejmowanie(struct Macierz *a,struct Macierz x,struct Macierz *w)
{   
    w->c = a->c;
    w->r = a->r;
    float pom = 0;
    if((a->r != x.r) || (a->c != x.c))   
    {
           printf("Nie mozna wykonac odejmowania na tej parze macierzy !\n");
           exit(-2);
    }

    else
   {
        for (int i=0; i < a->r; i++) 
        {
        for (int j=0; j < a->c; j++)
        {
        pom = a->tab[i][j] - x.tab[i][j];
        w->tab[i][j] = pom;
        pom = 0;
        }
        }
    }
    
}

void product(struct Macierz *a,struct Macierz x,struct Macierz *w)
{   
    w->c = a->c;
    w->r = a->r;
    float pom = 0;
    if(a->c != x.r)  
    {
           printf("Nie mozna wykonac mnozeania na tej parze macierzy !\n");
           exit(-2);
    }

    else
   {
        for (int i=0; i < a->r; i++) 
        {
        for (int j=0; j < x.c; j++)
        {
            for(int w=0; w< x.r; w++)
            {
            pom += a->tab[i][w] * x.tab[w][j];
            }
            w->tab[i][j] = pom;
            pom = 0;
        }
        }
    }
    
}

void multiply(struct Macierz *a,struct Macierz *w, float iloczyn)
{   
    w->c = a->c;
    w->r = a->r;     
    for (int i=0; i < a->r; i++) 
    {
        for (int j=0; j < a->c; j++)        
        w->tab[i][j] = a->tab[i][j] * iloczyn;
       
    }
 }

float norm(struct Macierz *a)
{   
    float w = 0;
    for (int i=0; i < a->r; i++) 
    {
        for (int j=0; j < a->c; j++)        
        w += a->tab[i][j] * a->tab[i][j];       
    }
    float wynik = 5;
    return wynik;

 }