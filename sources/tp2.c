#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp2.h"
#include "tp1.h"


void inversions(int *tab, size_t size) {
    //Déjà fait avec tri_tab dans TP1
    tri_tab(tab, size);
}

/**
 * 
 * 
 * Fonctions
 * 
 * 
*/

void ligne(int nbr) {
    for(int i = 0; i < nbr; i++){
        printf("*");
    }
    printf("\n");
}

float moyenne(int a, int b, int c){
    return (a+b+c)/3;
}

int racine_polynome(int a, int b, int c) {
    int delta = power(b, 2) - 4 * a * c;

    if(delta > 0) {
        printf("x1 = %f\nx2 = %f", (-b + sqrt((double)delta)) / (2 * a), (-b - sqrt((double)delta)) / (2 * a));
    }
    else if (delta = 0)
    {
        printf("x = %f", (-b)/(2*a));
    }
    else {
        printf(u8"La solution n'existe pas dans les reels.");
    }
    return delta;
}

void triBulles(int tab[], int taille){
    inversions(tab, (size_t)taille);
}

/**
 * 
 * Exemple :
 * Les sous-tableaux doivent avoir la même taille 
 * {{1, 2, 3, 4, 5, 6, 7, 8, 9}, }
 * 
 * Nous allons faire simple et estimer qu'il n'y a qu'une note par matière par étudiant, sinon il va nous falloir un tableau de 3 dimensions 
 * 
*/
// Etudiant & Matières
int tab_test[2][3] = {{1, 2, 3}, {4, 5, 6}}; //Dans cet exemple, il y a 2 élèves, et trois matières

int **tab_rand_double_dimensions(int number_max, int limite_elem_d1, int limite_elem_d2)
{
    size_t size = limite_elem_d2 * limite_elem_d1 * sizeof(int *);
    int **tab = malloc(size);
    srand(time_time());
    for (int i = 0; i < limite_elem_d1; i++)
    {
        tab[i] = malloc(limite_elem_d2 * sizeof(int **));
        for(int j = 0; j < limite_elem_d2; j++) {
            tab[i][j] = rand() % number_max;
        }
        
    }
    
    return tab;
}

void print_tab_double_dimension(int **tab, size_t d1, size_t d2) {
    for(int i = 0; i < d1; i++){
        print_tab_with_size(tab[i], d2);
        printf("\n");
    }
}

/**
 * Renvoi un tableau de dimension (7, 25)
*/
int **notetest(int nbr_eleve, int nbr_matiere) {
    return (int **)tab_rand_double_dimensions(20, nbr_eleve, nbr_matiere);
}

/**
 * Nous allons faire simple et estimer qu'il n'y a qu'une note par matière par étudiant, sinon il va nous falloir un tableau de 3 dimensions
 * 
 * 3 fonctions vont être utiles
 * Trier et prendre la meilleure avec tri_tab de tp1.h
 * Fonction moyenne_tab de tp1.h
 * Ainsi qu'une nouvelle
 *
 * n le nombres d'élèves
 * m le nombre de matières
 * 20 sera la note maximale disponible
 */

float *moyenneGeneraleMatiere(int **tab, size_t n, size_t m) {
    float *moy_mat = malloc(sizeof(float*) * m);
    
}

void moyenneParMatiere(int **tab, size_t n, size_t m)
{   

    for(int i = 0; i < n; i++) {
        tri_tab(tab[i], m);
    }
    
}

/**
 * Pas de réflexion, on lance et tout est fait pour nous l'afficher
*/
void testultime_moyenne_etudiants() {
    int nbr_eleve = 20;
    int nbr_matiere = 10;
    int **enotes = notetest(nbr_eleve, nbr_matiere);
    print_tab_double_dimension(enotes, nbr_eleve, nbr_matiere);
    moyenneParMatiere(enotes, nbr_eleve, nbr_matiere);
}
