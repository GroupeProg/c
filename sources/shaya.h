struct array
{
    int elem;
    int size;
};
typedef struct array Array;
Array empty_Array();
void append_int_array(Array *a, int e);
void afficher_array(Array a);
void free_array(Array *a);