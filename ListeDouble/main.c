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

    //printf("\nListe apres ajouts en tete : ");
    l=ajoutEnTete(l, 4);
    l=ajoutEnTete(l, 2);
    l=ajoutEnTete(l, 1);
    //afficheListeV1(l);

    printf("\n\nListe apres ajout en fin : ");
    l=ajoutEnFin(l, 5);
    afficheListeV1(l);

    //printf("\n\nListe apres ajout en N : ");
    l=ajoutEnN(l, 3, 3);
    //afficheListeV1(l);

    //printf("\n\nListe apres suppression en tete : ");
    l=suppEnTete(l);
    //afficheListeV1(l);

    //printf("\n\nListe apres suppression a la fin : ");
    l=suppEnFin(l);
    //afficheListeV1(l);

    l=ajoutEnTete(l, 4);
    l=ajoutEnTete(l, 2);
    l=ajoutEnTete(l, 1);
    //printf("\n");
    //afficheListeV1(l);

    //printf("\n\nListe apres suppression en N : ");
    l=suppEnN(l, 6);
    //afficheListeV1(l);

    //printf("\n\nPointeur sur le debut de la liste");
    T_cellule *ptr;
    ptr=getptrFirstCell(l);
    ptr=l->suiv;
    //printf("\nValeur du pointeur apres decalage : ");
    //afficheListeV1(ptr);
    //printf("\nValeur de l pour comparer : ");
    //afficheListeV1(l);

    //printf("\n\nPointeur de la derniere case : ");
    ptr=getptrLastCell(l);
    //afficheListeV1(ptr);

    printf("\n\nPointeur cellule suivante : ");
    ptr=getptrNextCell(l);
    afficheListeV1(ptr);
    printf("\n");
    ptr=getptrNextCell(ptr);
    afficheListeV1(ptr);

    printf("\n\nPointeur de la cellule precedante de la liste : ");
    ptr=getptrPrevCell(ptr);
    afficheListeV1(ptr);

    printf("\n\nPointeur sur pdata : ");
    int *p=getPtrData(l);
    printf("\nValeur pointee par p : %d ", *p);
    printf("\nModif de pdata grace au pointeur : ");
    *p=6;
    afficheListeV1(l);

    printf("\n\nSwap data : \n");
    swapPtrData(l, l->suiv);
    afficheListeV1(l);
    printf("\nNomre de cellules : %d",getNbreCell(l));
    printf("\nNombre d'octets de la liste : %d",getSizeBytes(l));

    printf("\n\nNouvelle liste fusion : ");
    printf("\nListe 1 : ");
    afficheListeV1(l);
    printf("\nListe 2 : ");
    afficheListeV1(ptr);
    T_liste nouv;
    initListe(&nouv);
    printf("\nNouvelle liste : ");
    ptr=getptrNextCell(ptr);
    nouv=creatNewListeFromFusion(l, ptr);
    afficheListeV1(nouv);
    printf("\naddbehind : ");
    nouv=addBehind(nouv, ptr);
    afficheListeV1(nouv);
    printf("\nTrouver valeur dans une liste: ");
    nouv=findCell(nouv, 3);
    afficheListeV1(nouv);

    //à vous la suite

    return 0;
}
