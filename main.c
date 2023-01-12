#include <stdio.h>
#include "sources/pile.h"
#include "sources/file.h"

int main(int argc, char *argv[])
{
    T_pile a;
    T_file b;
    a = creerVide();
    for (int i = 1; i <= 50; i++) {
        a = empiler(a, i);
    }
    lenPile(a);
}

