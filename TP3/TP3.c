#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP3.h"

char *afficheDate_aux(date D){
    switch (D.d){
        case 0 : return "lundi"; break;
        case 1 : return "mardi"; break;
        case 2 : return "mercredi"; break;
        case 3 : return"jeudi"; break;
        case 4 : return"vendredi"; break;
        case 5 : return"samedi"; break;
        case 6 : return "dimanche"; break;
        default : return "nothing"; break;
    }
}

char *afficheDate_mois(date D){
    switch (D.m) {
        case 0 : return "janvier"; break;
        case 1 : return"fevrier"; break;
        case 2 : return "mars"; break;
        case 3 : return "avril"; break;
        case 4 : return "mai"; break;
        case 5 : return "juin"; break;
        case 6 : return "juillet"; break;
        case 7 : return "aout"; break;
        case 8 : return "septembre"; break;
        case 9 : return "octobre"; break;
        case 10 : return "novembre"; break;
        case 11 : return "decembre"; break;
        default : return "nothing"; break;
    }
}
void afficheDate(date D){
    char jour[10];
    strcpy(jour, afficheDate_aux(D));
    char mois[15];
    strcpy(mois, afficheDate_mois(D));
    printf("la date est : %s %d %s %d", jour, D.day_nbr,mois, D.annee);
}

date saisieDate(){
}

//pointeurs

void test_pointeurs(){
    int a=5;
    int *p=&a;
    int *q=NULL;
    printf("%d\n",*p);
    scanf("%d", p);
    printf("%d", *p);
    printf("%d", a);
    int b=*p;
    printf("%d\n", b);
    int *ptr=p;
    scanf("%d", ptr);
    printf("%d %d %d",a, *ptr, *p);
}
void test_pointeurs2(){
    srand(time(NULL));
    int tab[100];
    for(int i=0; i<100; i++){
        tab[i]=rand() % 10;
        printf("%d", tab[i]);
    }
    int * ptr=tab;
    printf("\n%d\n", *ptr);
    for(int i=0; i<100; i++){
        printf("%d", *ptr);
        ptr++;
    }
}



