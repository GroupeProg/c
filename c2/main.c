#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listeDouble.h"

int main()
{
    T_liste l;
    printf("Zone de test de vos fonctions!\n");
    printf("1 fonction = 1 test immediat!\n");

    //tests
    initListe(&l);
    if (listeVide(l)) printf("la liste est vide\n");

    l = ajoutEnTete(l, 65);
    l = ajoutEnTete(l, 12);
    l = ajoutEnFin(l, 23);

    afficheListeV1(l);

    return 0;
}
