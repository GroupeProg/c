#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "types.h"
#include "utils.h"



// Fonctions de comparaisons
//-------------------------------------------------------------------
bool comp_taille_AsupB ( T_personne a, T_personne b){
    return a.taille > b.taille;
};
//-------------------------------------------------------------------
bool comp_taille_AinfB ( T_personne a, T_personne b){
    return a.taille < b.taille;
};
//-------------------------------------------------------------------
bool comp_taille_AegaleB ( T_personne a, T_personne b){
    return a.taille == b.taille;
};
//-------------------------------------------------------------------
bool comp_masse_AsupB  ( T_personne a, T_personne b){
    return a.masse > b.masse;
};
//-------------------------------------------------------------------
bool comp_masse_AinfB ( T_personne a, T_personne b){
    return a.masse < b.masse;
};
//-------------------------------------------------------------------
bool comp_masse_AegaleB ( T_personne a, T_personne b){
    return a.masse == b.masse;
};
//-------------------------------------------------------------------






//Fonctions d'entrées/sorties
//-------------------------------------------------------------------
void print (T_personne p){
    printf("id:%d nom:\"%s\", taille: %dcm, masse: %2.1fkg, ne(e) le %2d/%2d/%4d \n",
           p.id, p.nom, p.taille, p.masse, p.jour, p.mois, p.annee );
};
//-------------------------------------------------------------------
void printTabPers (T_personne *tab, int taille){
    for (int i=0; i<taille; i++)
    {
        print(tab[i]);
    }
    return ;
};
//-------------------------------------------------------------------
void printTabPersRec (T_personne *tab, int taille){
    if (taille >0)
    {
        print(tab[0]);
        printTabPers (tab+1, taille-1);
    }
    return ;
};
//-------------------------------------------------------------------
T_personne getPers(int id)
{
    T_personne bob;

    fflush(stdin);  //vide la mémoire tampon du flux issu du clavier
    printf("\nDonnez un nom:\n");
    scanf("%s", bob.nom);

    printf("\nDonnez taille (cm), masse (kg) et date de naissance (jj/mm/aaaa):\n");
    scanf("%d %f %d/%d/%d",&(bob.taille), &(bob.masse), &bob.jour, &bob.mois, &bob.annee );

    bob.id=id;
    return bob;
};
//-------------------------------------------------------------------
void get(T_personne* bob, int id)  // nous disposons ici de l'adresse de la variable dans laquelle on doit écrire
{
    fflush(stdin);  //vide la mémoire tampon du flux issu du clavier
    printf("\nDonnez Nom Taille Masse Date de naissance (jj/mm/aaaa):\n");
    scanf("%s %d %f %d/%d/%d"
         ,bob->nom, &bob->taille, &bob->masse, &bob->jour, &bob->mois, &bob->annee );
    bob->id=id;
    return;
};
//-------------------------------------------------------------------


//Fonctions de génération auto
//-------------------------------------------------------------------
T_personne getPersAlea(int id)
{
    T_personne p;
    p.id = id;
    strcpy(p.nom, "i am a bot");
    p.taille = getRandInt(150,199);
    p.masse = getRandFloat(50.0,130.0);

    p.mois = getRandInt(1,12);
    p.annee = getRandInt(1900,2021);

    int bisextile = ((p.annee%4 ==0  && p.annee !=100) || (p.annee%400==0)) ? 1 : 0;
    p.jour = (p.mois==2) ? getRandInt(1,28 + bisextile )
            : (p.mois==4 || p.mois==6 || p.mois==4 || p.mois==9 || p.mois==11) ? 30:31;

    return p;
};
//-------------------------------------------------------------------
T_personne* getTabPersAlea(int taille)
{
    T_personne *tab = (T_personne*)malloc(taille*sizeof(T_personne));

    for (int i=0; i<taille; i++){
        tab[i]=getPersAlea(i);
    }
    return tab;
};
//-------------------------------------------------------------------
