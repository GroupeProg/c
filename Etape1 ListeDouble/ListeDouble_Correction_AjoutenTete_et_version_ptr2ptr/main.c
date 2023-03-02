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

    l=ajoutEnTete(l,10);
    l=ajoutEnTete(l,100);
    l=ajoutEnTete(l,1000);

    ajoutEnTetePtr2Ptr(&l, 20);
    ajoutEnTetePtr2Ptr(&l, 200);

    afficheListeV1(l);
    //à vous la suite

    return 0;
}
