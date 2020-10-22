#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main (int argc, char *argv[])
{
    char n[100];
    char n2[] = "ULLLALALALa";
    char tab[10][10];

    strcpy(tab[0],"akukuku");
    strcpy(tab[1], "heyyyyyyy");
    strcpy(n, "Ala");
    printf("%s %s %s %s\n",n,n2,tab[0],tab[1]);
    
    for(int i = 0; i<3; i++)
    { 
        printf("[%d]: %c, %d\n",i,n[i], n[i]);
    }

    printf("trzeci znak z pierwszego napisu %c\n", argv[1][2]); 
    return 0;
}