#include <stdlib.h>
#include <stdio.h>
#include "tp.h"

//Premiers programmes:
//Un programme qui demande a l’utilisateur son prenom, puis son nom, et affiche 'Bonjour prenom nom'.
int quisuisje(){
    char p[10],n[10];
    printf("Ton prenom? ");
    scanf("%s", p);
    printf("Ton nom? ");
    scanf("%s", n);
    printf("Dak %s %s, ty est un vrai BG toi.\n", p,n);
    return 0;
}

//Un programme qui permute deux valeurs entieres et les affiche avant et apres permutation.
int permute(){
    int a, b, c;
    printf("Un nombre ? ");
    scanf("%d", &a);
    printf("Un autre nombre ? ");
    scanf("%d", &b);
    printf("Dak, tes deux nombres sont : %d et %d.\n", a,b);
    c = a;
    a = b;
    b = c;
    printf("Tiens tes nombres apres permutation:  %d et %d.\n", a,b);
    return 0;
}

//Structures de controle:
//Un programme qui indique si une annee donnee par l’utilisateur est bissextile.
int year(){
    int y;
    printf("Une annee? ");
    scanf("%d", &y);
    if ((y%4 == 0 && y%100 != 0)||(y%400 == 0)){
        printf("Bissextile! ;p \n");      
    }
    else{
        printf("PAS Bissextile! ;p \n");
    }
    return 0;
}

// Afficher division, remarquer que faire un int sur un float prend seulement la valeur entière.
int division() {
    int a, b;
    printf("Valeur a : ");
    scanf("%d", &a);
    printf("\nValeur de b : ");
    scanf("%d", &b);
    printf("\n%d", (a/b));

    return 0;
}
