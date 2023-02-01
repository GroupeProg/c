#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* FONCTIONS */

int ligne_aux(int n) {
    if(n==0) {
        return 0;
    }
    printf("*\n");
    ligne_aux(n-1);
}

int ligne(int n) {
    ligne_aux(n);
}

// Ces deux fonctions font apparaître une étoile par ligne, le nombre de ligne étant determiné par n
// Je m'aide d'une fonction auxiliaire pour ne pas faire apparaître pour ne pas faire apparaître plusieurs fois la demande de saisie d'un entier (1ère question)

int moyenne(int a, int b ,int c) {
    float d;
    d = (a+b+c)/3.0;
    printf("%f", d);
    return 0;
}

// Cette fonction fait un simple calcul de moyenne à l'aide d'entiers renvoyant un flottant, la conversion se fait automatiquement -> il suffit de remplacer %d par %f pour afficher une décimale à virgule

int polynome(int a, int b, int c) {
    int d;
    d = pow(b,2)-4*a*c;
    printf("Determinant : %d \n", d);
    if(d<0) {
        printf("Le polynome n'a pas de racines");
    }
    if(d==0) {
        int x = -b/(2*a);
        printf("Le polynome n'a qu'une seule racine : x1 = %d", x);
    }
    if(d>0) {
        int x1 = (-b-(sqrt(d)))/(2*a);
        int x2 = (-b+(sqrt(d)))/(2*a);
        printf("Le polynome a deux racines racine : x1 = %d et x2 = %d", x1, x2);
    }
    return 0;
}

// La fonction calcule un polynome du 2nd degré avec les coefficients entrés en paramètres

int random(int n1, int n2, int nbr) {
    srand(time(NULL));
    int* tab = malloc(nbr * sizeof(int));
    int a = 0;
    printf("{");
    for(int i=0; i<nbr; i++) {
        while(tab[i]<n1 || tab[i]>n2) {
            tab[i] = rand();
        }
        printf(" %d ",tab[i]);
        printf(";");
        a = rand();
    }
    printf("}");
    return tab;
}

// Cette fonction permet de calculer un tableau de nombres aléatoires compris entre n1 et n2
// Je vérifie bien que le rand() est compris entre les deux nombres, et pour éviter qu'il ne bloque sur la même valeur, je le réinitialise à chaque tour de boucle

int tab2dim(int n, int m) {
    int tab2[n][m];
    for(int i=0; i<n; i++) {
        tab2[i][m] = random(0,20,5);
        printf(" math");
        printf(", ");
    }
}

int moy_gen(int nb) {
    int *a = random(0,20,nb);
    int moy;
    for(int i=0; i<nb; i++) {
        moy += a[i];
    }
    moy = moy/nb;
    printf("\nmoyenne = %d", moy);
    return moy;
}

// Cette fonction calcule la moyenne generale de notes générées aléatoirement avec la fonction random (j'utilise un pointeur pour récuperer le tableau)

int m_note(int nb) {
    int *a = random(0,20,nb);
    int m = a[0];
    for(int i=0; i<nb; i++) {
        if(a[i] > m) {
            m = a[i];
        }
    }
    printf("\nMeilleur note : %d", m);
    return m;
}

// Cette fonction calcule la meilleure note parmis un nombre de notes aléatoires avec à peu près le même fonctionnement que la fonction du dessus
// Seulement cette fois, j'initialise m comme première valeur du tableau puis je compare cette valeur avec les autres, si m est inférieur à la valeur suivante, celle-ci lui est donc affectée et ainsi de suite

/* FONCTIONS RECURSIVES */

int facto(int n) {
    if(n > 0){
        return n * facto(n-1);
    }
    else{
        return 1;
    }
}

// Fonction principale qui return la valeur à la fonction en dessous

void facto_afficheur()
{
    int n;
    printf("Cette fonction va donner un factoriel d'un nombre n.\nNombre n : ");
    scanf("%d", &n);
    int f = facto(n);
    printf("\nCe qui donne : %d", f);
}

int fibo(int U0, int U1, int n) {
    int UN;
    if(n>0) {
        UN = U0 + U1;
        U1 = UN;
        U0 = U1;
        return fibo(U0,U1,n-1);
    }
    else {
        return U1;
    }
}

// Même principe mais la fonction de marche pas, elle n'affiche pas la bonne valeur et je n'ai pas compris pourquoi...

void fibonacci_tp2_afficheur() {
    int u0, u1, n;
    printf("Nombre pour U0 : ");
    scanf("%lu", &u0);
    printf("\nNombre pour U1 : ");
    scanf("%lu", &u1);
    printf("\nNombre pour n : ");
    scanf("%lu", &n);
    int fib = fibo(u0, u1, n);
    printf("FIBO : %d\n", fib);
}
