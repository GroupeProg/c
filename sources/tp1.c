#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int q1()
{
    char nom[20];
    char prenom[20];
    printf("Entrer votre nom :");
    scanf("%s", nom);
    printf("Entrer votre prenom :");
    scanf("%s", prenom);
    printf("Bonjour %s %s", prenom, nom);
    return 0;
}

int q3()
{
    int a, b, c;
    printf("La premiere valeur :");
    scanf("%d", &a);
    printf("La seconde valeur :");
    scanf("%d", &b);
    printf("%d %d\n", a, b);
    c = a;
    a = b;
    b = c;
    printf("Inversion : %d %d", a, b);
    return 0;
}

int q4()
{
    int a, b, c;
    float d;
    printf("Entrer une valeur entiere :");
    scanf("%d", &a);
    printf("Entrer une seconde valeur entiere :");
    scanf("%d", &b);
    printf("Premiere valeur = %d et deuxieme valeur = %d\n", a, b);
    c = a / b;
    printf("Division de a par b : %d", c);
    return 0;
}

int q5()
{
    int annee, calcul;
    printf("Entrer une annee : ");
    scanf("%d", &annee);
    if((annee%4 == 0 && annee%100 != 0) || annee%400 ==0)  {
        printf("L'annee %d est bissextile", annee);
    }
    else
    {
        printf("L'annee %d n'est pas bissextile", annee);
    }
    return 0;
}

int q6()
{
    int mois;
    printf("Entrer un mois entre 1 et 12: ");
    scanf("%d", &mois);
    while(mois > 12) {
        printf("Nombre superieur a 12, recommencez : ");
        scanf("%d", &mois);
    }
    switch(mois) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Le mois compte 31 jours");
        break;
    case 2:
        printf("Le mois compte 28 ou 29 jours");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Le mois compte 30 jours");
        break;
    }
    return 0;
}

int q7()
{
    int a, b, c;
    printf("Entrer un nombre: ");
    scanf("%d", &a);
    printf("Entrer un deuxieme nombre: ");
    scanf("%d", &b);
    if(a==0) {
        return 0;
    }
    else {
        c = a;
        while(b!=1) {
            a+=c;
            b-=1;
        }
       printf("Le resultat est %d", a);
    }
}

int q8()
{
    int h, h1;
    h1 = 0;
    printf("Entrer une hauteur: ");
    scanf("%d", &h);
    while(h1!=h) {
        if(h1==0) {
            int a;
            a = 0;
            printf("%d",a);
            printf("\n");
        }
        else {
            int a;
            a = 1;
            printf("0%d0",a);
            printf("\n");
        }
        h1+= 1;
    }
    return 0;
}

/* Tableaux */

int tq5() {
    int a = 10;
    int tab[a];
    int b;
    for(int i = 0; i<a; i++) {
        tab[i] = rand();
        printf("%d\n", tab[i]);
        b += tab[i];
    }
    printf("La moyenne des valeurs aleatoires d'un tableau de 10 cases est : %d", b/10);
    return 0;
}

int tq6() {
    int a = 10;
    int tab[a];
    for(int i = 0; i<a; i++) {
        tab[i] = rand();
        printf("%d\n", tab[i]);
    }
    int b = tab[0];
    int c = tab[0];
    for(int j=0; j<a; j++) {
        if((tab[j] < tab[j+1]) && (tab[j] < b))  {
            b = tab[j];
        }
        if((tab[j] > tab[j+1]) && (tab[j] > c))  {
            c = tab[j];
        }
    }
    printf("La plus petite valeur du tableau est %d et son indice est %d", b, &b);
    printf("\nLa plus grande valeur du tableau est %d et son indice est %d", c, &c);
    return 0;
}

int tq7() {
    int tab[5];
    tab[0] = 1;
    tab[1] = 3;
    tab[2] = -5;
    tab[3] = -7;
    tab[4] = 8;
    for(int i=0; i<5; i++) {
        if(tab[i]<0) {
            int tab1[2];
            tab1[i] = tab[i];
            printf("Premier tableau : ");
            printf("%d \n", tab1[i]);
        }
        else {
            int tab2[3];
            tab2[i] = tab[i];
            printf("Second tableau : ");
            printf("%d \n", tab2[i]);
        }
    }
    return 0;
}

int tq8() {
    int e;
    int b;
    printf("Entrer un entier superieur a 0 : ");
    scanf("%d", &e);
    int tab[e/2];
    for(int i = 0; i<e; i++) {
        while(e != 0) {
            b = e%2;
            e = e/2;
            tab[i] = b;
            printf("%d", tab[i]);
        }
    }
    printf("\n");
    int tab1[e/2];
    int m = 0;
    for(int j = e/2; j>0; j--) {
        tab[j] = tab[m];
        m += 1;
        printf("%d", tab[j]);
     }
    return 0;
}

int tq9() {
    int tab[100];
    for(int i = 0; i<100; i++) {
        tab[i] = rand();
        printf("%d\n", tab[i]);
        if(tab[i] > tab[i+1]) {
            int a = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = a;
        }
    }
    return 0;
}

/* chaine de caractere */

int cq1() {
    char a[20];
    char b[20];
    printf("Entrer une chaine de caractere : ");
    scanf("%s",&a);
    printf("Entrer une seconde chaine de caractere : ");
    scanf("%s",&b);
    int result;
    result = strcmp(a, b);
    if(result == 0) {
        printf("Les deux chaines de caracteres sont egales");
    }
    else {
        printf("Les deux chaines de caracteres ne sont pas egales");
    }
    return 0;
}

int cq2() {
    char a[20];
    printf("Entrer une chaine de caractere : ");
    scanf("%s",&a);
    char tab[20];
    for(int i=0; i<strlen(a); i++) {
        strcpy(tab, a);
        printf("%c", tab[i]);
    }
    return 0;
}

int cq3() {
    char a[20];
    char b[20];
    printf("Entrer une chaine de caractere : ");
    scanf("%s",&a);
    printf("Entrer une seconde chaine de caractere : ");
    scanf("%s",&b);
    int result;
    result = strcat(a, b);
    printf("%s", result);
    return 0;
}

int cq5 () {
    char mot[20];
    int nbr;
    printf("Entrer une chaine de caractere : ");
    scanf("%s",&mot);
    printf("Entrer un entier : ");
    scanf("%d",&nbr);
    for(int i = 1; i <= nbr; i++) {
        if (i >= strlen(mot))
        {
            printf("Valeur de nombre de lignes trop grande.");
            break;
        }
        printf("%d : ", i);
        for(int j = 0; j < i; j++) {
            printf("%c", mot[j]);
        }
        printf("\n");
    }
    return 0;
}

int cq6() {
    char m[20];
    printf("Entrer une chaine de caractere : ");
    scanf("%s",&m);
    for(int i = strlen(m)-1; i>=0; i--) {
        printf("%c", m[i]);
    }
    return 0;
}

int cq7() {
    char m[20];
    char a[20];
    char b[20];
    printf("Entrer une chaine de caractere : ");
    scanf("%s",&m);
    for(int i = 0; i<strlen(m); i++) {
        printf("%c", m[i]);
        a[i] = m[i];
    }
    printf("\n");
    int k = 0;
    for(int j = strlen(m)-1; j>=0; j--) {
        printf("%c", m[j]);
        b[j] = m[k];
        k += 1;
    }
    if(a == b) {
        printf("\nCe mot est un palindrome");
    }
    else {
        printf("\nCe mot n'est pas un palindrome");
    }
    printf("\n%s", a);
    printf("\n%s", b);
    return 0;
}
