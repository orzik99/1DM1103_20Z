#ifndef _operacje_plikowe_h 
#define _operacje_plikowe_h


struct Macierz{
    int r;
    int c;
    float **tab;
};
void wczytaj(struct Macierz *m, char *nazwa);
void zapisz(struct Macierz m,char *nazwa);
void wyswietl(struct Macierz m);
#endif
