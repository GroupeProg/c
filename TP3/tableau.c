#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tableau.h"


float *alloctabfloat(int taille){
    float *tab = (float *)malloc(sizeof(float)*taille);
    return tab;
}

float *remplittab(float *tab, int size){
    float *p=tab;
    for(int i=0; i<size; i++){
        scanf("%f", p);
        p++;
    }
    return tab;
}

float *remplitabalea(float *tab, int taille){
    srand(time(NULL));
    for(int i=0; i<taille; i++){
        tab[i]=rand() %10;
    }
    return tab;
}

void affichetab(float *tab, int size){
    for(int i=0; i<size; i++){
        printf("%f ",tab[i]);
    }
    printf("\n");
}
