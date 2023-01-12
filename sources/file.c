/**
 * La fonction enfiler fonctionne, mais pas la fonction défiler
*/

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

T_file creerFile(void) {
    T_file file;
    file.tete = file.queue = NULL;
    return file;
}

//fait une fonction pour enfiler un élément dans une file
T_file enfiler(T_file file, int elem){
    T_file *nouveau = (T_file *)malloc(sizeof(file));
    struct cellule *cell = (struct cellule *)malloc(sizeof(struct cellule));
    cell->elem = elem;
    if(file.queue == NULL){
        cell->suiv = NULL;
        nouveau->tete = cell;
    }
    else{
        cell->suiv = file.queue;
    }
    nouveau->tete = cell;
    return *nouveau;
}

T_file defiler(T_file file){
    T_file *nouveau;
    if (file.queue == NULL)
    {
        fprintf(stderr, "Impossible de defiler une file vide");
        exit(EXIT_FAILURE);
    }
    else
    {
        nouveau = (T_file *)malloc(sizeof(file));
        if(file.tete == file.queue){
            (*nouveau).tete = NULL;
            (*nouveau).queue = NULL;
        }
        (*nouveau).tete = file.queue->suiv;
        free(file.queue);
    }
    return *nouveau;
}