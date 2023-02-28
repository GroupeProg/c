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
    afficheListeV1(l);

    printf("\nListe apres ajouts en tete : ");
    l=ajoutEnTete(l, 4);
    l=ajoutEnTete(l, 2);
    l=ajoutEnTete(l, 1);
    afficheListeV1(l);

    printf("\n\nListe apres ajout en fin : ");
    l=ajoutEnFin(l, 5);
    afficheListeV1(l);

    printf("\n\nListe apres ajout en N : ");
    l=ajoutEnN(l, 3, 3);
    afficheListeV1(l);

    printf("\n\nListe apres suppression en tete : ");
    l=suppEnTete(l);
    afficheListeV1(l);

    printf("\n\nListe apres suppression a la fin : ");
    l=suppEnFin(l);
    afficheListeV1(l);

    l=ajoutEnTete(l, 4);
    l=ajoutEnTete(l, 2);
    l=ajoutEnTete(l, 1);
    printf("\n");
    afficheListeV1(l);

    printf("\n\nListe apres suppression en N : ");
    l=suppEnN(l, 6);
    afficheListeV1(l);

    //à vous la suite

    return 0;
}
