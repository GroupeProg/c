#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tp3.h"

/* POINTEURS */

int affichepoint() {
    int a = 5;
    int *p = a;
    int *q = NULL;
    printf("Entrer une nouvelle valeur :");
    scanf("%d", &a);
    p = a;
    printf("Le contenu du pointeur : %d\n", p);
    printf("L'adresse du pointeur : %d\n", &p);
    printf("La valeur pointee : %d\n", a);
    printf("L'adresse de la valeur pointee: %d\n", &a);
    return 0;
}

int tabpoint() {
    int tab[5];
    int *ptr = tab[0];
    for(int i=0; i<5; i++) {
        ptr = tab[i];
    }
    return 0;
}

// Pas compris comment faire la fonction tabpoint (et la question)...

int comparepoint() {
    int a = 7;
    int b = 10;
    int *p = a;
    int *q = b;
    printf("adresse du pointeur p : %d\n", &p);
    printf("adresse du pointeur q : %d\n", &q);
    printf("taille de la variable a sur laquelle pointe p : %d", sizeof(a));
    return 0;
}

// Etrangement les adresses sont séparées par 8 octets alors que la variable a prend 4 octet
