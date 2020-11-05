#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz{
    int r;
    int c;
    float tab[20][20];
};

void wczytaj(struct Macierz *m, char *nazwa)
{
    FILE *fin;
    fin = fopen(nazwa, "r");
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);    
    for (int i=0; i < m->r; i++) 
    {
        for (int j=0; j < m->c; j++)
        fscanf(fin, "%f", &m->tab[i][j]);
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

void suma(struct Macierz a,struct Macierz x,struct Macierz *w)
{   
    w->c = a.c;
    w->r = a.r;
    float pom = 0;
    if((a.r != x.r) || (a.c != x.c))   
    {
           printf("Nie mozna dodac tych dwóch maciezy !\n");
           exit(-2);
    }

    else
   {
        for (int i=0; i < a.r; i++) 
        {
        for (int j=0; j < a.c; j++)
        {
        pom = a.tab[i][j] + x.tab[i][j];
        w->tab[i][j] = pom;
        pom = 0;
        }
        }
    }
    
}

void odejmowanie(struct Macierz a,struct Macierz x,struct Macierz *w)
{   
    w->c = a.c;
    w->r = a.r;
    float pom = 0;
    if((a.r != x.r) || (a.c != x.c))   
    {
           printf("Nie mozna wykonac odejmowania na tej parze macierzy !\n");
           exit(-2);
    }

    else
   {
        for (int i=0; i < a.r; i++) 
        {
        for (int j=0; j < a.c; j++)
        {
        pom = a.tab[i][j] - x.tab[i][j];
        w->tab[i][j] = pom;
        pom = 0;
        }
        }
    }
    
}

void product(struct Macierz a,struct Macierz x,struct Macierz *w)
{   
    w->c = a.c;
    w->r = a.r;
    float pom = 0;
    if(a.c != x.r)  
    {
           printf("Nie mozna wykonac mnozeania na tej parze macierzy !\n");
           exit(-2);
    }

    else
   {
        for (int i=0; i < a.r; i++) 
        {
        for (int j=0; j < x.c; j++)
        {
            for(int w=0; w<x.r; w++)
            {
            pom += a.tab[i][w] * x.tab[w][j];
            }
            w->tab[i][j] = pom;
            pom = 0;
        }
        }
    }
    
}

void multiply(struct Macierz a,struct Macierz *w, float iloczyn)
{   
    w->c = a.c;
    w->r = a.r;     
    for (int i=0; i < a.r; i++) 
    {
        for (int j=0; j < a.c; j++)        
        w->tab[i][j] = a.tab[i][j] * iloczyn;
       
    }
 }

float norm(struct Macierz a)
{   
    float w = 0;
    for (int i=0; i < a.r; i++) 
    {
        for (int j=0; j < a.c; j++)        
        w += a.tab[i][j] * a.tab[i][j];       
    }
    
    return sqrtf(w);

 }

int main(int argc, char *argv[])
{
    struct Macierz A;
    wczytaj(&A,argv[2]);
    struct Macierz wynik;

    if (strcmp(argv[1],"sum") == 0)
    {   
        struct Macierz X;
        wczytaj(&X,argv[3]);
        suma(A,X,&wynik);
        printf("Wynik dodawania: \n");
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
    } 
    else if(strcmp(argv[1],"subtract") == 0)
    {   
        struct Macierz X;
        wczytaj(&X,argv[3]);
        odejmowanie(A,X,&wynik);
        printf("Wynik odejmowania: \n");
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
    }
    else if(strcmp(argv[1],"prod") == 0)
    {
        struct Macierz X;
        wczytaj(&X,argv[3]);
        product(A,X,&wynik);
        printf("Wynik mnożenia macierzy: \n");
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
    }
    else if(strcmp(argv[1],"multiply") == 0)
    {
        multiply(A,&wynik,atof(argv[3]));
        printf("Wynik mnożenia przez skalar: [%f]: \n",atof(argv[3]));
        wyswietl(wynik);
        if (argc == 5)
            zapisz(wynik,argv[4]);
    }
    else if(strcmp(argv[1],"norm") == 0)
    {   
        float w;
        w = norm(A);
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