/**
 * Un fichier pour comprendre comment fonctionne le malloc, J'AI ENFIN COMPRIS ! 
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include "shaya.h"

T_Array init_Array(int taille)
{
    T_Array a;
    a.elem = (int *)malloc(sizeof(int) * taille);
    a.size = 0;
    return a;
}

void afficher_array(T_Array a) {
    printf("[");
    for(int i = 0; i <= a.size - 1; i++) {
        printf("%d", a.elem[i]);
        if (i != a.size-1) {
            printf(", ");
        }
    }
    printf("]");
}

void append_int_array(T_Array *a, int e)
{
    // ici on va pointer vers le pointeur T_Array en prio
    (*a).size += 1;
    int *temp = (int *)malloc((*a).size * sizeof(int));
    if ((*a).size-1!=0) {
        for (int i = 0; i < (*a).size; i++) {
            temp[i] = (*a).elem[i];
        }
        temp = (*a).elem = temp;
        temp[(*a).size - 1] = e;
        (*a).elem = temp;
    }
    else {
        (*a).elem[0] = e;
    }
}

void free_array(T_Array *a) {
    free((*a).elem);
}