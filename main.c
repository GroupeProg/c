#include <stdio.h>
#include <stdlib.h>
#include "sources/pile.h"
#include "sources/file.h"
#include "sources/tp.h"
#include "sources/shaya.h"

int main(){

    Array a;
    a = empty_Array();
    append_int_array(&a, 9);
    append_int_array(&a, 8);
    append_int_array(&a, 8);
    append_int_array(&a, 5);
    append_int_array(&a, 8);
    append_int_array(&a, 8);
    append_int_array(&a, 6);
    append_int_array(&a, 8);
    append_int_array(&a, 8);
    afficher_array(a);
    free_array(&a);
    return 0;
    
}