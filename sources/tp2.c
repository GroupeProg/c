#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Tableaux */

int random() {
    srand(time(NULL));
    int a = 0;
    for(int i=0; i<10; i++) {
        while(a<10 || a>99) {
            a = rand();
        }
        printf("%d\n",a);
        a = rand();
    }
    return 0;
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

int ligne() {
    int n;
    printf("Saisir une valeur : ");
    scanf("%d", &n);
    printf("*");
    n * ligne();
}
