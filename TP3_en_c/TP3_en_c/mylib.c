#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"


void afficheDate(t_date D)
{
    printf("Nous sommes le %s %d %s %d ",D.j,D.numeroJour,D.m,D.annee);
}

const char* getDayName(jour)
{
    switch (jour)
    {
        case 1 : return "Lundi";
        case 2 : return "Mardi";
        case 3 : return "Mercredi";
        case 4 : return "Jeudi";
        case 5 : return "Vendredi";
        case 6 : return "Samedi";
        case 7 : return "Dimanche";
    }
}

const char* getMonthName(mois)
{
    switch (mois)
    {
        case 1 : return "Janvier";
        case 2 : return "fevrier";
        case 3 : return "Mars";
        case 4 : return "Avril";
        case 5 : return "Mai";
        case 6 : return "Juin";
        case 7 : return "Juillet";
        case 8 : return "Aout";
        case 9 : return "Septembre";
        case 10 : return "Octobre";
        case 11 : return "Novembre";
        case 12 : return "Decembre";
    }
}

t_date saisieDate()
{
    int num, annee,a,b;
    t_jour jour;
    t_mois mois;
    printf("Numero du jour: ");
    scanf("%d", &num);
    fflush(stdin);
    printf("Le jour (de 1 a 7): ");
    scanf("%d",&a);
    fflush(stdin);
    printf("Le mois (de 1 a 12): ");
    scanf("%d",&b);
    fflush(stdin);
    printf("L'annee (2 derniers chiffres): ");
    scanf("%d", &annee);
    fflush(stdin);
    jour = (t_jour)getDayName(a);
    mois = (t_mois)getMonthName(b);
    t_date d={num,jour,mois,annee};

    return d;
}

void tabPointeur(int taille)
{
    int* tab = (int*)malloc(taille*sizeof(int));
    int* ptr = tab;

    for(int i=0;i<taille;i++)
    {
        *ptr = 6;
        printf("%d ",*ptr);
        ptr++;

    }
    free(tab);
}

float *allocTabFloat(int size)
{
    float* tab = (float*)malloc(size*sizeof(float));
    return tab;
}

int remplitTab(float *tab,int size)
{
    allocTabFloat(size);
    float* ptr = tab;

    for(int i=0;i<size;i++)
    {
        *ptr = 6.1;
        printf("%d ",*ptr);
        ptr++;

    }
    return 0;
}



