#include <stdbool.h>

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdbool.h>
typedef struct tree *T_btree;

T_btree creer_arbre_vide();
T_btree creer_arbre(int val);
T_btree creer_arbre_test(int profondeur);
T_btree subleft(T_btree tree);
void afficher_arbre(T_btree tree);
int free_branch(T_btree tree);
void free_tree(T_btree tree);
void cut(T_btree tree, char l_or_r);
unsigned long long get_nbr_leaf(T_btree tree);
unsigned long long get_nbr_noeuds(T_btree tree);
bool isleaf(T_btree tree);
int test_tree();

#endif
