#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Listechainee.h"

int main()
{
    pile p;
    p=creerPileVide();
    p=empiler(p, 'b');
    bool res;
    res=estVide(p);
    if(res==true){
        printf("true");
    }else printf("false");
}
