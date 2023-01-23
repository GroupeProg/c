#ifndef SHAYA_H_INCLUDED
#define SHAYA_H_INCLUDED


typedef struct
{
    int *elem;
    int size;
} T_Array;

T_Array init_Array(int taille);
void append_int_array(T_Array *a, int e);
void afficher_array(T_Array a);
void free_array(T_Array *a);

#endif
