#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Comparé à Ocaml ou Python, on ne peut pas faire des inclusion dans des inclusions, pour cela, on pointe vers une case
 */
struct tree
{
    int elem;
    struct tree *subleft;
    struct tree *subright;
};

typedef struct tree *T_btree; // Pourquoi *T_btree au lieu de T_btree, car les branche de tree (subleft et subright) sont des pointeurs. On pourra travailler avec malloc aussi

/**
 * La taille classique d'un T_btree ne suffisait pas, par précaution donc, une taille d'un seul b_tree équivaut à celui de trois pour supporter celui des autres
*/
T_btree creer_arbre_vide() {
    T_btree tree = malloc(3*sizeof(T_btree));
    tree->elem = (int)NULL;
    tree->subleft = NULL;
    tree->subright = NULL;

    return tree;
}

/**
 * Permet de créer un arbre vide avec une valeur initiale
*/
T_btree creer_arbre(int val)
{
    T_btree tree = malloc(3*sizeof(T_btree));
    tree->elem = val;
    tree->subleft = NULL;
    tree->subright = NULL;

    return tree;
}

/**
 * Permet de creer un arbre à n profondeur. Les valeur des arbres est simpl et indique quelle est la profondeur restante. Si la valeur vaut 0, alors c'est une feuille.
*/
T_btree creer_arbre_test(int profondeur) {

    if(profondeur != 0){
        T_btree tree = malloc(3*sizeof(T_btree));;
        int elem = profondeur;
        tree->elem = elem;
        tree->subleft = creer_arbre_test(profondeur-1);
        tree->subright = creer_arbre_test(profondeur-1);
        return tree;
    }
    else {
        return creer_arbre(0);
    }
}

/**
 * Renvoi le sous-arbre de gauche
*/
T_btree subleft(T_btree tree)
{
    return tree->subleft;
}


/**
 * Renvoi le sous-arbre de droite
*/
T_btree subright(T_btree tree)
{
    return tree->subright;
}

/**
 * Affiche sommairement les valeurs à la suite des autres
*/
void afficher_arbre(T_btree tree) {
    if(tree != NULL) {
        printf("%d, ", tree->elem);
        afficher_arbre(tree->subleft);
        afficher_arbre(tree->subright);
    }
}

/**
 * Libère la mémoire d'une des branches 
*/
int free_branch(T_btree tree) {

    //free subleft
    if(tree->subleft != NULL) {
        int result = free_branch(tree->subleft);
        if(result == 0) {
            free(tree->subleft);
        }
        return 0;
    }
    else {
        return 0;
    }

    //free subright
    if (tree->subright != NULL) {
        int result = free_branch(tree->subright);
        if (result == 0) {
            free(tree->subright);
        }
        return 0;
    }
    else {
        return 0;
    }
}

/**
 * Libère tout l'arbre
*/
void free_tree(T_btree tree) {
    free_branch(tree);
}


/**
 * Sépare une branche de l'arbre en libérant la mémoire en même temps.
*/
void cut(T_btree tree, char l_or_r) {
    if(l_or_r == 'l') {
        free_branch(tree->subleft);
        tree->subleft = NULL;
    }
    else if (l_or_r == 'r')
    {
        free_branch(tree->subright);
        tree->subright = NULL;
    }
    else if (l_or_r == 'a')
    {
        free_branch(tree);
        tree = NULL;
    }
};

bool isleaf(T_btree tree) {
    if(tree->subleft == NULL && tree->subright == NULL) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * Donne le nombre de noeuds total, feuille 
*/
unsigned long long get_nbr_noeuds(T_btree tree)
{
    unsigned long nbr = 0;

    if(isleaf(tree) == false){
        nbr += 1;
        if (tree->subleft != NULL) {
            nbr += get_nbr_noeuds(tree->subleft);
        }
        if (tree->subright != NULL) {
            nbr += get_nbr_noeuds(tree->subright);
        }
        return nbr;
    }
    else {
        return 0;
    }
}

/**
 * Donne le nombre de feuille
*/
unsigned long long get_nbr_leaf(T_btree tree) {
    unsigned long nbr = 0;
    if(isleaf(tree)) {
        nbr++;
        return nbr;
    }
    else {
        nbr += get_nbr_leaf(tree->subleft);
        nbr += get_nbr_leaf(tree->subright);
        return nbr;
    }
}

int test_tree()
{
    T_btree tree = creer_arbre_test(4);
    unsigned long long nbr = get_nbr_noeuds(tree);
    printf("\n----\n%d", nbr);
    nbr = get_nbr_leaf(tree);
    printf("\n----\n%d", nbr);
    afficher_arbre(tree);
    return 0;
}
