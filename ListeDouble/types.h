#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <stdbool.h>

typedef struct {  //un carton de boites de chaussures
    int id;
    char nom[20];
    int taille;   //en cm
    float masse;  //en Kg
    int annee,mois,jour;
} T_personne;

// fonctions de comparaisons
bool comp_taille_AsupB ( T_personne a, T_personne b);
bool comp_taille_AinfB ( T_personne a, T_personne b);
bool comp_taille_AegaleB ( T_personne a, T_personne b);

bool comp_masse_AsupB  ( T_personne a, T_personne b);
bool comp_masse_AinfB  ( T_personne a, T_personne b);
bool comp_masse_AegaleB  ( T_personne a, T_personne b);


//fonctions d'entrées/sorties
void print( T_personne p);
void printTabPers (T_personne *tab, int taille);
void printTabPersRec (T_personne *tab, int taille);

T_personne getPers(int id);
void get(T_personne* bob, int id);


//fonctions de générations aleatoires
T_personne getPersAlea(int id);
T_personne* getTabPersAlea(int taille);

#endif // TYPES_H_INCLUDED
