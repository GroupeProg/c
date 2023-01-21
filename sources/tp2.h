#include <stdlib.h>

void inversions(int *tab, size_t size);

//Fonctions
void ligne(int nbr);
float moyenne_3(int a, int b, int c);
int racine_polynome(int a, int b, int c);
void etudiant_matiere(int **tab, size_t n, size_t m);
int **tab_rand_double_dimensions(int number_max, int limite_elem_d1, int limite_elem_d2);
int **notetest(int nbr_eleve, int nbr_matiere);
void print_tab_double_dimension(int **tab, size_t d1, size_t d2);
void test_ultime_moyenne_etudiants();
void print_tab_with_size_float(float *tab, size_t size);
int *meilleureNoteMatiere(int **tab, size_t n, size_t m);
float *moyenneGeneraleEleve(int **tab, size_t n, size_t m);
float *moyenneGeneraleMatiere(int **tab, size_t n, size_t m);
float moyenne(int a, int b);
int facto(int n);
void facto_afficheur();
int fibonacci_tp2(int u0, int u1, int n);
void fibonacci_tp2_afficheur();