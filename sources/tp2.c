#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include "tp2.h"
#include "tp1.h"

// Tri un tableau
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

// Imprime une somme de n fois étoiles sur un ligne.
void ligne(int nbr) {
    for(int i = 0; i < nbr; i++){
        printf("*");
    }
    printf("\n");
}

// Renvoie la moyenne de trois nombres.
float moyenne_3(int a, int b, int c){
    return (a+b+c)/3;
}

// Cette fonction permet de calculer le discriminant, afficher les racines et renvoi le delta (discriminant).
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

// Fais un trie bulle, déjà fait dans inversion, lui même déjà fait au TP1.
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

/**
 * Renvoie un tableau de deux dimensions avec des nombres aléatoires, avec trois paramètres :
 *  - number_max -> C'est le chiffre max random
 *  - limite_elem_d1 -> Définit la première dimension
 *  - limite_elem_d2 -> Définit la deuxième dimension
 */
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

// Permet d'afficher un tableau de deux dimensions
void print_tab_double_dimension(int **tab, size_t d1, size_t d2) {
    for(int i = 0; i < d1; i++){
        print_tab_with_size(tab[i], d2);
        printf("\n");
    }
}

/**
 * Renvoi un tableau de dimension (éléves, matières)
*/
int **notetest(int nbr_eleve, int nbr_matiere) {
    return (int **)tab_rand_double_dimensions(20, nbr_eleve, nbr_matiere);
}

// Permet de faire simplement une moyenne depuis des chiffres int.
float moyenne(int a, int b) {
    return (float)a/(float)b;
}

// Renvoie un tableau de une dimension avec la moyonne totales des notes par matières.
float *moyenneGeneraleMatiere(int **tab, size_t n, size_t m) {
    float *moy_mat = malloc(sizeof(float*) * m* n);
    for(int i = 0; i < m; i++) { // Attention, ici on selectionne en premier la matière
        float moye = 0.0;
        int somme = 0;
        for(int j = 0; j < n; j++) { // Par nombre d'élèves

            somme += tab[j][i];
        }
        moye = moyenne(somme, n);
        moy_mat[i] = moye;
    }
    return moy_mat;
}

// Renvoie un tableau de une dimension avec la moyonne totales des notes par élèves.
float *moyenneGeneraleEleve(int **tab, size_t n, size_t m){
    float *moy_ge = malloc(sizeof(float *) * m * n);
    for (int i = 0; i < n; i++)
    { // Attention, ici on selectionne en premier la matière
        float moye = 0.0;
        int somme = 0;
        for (int j = 0; j < m; j++)
        { // Par nombre d'élèves

            somme += tab[i][j];
        }
        moye = moyenne(somme, m);
        moy_ge[i] = moye;
    }
    return moy_ge;
}

// Renvoie un tableau de une dimension avec la meilleure note par matières.
int *meilleureNoteMatiere(int **tab, size_t n, size_t m) {

    int *m_mat = malloc(sizeof(int *) * m * n);
    for (int i = 0; i < m; i++)
    { // Attention, ici on selectionne en premier la matière
        int best = 0;
        int note = 0;
        for (int j = 0; j < n; j++)
        { // Par nombre d'élèves

            note = tab[j][i];
            if(note > best) {
                best = note;
            }
        }
        m_mat[i] = best;
    }
    return m_mat;
}

// Imprime un tableau de flottant à 'size' de taille.
void print_tab_with_size_float(float *tab, size_t size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%f", tab[i]);
    }
    printf("]");
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
void etudiant_matiere(int **tab, size_t n, size_t m)
{
    // 1. Les notes moyennes des matières

    float *moyenne = moyenneGeneraleMatiere(tab, n, m);
    printf("Moyenne Generale par Matiere : ");
    print_tab_with_size_float(moyenne, m);
    printf("\n");

    // 2. Les moyennes générales des étudiants

    float *moyenne_eleve = moyenneGeneraleEleve(tab, n, m);
    printf("Moyenne Generale par Eleve : ");
    print_tab_with_size_float(moyenne_eleve, n);
    printf("\n");

    // 3. La meilleure note d'une matière

    int *bests_notes = meilleureNoteMatiere(tab, n, m);
    printf("Meilleure Note par Matiere : ");
    print_tab_with_size(bests_notes, n);
    printf("\n");

    // La meilleure note tout confondu (meilleure note des élèves dans une matière , afficher matière, élève, et la note)
    // -> Un peu la flemme

}

/**
 * Pas de réflexion, on lance et tout est fait pour nous afficher dans un exemple concret sans nous même renseigner quoi que ce soit la question demandée pour :
 * - Notes par élèves
 * - Moyenne de l'élève
 * - Moyenne de la matière
 * - Meilleure note par matière
 * - Meilleure note tout court avec l'élève et sa matière dans lequel il a reçu la meilleure note.
*/
void test_ultime_moyenne_etudiants() {
    int nbr_eleve = 2;
    int nbr_matiere = 3;
    int **enotes = notetest(nbr_eleve, nbr_matiere);
    print_tab_double_dimension(enotes, nbr_eleve, nbr_matiere);
    etudiant_matiere(enotes, nbr_eleve, nbr_matiere);
}


/**
 * 
 * Fonctions Réccurcives
 * 
*/

// Permet de faire un factoriel en récurcif avec en paramètre n.
int facto(int n) {
    if(n > 0){
        return n * facto(n-1);
    }
    else{
        return 1;
    }
}

// Interface pour renseigner à l'écran n.
void facto_afficheur()
{   
    int n;
    printf("Cette fonction va donner un factoriel d'un nombre n.\nNombre n : ");
    scanf("%d", &n);
    int f = facto(n);
    printf("\nCe qui donne : %d", f);
}

/**
 * Permet de faire la suite de fibonacci avec trois paramères :
 * - u0
 * - u1
 * - n qui est la limite de la suite.
 */

int fibonacci_tp2(int u0, int u1, int n)
{
    __int64 u2 = 0;
    if(n > 0) {
        int i = 1;
        u2 = u1 + u0;
        u1 = u2;
        u0 = u1;
        return fibonacci_tp2(u0, u1, n-1);
    } else {
        return u1;
    }
}


// Interface pour que l'utilisateur renseigne u0, u1 et n (limite de al suite de fibonacci).
void fibonacci_tp2_afficheur() {
    int u0, u1, n = 0;
    printf("Nombre pour U0 : ");
    scanf("%lu", &u0);
    printf("\nNombre pour U1 : ");
    scanf("%lu", &u1);
    printf("\nNombre pour n : ");
    scanf("%lu", &n);
    int fib = fibonacci_tp2(u0, u1, n);
    printf("FIBO : %d\n", fib);
}