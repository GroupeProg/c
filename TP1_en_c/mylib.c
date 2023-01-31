#include "mylib.h"
#include <time.h>

void printNomPrenom()
{
    char prenom[10];
    char nom[10];
    printf("quel est ton prenom et ton nom? ");
    scanf("%s", prenom);
    scanf("%s", nom);
    printf("Bonjour %s %s !", prenom, nom);
    return 0;
}

void differentTypePercent()
{
    int number = 38;
    int num = 125;
    printf("%c | %c\n", number, num); //& | }
    printf("%d | %d\n", number, num); // 38 | 125
    printf("%f | %f\n", number, num); // 0.00000 | 0.000000
    printf("%i | %i\n", number, num); // 38 | 125
    printf("%o | %o\n", number, num); // 46 | 175
    printf("%O | %O\n", number, num); // 0 | O
    printf("%x | %x\n", number, num); // 26 | 7d
    printf("%X | %X\n", number, num); // 26 | 7D
    return 0;
}

void permuterDeuxValeurs()
{
    int num1;
    int num2;
    // int c
    printf("Ecris deux nombres : \n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("num1 = %d \nnum2 = %d \n", num1, num2);
    num1 = num1 + num2; // c = num1;
    num2 = num1 - num2; // num1 = num2;
    num1 = num1 - num2; // num2 = c;
    printf("num1 = %d \nnum2 = %d", num1, num2);
    return 0;
}

void bissextile()
{
    int year;
    printf("Renseignez l'annee souhaitee : \n");
    scanf("%d", &year);
    if (year%4==0 && year%100!=0 || year%400==0)
    {
        printf("L'annee %d est bissextile !", year);
    }
    else{printf("l'annee %d n'est pas bissextile !", year);}
}

void dayPerMonth()
{
    int mois;
    printf("choisissez le numero du mois : ");
    scanf("%d", &mois);
    printf("%d", mois);
    switch (mois)
    {
        case 1: printf("\n31"); break;
    default:
        printf("Error! operator is not correct");
    }
}

void tabRand()
{
    int tab[200];
    int a;
    srand(time(NULL));
    for(int i=0;i<200;i++)
    {
        int num=rand() % (100 - 11);
        num +=11;
        tab[i]= num;
        if(tab[i]<tab[i+1])
        {
            a=tab[i];
            tab[i]=tab[i-1];
            tab[i-1]=a;
        }else tab[i];
    };
    for(int i=0;i<=200;i++)
    {
        printf("%d\n",tab[i]);
    };
}

void tabRandTri()
{
    int tab[200];
    int a;

    srand(time(NULL));
    for (int i=0;i<200;i++) //creation de valeurs dans tab
    {
        int num=rand() % (100 - 11);
        num +=11;
        tab[i]= num;
    }

    for (int i=0;i<200;i++) //tri
    {
        for (int u=i+1;u<200;u++)
        {
            if (tab[i]>tab[u])
            {
                a=tab[i];
                tab[i]=tab[u];
                tab[u]=a;
            }
        }
    }
    for(int i=0;i<200;i++) //affichage
    {
        printf("%d ",tab[i]);
    };
}
