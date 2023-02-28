#include <stdio.h>
#include <stdlib.h>

#include "listeDouble.h"


//initListe ne fait pas de malloc, juste une initialisation à NULL du pointeur de liste
void initListe(T_liste *l){
*l=NULL;
}

//fonction qui dit si la liste est vide
bool listeVide( T_liste l){
    return (l==NULL);
};

//affiche la liste passée en parametre
void afficheListeV1( T_liste l){
    T_liste p = l;
    while (p!=NULL){
        printf(" %d ", *(p->pdata));
        p=p->suiv;
    }
}

//ajoute une valeur passee en parametre au debut de la liste
T_liste ajoutEnTete(T_liste l, int mydata){
    T_liste nouveau=(T_liste)malloc(sizeof(struct T_cell));
    nouveau->pdata=(int *)malloc(sizeof(int));
    *(nouveau->pdata)=mydata;

    if (l==NULL)
    {
        nouveau->suiv=NULL;
        nouveau->prec=NULL;
    }
    else
    {
        nouveau->prec=NULL;
        nouveau->suiv=l;
        l->prec=nouveau;
    }
    return nouveau;
}

//ajoute une valeur passe en parametre a la fin de la liste
T_liste ajoutEnFin(T_liste l, int mydata){
    T_liste res=l;
    T_liste nouv=(T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata=(int *)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    if(res==NULL)
    {
        nouv->suiv=NULL;
        nouv->prec=NULL;
    }
    else
    {
        nouv->suiv=NULL;
        while(res->suiv!=NULL)
        {
            res=res->suiv;
        }
        nouv->prec=res;
        res->suiv=nouv;
    }
    return l;
}

//ajoute une valeur a la place N dans la liste
//si cette place est (<=1) alors ajout a la première place
//si la valeur est supérieure à la longueur de la liste alors ajout à la fin
T_liste ajoutEnN(T_liste l, int pos, int mydata){
    T_liste liste=l;
    T_liste nouv=(T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata=(int *)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    if(liste==NULL)
    {
        nouv->suiv=NULL;
        nouv->prec=NULL;
    }
    else if(pos<=1)
    {
        l=ajoutEnTete(liste, mydata);
    }
    else
    {
      for(int i=2; i<pos; i++){
            liste=liste->suiv;
            if((liste->suiv)==NULL)
            {
                break;
            }
      }
      if((liste->suiv)==NULL)
        {
            ajoutEnFin(liste, mydata);
        }
      else{
      nouv->suiv=(liste->suiv);
      nouv->prec=liste;
      T_liste fin=(liste->suiv);
      liste->suiv=nouv;
      fin->prec=nouv;
      }
    }
    return l;
}

//supprime la premiere valeur de la liste
T_liste suppEnTete(T_liste l){
    T_liste res=l->suiv;
    res->prec=NULL;
    return res;
}

//supprime la derniere valeur de la liste
T_liste suppEnFin(T_liste l){
    T_liste res=l;
    while(res->suiv!=NULL){
        res=res->suiv;
    }
    res=res->prec;
    T_liste l2=(res->suiv);
    res->suiv=NULL;
    l2->prec=NULL;
    return l;
}

//supprime la valeur en position N sur la liste
//si la position selectionnee est (<=1) supprime la premiere valeur
//si la position est supperieure a la longueur de la liste, supprime la derniere valeur.
T_liste suppEnN(T_liste l, int pos){
    T_liste res=l;
    if(pos<=1)
    {
        l=suppEnTete(l);
    }
    else
    {
        for(int i=2; i<=pos; i++){
            res=res->suiv;
            if((res->suiv)==NULL){
                break;
            }
        }
        if((res->suiv)==NULL){
            l=suppEnFin(l);
        }
        else
        {
            T_liste suite=(res->suiv);
            T_liste precedent=(res->prec);
            suite->prec=precedent;
            precedent->suiv=suite;
        }
    }
    return l;
}

T_liste getptrFirstCell(T_liste l){
    T_liste *ptr=
}
