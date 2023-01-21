#include <stdio.h>
#include <stdlib.h>
#include "sources/pile.h"
#include "sources/file.h"
#include "sources/tp1.h"
#include "sources/shaya.h"
#include "sources/tree.h"


int main(){
    int limite = 20;
    int *tab = tab_rand_without_print_limited(limite);
    print_tab_with_size(tab, limite);
    printf("\n");
    tri_tab(tab, limite);
    print_tab_with_size(tab, limite);
    return 0;
}