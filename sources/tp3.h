#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED

typedef enum{lundi = 1, mardi = 2, mercredi = 3, jeudi = 4, vendredi = 5, samedi = 6, dimanche = 7}T_jour;

// Q1 : type énuméré des jours de la semaine

typedef enum{janvier = 1, fevrier = 2, mars = 3, avril = 4, mai = 5, juin = 6, jullet = 7, aout = 8, septembre = 9, octobre = 10, novembre = 11, decembre = 12}T_mois;

// Q2 : meme chose avec les mois

typedef struct{
    T_jour jour;
    int njour;
    T_mois mois;
    int annee;
}T_date;

// Q3 : type structuré pour représenter une date

/* FONCTIONS */

int convert_jour();
int convert_mois();
void afficheDate();
void saisieDate();
void saisieDateMenu();

/* POINTEURS */

int affichePoint();
int tabPoint();
int comparePoint();
int *alloueDate();

/* TABLEAUX BIS REPETITA */

float *allocTabFloat(int size);
allocTabFloatPrompt();


#endif // TP3_H_INCLUDED
