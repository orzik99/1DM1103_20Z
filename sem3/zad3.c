#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
    float a1;
    a1 = atof(argv[1]);
    printf("Wartość %f do kwadratu to %f.\n",a1,a1*a1);



    return 0;
}