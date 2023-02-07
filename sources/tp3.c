#include "tp3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int convert_jour(T_jour n) {
    if(n == 1){
        return "lundi";
    }
    if(n == 2){
        return "mardi";
    }
    if(n == 3){
        return "mercredi";
    }
    if(n == 4){
        return "jeudi";
    }
    if(n == 5){
        return "vendredi";
    }
    if(n == 6){
        return "samedi";
    }
    if(n == 7){
        return "dimanche";
    }
    else {
        return 0;
    }
}

int convert_mois(T_jour n) {
    int mois;
    if(n == 1){
        return "janvier";
    }
    if(n == 2){
        return "fevrier";
    }
    if(n == 3){
        return "mars";
    }
    if(n == 4){
        return "avril";
    }
    if(n == 5){
        return "mai";
    }
    if(n == 6){
        return "juin";
    }
    if(n == 7){
        return "juillet";
    }
    if(n == 8){
        return "aout";
    }
    if(n == 9){
        return "septembre";
    }
    if(n == 10){
        return "octobre";
    }
    if(n == 11){
        return "novembre";
    }
    if(n == 12){
        return "decembre";
    }
    else {
        return 0;
    }
}

void afficheDate(T_date D) {
    printf("La date affichee est le %s %d %s %d.", convert_jour(D.jour), D.njour, convert_mois(D.mois), D.annee);
}

// La fonction affiche la date à l'aide de fonctions de conversion entre les différents types

void saisieDate() {
    int jours;
    int jourm;
    int annee;
    printf("Entrer un jour de la semaine : ");
    scanf("%d", &jours);
    printf("Entrer un jour du mois : ");
    scanf("%d", &jourm);
    printf("Entrer une annee : ");
    scanf("%d", &annee);
    if(jourm<10 && jours<=7) {
        printf("Date : %d/0%d/%d", jours, jourm, annee);
    }
    if(jourm>=10 && jours<=7) {
        printf("Date : %d/0%d/%d", jours, jourm, annee);
    }
    else {
        printf("Recommencer.\n\n");
        saisieDate();
    }
}

// La fonction au dessus permet de saisir une date (uniquement au format numérique)

// Q6 : logiquement non ils ne sont pas dans la même case mémoire mais je peux me tromper

void saisieDateMenu() {
    int choixmenu;

    printf("\nNous allons choisir la date a l'aide de petits menus. Entrer un nombre pour choisir.\n\n");
    printf("Jour de la semaine :\n\n");
    printf("    1) Lundi\n");
    printf("    2) Mardi\n");
    printf("    3) Mercredi\n");
    printf("    4) Jeudi\n");
    printf("    5) Vendredi\n");
    printf("    6) Samedi\n");
    printf("    7) Dimanche\n");
    printf("\nVotre choix : ");
    scanf("%d", &choixmenu);

    switch(choixmenu) {
        case 1:
            printf("Vous avez choisi lundi");
            break;
        case 2:
            printf("Vous avez choisi mardi");
            break;
        case 3:
            printf("Vous avez choisi mercredi");
            break;
        case 4:
            printf("Vous avez choisi jeudi");
            break;
        case 5:
            printf("Vous avez choisi vendredi");
            break;
        case 6:
            printf("Vous avez choisi samedi");
            break;
        case 7:
            printf("Vous avez choisi dimanche");
            break;
        default:
            printf("Vous n'avez choisi aucun jour de la semaine... Recommencez.\n");
            saisieDateMenu();
    }
}

// La fonction permet d'entrer un jour à l'aide de menu, n'y voyant pas d'utilités à continuer je n'ai pas finis la fonction...

/* POINTEURS */

int affichePoint() {
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

int tabPoint() {
    int tab[5];
    int *ptr = tab[0];
    for(int i=0; i<5; i++) {
        ptr = tab[i];
    }
    return 0;
}

// Pas compris comment faire la fonction tabpoint (et la question)...

int comparePoint() {
    int a = 7;
    int b = 10;
    int *p = a;
    int *q = b;
    printf("adresse du pointeur p : %p\n", &p);
    printf("adresse du pointeur q : %p\n", &q);
    printf("taille de la variable a sur laquelle pointe p : %d", sizeof(a));
    return 0;
}

// Etrangement les adresses sont séparées par 8 octets alors que la variable a prend 4 octet

int *alloueDate() {
    printf("");
}

// A finir

/* TABLEAUX BIS REPETITA */

float *allocTabFloat(int size) {
    return (float*)malloc(sizeof(float*)*size);
    free(size);
}

int allocTabFloatPrompt() {
    int size;
    printf("Donnez la taille du tableau : ");
    scanf("%d", &size);
    float *tab = allocTabFloat(size);
    return 0;
}
