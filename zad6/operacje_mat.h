#ifndef _operacje_mat_h
#define _operacje_mat_h
#include "operacje_plikowe.h"

void suma(struct Macierz *a,struct Macierz x,struct Macierz *w);
void odejmowanie(struct Macierz *a,struct Macierz x,struct Macierz *w);
void product(struct Macierz *a,struct Macierz x,struct Macierz *w);
void multiply(struct Macierz *a,struct Macierz *w, float iloczyn);
float norm(struct Macierz *a);

#endif