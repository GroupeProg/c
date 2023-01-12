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

T_file defiler(T_file file)
{
    if (file.tete == NULL)
    {
        printf("La file est vide\n");
        return file;
    }
    T_file *nouveau = (T_file *)malloc(sizeof(file));
    struct cellule *temp = file.tete;
    nouveau->tete = temp->suiv;
    if (nouveau->tete == NULL)
    {
        nouveau->queue = NULL;
    }
    free(temp);
    return *nouveau;
}

int main() {
    T_file a = creerFile();
    a = enfiler(a, 12);
}