#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//dans cette version "l" est un pointeur sur le pointeur de la 1ere cellule.
void ajoutEnTetePtr2Ptr(T_liste *l, int mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    //struct T_cell * nouv = (struct T_cell *)malloc(sizeof(struct T_cell))  //equivalent
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    if (*l==NULL) // on cree en fait la premiere cellule de la liste
    {
        nouv->suiv = NULL;
        nouv->prec = NULL;
    }
    else  // la lste n'etait pas vide, on doit donc faire les branchements
    {
        nouv->suiv = *l;
        nouv->prec = NULL;
        (*l)->prec = nouv;
    }
    //on modifie l'adresse de la t�te de la liste, soit le contenu point� par l
    *l=nouv;
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
    if(l==NULL)
    {
        l=(T_liste)malloc(sizeof(struct T_cell));
        l->pdata=(int *)malloc(sizeof(int));
        l->prec=NULL;
        l->suiv=NULL;
        *(l->pdata)=mydata;
    }
    else
    {
        T_liste res=l;
        T_liste nouv=(T_liste)malloc(sizeof(struct T_cell));
        nouv->pdata=(int *)malloc(sizeof(int));
        *(nouv->pdata)=mydata;
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

    if(l==NULL)
    {
        l=(T_liste)malloc(sizeof(struct T_cell));
        l->pdata=(int *)malloc(sizeof(int));
        l->prec=NULL;
        l->suiv=NULL;
        *(l->pdata)=mydata;
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
    T_liste res;
    initListe(&res);
    res=l->suiv;
    res->prec=NULL;
    free(l->pdata);
    free(l);
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
    free(l2->pdata);
    free(l2);
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
            free(res->pdata);
            free(res);
            suite->prec=precedent;
            precedent->suiv=suite;
        }
    }
    return l;
}

//renvoie un pointeur sur la premiere cellule de la liste
T_liste getptrFirstCell(T_liste l){
    T_cellule *ptr;
    if(l==NULL){
        ptr=NULL;
    }
    else
    {
        ptr=l;
    }
    return ptr;
}

//renvoie un pointeur sur la derniere cellule de la liste
T_liste getptrLastCell(T_liste l){
    T_cellule *ptr;
    if(l==NULL){
        ptr=NULL;
    }
    else
    {
        while((l->suiv)!=NULL){
                l=l->suiv;
        }
        ptr=l;
    }
    return ptr;
}

//renvoie un pointeur sur la cellule suivante de la liste
T_liste getptrNextCell(T_liste l){
    T_cellule *ptr;
    if(l==NULL){
        ptr=NULL;
    }
    else
    {
        l=l->suiv;
        ptr=l;
    }
    return ptr;
}

//renvoie un pointeur sur la cellule precedente de la liste
T_liste getptrPrevCell(T_liste l){
    if(l==NULL){
        return NULL;
    }
    else
    {
        return l->prec;
    }
}

//renvoie un pointeur sur la valeur contenu dans le champ pdata
int* getPtrData(T_liste l){
    if(l==NULL){
        return NULL;
    }
    else
    {
        return l->pdata;
    }
}

//echange les valeurs de deux champs pdata
void swapPtrData( T_liste source, T_liste destination ){
    int *p1=getPtrData(source), *p2=getPtrData(destination);
    printf("pointeur 1 : %d, pointeur 2 : %d", *p1, *p2);
    int tmp = *p1;
    *p1=*p2;
    *p2=tmp;
    printf("\npointeur 1 : %d, pointeur 2 : %d \n", *p1, *p2);
}

//donne le nombre de cellules de la liste
int getNbreCell(T_liste l){
    int res=0;
    while(l!=NULL){
        l=l->suiv;
        res=res+1;
    }
    return res;
}

//renvoie la taille en bits d'une liste
int getSizeBytes(T_liste l){
    int len=getNbreCell(l);
    int res=len*sizeof(struct T_cell);
    return res;
}

//renvoie une nouvelle liste cree a partir de deux liste mise l'une derriere l'autre;
//les liste d'origine ne sont pas modifiees
T_liste creatNewListeFromFusion(T_liste l1, T_liste l2){
    T_liste res;
    initListe(&res);
    int len=getNbreCell(l1);
    T_cellule *p=getptrFirstCell(l1);
    int *ptr=getPtrData(p);
    for(int i=0; i<len; i++){
        res=ajoutEnFin(res,*ptr);
        p=getptrNextCell(p);
        ptr=getPtrData(p);
    }
    len=getNbreCell(l2);
    p=getptrFirstCell(l2);
    ptr=getPtrData(p);
    for(int i=0; i<len; i++){
        res=ajoutEnFin(res,*ptr);
        p=getptrNextCell(p);
        ptr=getPtrData(p);
    }
    return res;
}

