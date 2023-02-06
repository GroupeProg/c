#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Listechainee.h"

pile creerPileVide()
{
    pile *p=
    p=NULL;
    return p;
}

bool estVide(pile P)
{
    if(P==NULL){
        return true;
    }else return false;
}

pile empiler(pile P, char v)
{
    pile p2;
    p2=creerPileVide();
    p2.val=v;
    p2.next=P;
    return p2;
}
