#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Tableaux */

int* random(int n1, int n2, int nbr) {
    srand(time(NULL));
    int* tab = malloc(nbr * sizeof(int));
    int a = 0;
    for(int i=0; i<nbr; i++) {
        while(tab[i]<n1 || tab[i]>n2) {
            tab[i] = rand();
        }
        printf("%d\n",tab[i]);
        a = rand();
    }
    return tab;
}

int tq1() {
    srand(time(NULL));
    int tab[200];
    int b = 0;
    int inverse;
    printf("[ ");
    for(int i=0; i<200; i++) {
        while(b < 10 || b > 99) {
            b = rand();
        }
        tab[i] = b;
        printf("%d ; ", tab[i]);
        b = rand();
    }
    printf("]");
    printf("\n\nNouveau tableau :\n\n");
    printf("[ ");
    for(int j=0; j<200; j++) {
        if(tab[j] > tab[j+1]) {
            inverse = tab[j];
            tab[j] = tab[j+1];
            tab[j+1] = inverse;
            printf("%d ; ", tab[j]);
        }
    }
    printf("]");
    return 0;
}

/* Fonctions */

int tab2dim(int n, int m) {
    return 0;
}

int moy_gen_etu(int nb) {
    int *a = random(0,20, nb);
    printf("Premiere valeur : %d",a[0]);
    printf("\nDeuxieme valeur : %d",a[1]);
    return 0;
}
