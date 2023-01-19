#include <stdio.h>
#include <stdlib.h>
#include "sources/pile.h"
#include "sources/file.h"
#include "sources/tp.h"
#include "sources/shaya.h"

int main(){

    T_file a;
    enfiler(&a, 6);
    enfiler(&a, 8);
    enfiler(&a, 9);
    afficher_tete_queue(a);
    defiler(&a);
    afficher_tete_queue(a);
    return 0;
    
}