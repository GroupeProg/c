#include <stdlib.h>

//Première commandes
int quisuisje(void);
int permute(void);
int year(void);
int division(void);

// Structures de controles
int multi_aux(int a, int b);
int multi(void);
int pyramide(void);
int factoriel(void);
int sum(void);
int longue_cons(void);
int nombre_parfait(void);
int fibonacci(void);

//tableaux
int tableau(void);
int tableau_paire(void);
int random(void);
int randint(int min, int max);
int time_time(void);
int *tab_rand(void);
int *tab_rand_without_print(void);
int *tab_rand_without_print_limited(int limite);
int *tab_rand_without_print_double_limited(int limite_int, int limite_elem);
float moyenne_tab(void);
int *sep_pos_neg(void);
int power(int a, int b);
int int_to_bin(int nbr);
void print_tab(int *tab);
void print_tab_with_size(int *tab, size_t size);
void print_tab_bin_loop(int limite, int milliseconds);
void tri_tab(int *tab, size_t size);

//chaînes de caractères
void stringcmp(void);
void stringcopy(void);
char *stringcatenation(void);
void str_print(char *str);
void printc(void);
void triangle_word(char *mot, int nbr);
char *str_upside_down(char *str);
int palindrome(char *str);