//renvoie la premiere liste avec la deuxieme liste rajoutee a la premiere
T_liste addBehind(T_liste debut, T_liste suite){
    T_cellule *ptr=getptrLastCell(debut);
    ptr->suiv=suite;
    suite->prec=ptr;
    return debut;
}

//trouve la premiere cellule qui contient la valeur data dans son champ pdata
T_liste findCell(T_liste l, int data){
    T_cellule *ptr=l;
    T_liste res=NULL;
    int *p=getPtrData(ptr);
    while(*p!=data && ptr->suiv!=NULL){
        ptr=getptrNextCell(ptr);
        p=getPtrData(ptr);
    }
    if(*p==data){
        res=ptr;
    }
    else printf("valeur pas dans la liste");
    return res;
}

//renvoie le nombre de fois que data est present dans la liste
int getOccurences(T_liste l, int data){
    T_cellule *ptr=getptrFirstCell(l);
    int *p=getPtrData(ptr);
    int res=0;
    int len=getNbreCell(ptr);
    for(int i=0; i<len; i++){
        if(*p==data){
            res=res+1;
        }
        ptr=getptrNextCell(ptr);
        p=getPtrData(ptr);
    }

    return res;
}


//affiche la liste grace à ??
void afficheListeV2( T_liste l){
    int *ptr=getPtrData(l);
    T_cellule *p=getptrFirstCell(l);
    int len=getNbreCell(l);
    for(int i=0; i<len; i++){
        printf("%d ", *ptr);
        p=getptrNextCell(p);
        ptr=getPtrData(p);
    }
}

//*******************************
//***********etape 2 ************
//*******************************

T_liste listeNbrAlea(int n){
    T_liste l;
    initListe(&l);
    srand(time(NULL));
    for(int i=0; i<n; i++){
        l=ajoutEnFin(l, (rand()%100));
    }
    return l;
}


void affichetab(int *tab, int len){
    for(int i=0; i<len; i++){
        printf("%d ", tab[i]);
    }
}


int *converttab(T_liste l, int taille){
    T_cellule *p=getptrFirstCell(l);
    int *val=getPtrData(p);
    int *tab=(int *)malloc(sizeof(int)*taille);
    for(int i=0; i<taille; i++){
        tab[i]=*val;
        p=getptrNextCell(p);
        val=getPtrData(p);
    }
    return tab;
}

int *converttabfree(T_liste l, int taille){
    T_cellule *p=getptrFirstCell(l);
    int *val=getPtrData(p);
    int *tab=(int *)malloc(sizeof(int)*taille);
    for(int i=0; i<taille; i++){
        tab[i]=*val;
        p=getptrNextCell(p);
        val=getPtrData(p);
    }
    p=getptrFirstCell(l);
    val=getPtrData(p);
    T_cellule *p2=getptrNextCell(p);
    int *val2=getPtrData(p2);
    for(int i=0; i<taille; i++){
        free(val);
        free(p);
        p=p2;
        val=val2;
        p2=getptrNextCell(p);
        val2=getPtrData(p2);
    }
    return tab;
}

T_liste tabintoliste(int *tab, int len){
    T_liste res;
    initListe(&res);
    for(int i=0; i<len; i++){
        int val=tab[i];
        res=ajoutEnFin(res, val);
    }
    return res;
}

void tri_selection(int *tableau, int taille){
    int en_cours, plus_petit, j, temp;

    for(en_cours = 0; en_cours<taille-1; en_cours++){
        plus_petit=en_cours;
        for(j = en_cours; j<taille; j++){
            if(tableau[j]<tableau[plus_petit])
                plus_petit=j;
            temp=tableau[en_cours];
            tableau[en_cours]=tableau[plus_petit];
            tableau[plus_petit]=temp;
        }
    }
}

T_liste triliste(T_liste l){
    int len=getNbreCell(l);
    int *tab=(int *)malloc(sizeof(int)*len);
    tab=converttab(l, len);
    tri_selection(tab, len);
    T_liste res=tabintoliste(tab, len);
    return res;
}

//**************************************************
//******************Etape 3*************************
//**************************************************


