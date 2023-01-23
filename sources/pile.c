#include <stdlib.h>
#include <stdio.h>

/**
 * La cellule est l'emplacement unique d'un élément integer
*/
struct cellule
{
    int elem;
    struct cellule *suiv;
};

typedef struct cellule *T_pile;

/**
 * Permet de créer une pile vide
*/
T_pile creerVide()
{
    T_pile p = NULL;
    return p;
}

/**
 * Permet d'empiler des cellules entre elles en pointant vers la cellule dite suivante
 * Utilisation de malloc pour garder en vie la nouvelle pile
*/
T_pile empiler(T_pile p, int val)
{
    T_pile newcase = (T_pile)malloc(sizeof(struct cellule));
    if (newcase == NULL)
    {
        fprintf(stderr, "Memoire insuffisante\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        newcase->elem = val;
        newcase->suiv = p;
        return newcase;
    }
}

/**
 * Permet de dépiler, de reprendre la cellule suivante en cellule tête et supprimer l'ancienne cellule tête de la mémoire
 * La méthode s'occupe de garder p et de créer une nouvelle T_pile qui sera égale à pile->suivant, ainsi que de la renvoyer
*/
T_pile depiler(T_pile p)
{
    if (p == NULL)
    {
        fprintf(stderr, "Vide\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        T_pile newcase = (T_pile)malloc(sizeof(struct cellule));
        T_pile suivant = p->suiv;
        newcase->suiv = suivant->suiv;
        newcase->elem = suivant->elem;
        free(p);
        free(suivant);
        return newcase;
    }
}

/**
 * Affiche les éléments de la pile avec printf en parcourant l'arborescence de la pile
*/
void afficherPile(T_pile p)
{
    if (p == NULL)
    {
        fprintf(stderr, "Vide\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        T_pile actuel = p;
        printf("[");
        while (actuel != NULL)
        {

            printf("%d", actuel->elem);
            actuel = actuel->suiv;
            if(actuel != NULL) {
                printf(", ");
            }
        }
        printf("]");
    }
}

/**
 * Renvoie la taille de la pile.
*/
int lenPile(T_pile p)
{
    if (p == NULL)
    {
        return 0;
    }
    else 
    {
    int c = 1;
    T_pile exit = p;
    
        while ( exit->suiv != NULL)
        {
            exit = depiler(exit);
            c += 1;
        }
        return c;
    }
}