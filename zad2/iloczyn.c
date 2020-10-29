#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wczytaj(char *nazwa,int liczba_wierszy, int liczba_kolumn, float A[liczba_wierszy][liczba_kolumn])
{
    
    FILE *fin;
    fin = fopen(nazwa, "r");   
    float pomoc;
    int i=1;
    for(i; i < liczba_wierszy + 3; i++)
    {   if (i < 3)
        fscanf(fin, "%f", &pomoc);
         else 
         {
            for(int j = 0; j<liczba_kolumn; j++)            
            fscanf(fin, "%f", &A[i-3][j]);                
            
            
         }

    }
    
    
}

int liczba_wierszy(char* nazwa)
{
    int liczba_wierszy, liczba_kolumn;
    FILE *fin;
    fin = fopen(nazwa, "r");  
    fscanf(fin, "%d %d", &liczba_wierszy, &liczba_kolumn);    
    return liczba_wierszy;

}

int liczba_kolumn(char* nazwa)
{
    int liczba_wierszy, liczba_kolumn;
    FILE *fin;
    fin = fopen(nazwa, "r");      
    fscanf(fin, "%d %d", &liczba_wierszy, &liczba_kolumn);    
    return liczba_kolumn;
}

void wyswietl_wyniki(int wiersze, int kolumny, float tablica[wiersze][kolumny])
{   
    int i;
     printf("lcziba wierszy(%d)\n ",wiersze);
    for (i = 0; i < wiersze; i++)
    {    
        printf("wiersz nr.: %d ",i);
        for (int j =0; j < kolumny; j++) 
        printf(" %f  ",tablica[i][j]);

        printf("\n");
    }
    
}

// program do obliczanai ilorazu A * x

int main(int argc, char *argv[])
{   
    float suma = 0;
    int wiersze_A = liczba_wierszy(argv[1]);
    int kolumny_A = liczba_kolumn(argv[1]);
    float A[wiersze_A][kolumny_A];
    wczytaj(argv[1],wiersze_A, kolumny_A, A);

    int wiersze_X = liczba_wierszy(argv[2]);
    int kolumny_X = liczba_kolumn(argv[2]);
    float X[wiersze_A][kolumny_X];
    wczytaj(argv[2],wiersze_X, kolumny_X, X);
        
    float wynik[wiersze_A][kolumny_X];
    if (kolumny_A == wiersze_X)
    {    
    for(int i =0; i < wiersze_A ; i++)
    {
        for(int j = 0; j < kolumny_X; j++)        
        {
            for (int w=0; w < wiersze_X; w++)
            {
                suma += A[i][w] * X[j][w];
            }
            wynik[i][j] = suma;
            suma = 0;
        }
    }
    }
    else
    {
        printf("Nie mozna pomonorzyc przez siebie tych macierzy");
    }
    
    wyswietl_wyniki(wiersze_A, kolumny_X,wynik);
   
    
    

    return 0;
}