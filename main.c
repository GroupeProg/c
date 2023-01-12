#include <stdio.h>
#include "pile.h"

int main(int argc, char *argv[])
{
    T_pile a;
    a = creerVide();
    for (int i = 1; i <= 50; i++) {
        a = empiler(a, i);
    }

    afficherPile(a);
}