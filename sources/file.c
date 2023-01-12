/**
 * Les fonctions enfiler et défiler ne fonctionnent pas vraiment
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

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 000b380ac528b5e0c6aa93eb222951f65bc71d16
T_file defiler(T_file file)
{
    if (file.tete == NULL)
    {
<<<<<<< HEAD
=======
T_file defiler(T_file file) {
    if (file.tete == NULL) {
>>>>>>> 3eb56bbe4ce1432f76cd03830cd7deeb036c701b
=======
>>>>>>> 000b380ac528b5e0c6aa93eb222951f65bc71d16
        printf("La file est vide\n");
        return file;
    }
    T_file *nouveau = (T_file *)malloc(sizeof(file));
    struct cellule *temp = file.tete;
    nouveau->tete = temp->suiv;
<<<<<<< HEAD
<<<<<<< HEAD
    if (nouveau->tete == NULL)
    {
=======
    if (nouveau->tete == NULL) {
>>>>>>> 3eb56bbe4ce1432f76cd03830cd7deeb036c701b
=======
    if (nouveau->tete == NULL)
    {
>>>>>>> 000b380ac528b5e0c6aa93eb222951f65bc71d16
        nouveau->queue = NULL;
    }
    free(temp);
    return *nouveau;
}

int main() {
    T_file a = creerFile();
    a = enfiler(a, 12);
    a = enfiler(a, 15);
    printf("%d", a.tete->elem);
    a = defiler(a);
    printf("%d", a.tete->elem);
}