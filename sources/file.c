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

typedef struct {
    struct cellule *tete;
    struct cellule *queue;
}T_file;


/**
 * Fonction qui renvoi un T_file vide
 */
T_file creerFile(void) {
    T_file file;
    file.tete = file.queue = NULL;
    return file;
}

/**
 * Enfile un élément sans en créer un nouveau.
 * Rappelons que c'est la tête qui pointe la suivante
 * 
 * Quand nous ajoutons un élément, nous poussons NULL vers le dernier de la queue,
 * la tête pointe vers le second et quand nous ajoutons un élément, l'ancien dernier éleément de la queue pointe vers le nouveau avant que ce nouveau ne devinne le dernier de la queue.
 * 
 * Dans le cas particulier où la file est vide, le dernier de la queue est aussi la tête
 */
void enfiler(T_file *file, int elem) {
    struct cellule *cell = malloc(sizeof(struct cellule));

    cell->suiv = NULL;
    cell->elem = elem;

    if ((*file).tete == NULL)
    {
        file->tete = cell;
        file->queue = cell; // cas particulier où la file est vide
    }
    else {
        file->queue->suiv = cell; // Le suivant de l'ancien dernier de la queue pointe vers cell
        file->queue = cell; // cell devient le dernier de la queue
    }
}

/**
 * Pour défiler, la fonction s'occuper de récupérer 
 */
void defiler(T_file *file)
{
    if (file->queue != NULL)
    {
        struct cellule *cell = file->tete->suiv;  // Récupération du second après la tête
        free(file->tete); // On libère la mémoire de l'ancienne tête
        file->tete = cell; // Le second devient premier
    }
}

/**
 * Afficher l'élément de la queue
 */
void afficher_queue(T_file file) {
    struct cellule *cell = file.queue;
    printf("QUEUE : %d\n", cell->elem);
}

/**
 * Afficher l'élément de la tete
 */
void afficher_tete(T_file file) {
    struct cellule *cell = file.tete;
    printf("TETE : %d\n", cell->elem);
}

/**
 * Afficher l'élément de la tete et l'élément de la queue
 */
void afficher_tete_queue(T_file file) {
    struct cellule *tete = file.tete;
    struct cellule *queue = file.queue;
    printf("TETE : %d <> QUEUE : %d\n", tete->elem, queue->elem);
}