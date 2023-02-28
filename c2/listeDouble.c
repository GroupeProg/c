#include <stdio.h>
#include <stdlib.h>
#include "listeDouble.h"


//initListe ne fait pas de malloc, juste une initialisation à NULL du pointeur de liste
void initListe(T_liste *l){
    *l = NULL;
}


bool listeVide(T_liste l){
    return (l==NULL);
}

void alv_aux(T_liste l) {
    if (l->suiv != NULL) {
        printf("%d ", *(l->pdata));
        alv_aux(l->suiv);
    }
    else if (l != NULL) {
        printf("%d ", *(l->pdata));
    }
}

void afficheListeV1(T_liste li) {
    T_liste l = li;
    while(l->prec != NULL) {
        l = l->prec;
    }
    alv_aux(l);
}

T_liste ajoutEnTete(T_liste l, int mydata) {
    if
    T_liste temp
    T_liste liste = (T_liste)malloc(sizeof(T_cellule));
    liste->prec = NULL;
    liste->suiv = l;
    int *data = (int *)malloc(sizeof(int));
    *data = mydata;
    liste->pdata = data;

    return liste;
}

T_liste ajoutEnFin(T_liste l, int mydata) {
    T_liste liste = (T_liste)malloc(sizeof(T_cellule));
    liste->prec = l;
    liste->suiv = NULL;
    int *data = (int *)malloc(sizeof(int));
    *data = mydata;
    liste->pdata = data;

    return liste;
}
