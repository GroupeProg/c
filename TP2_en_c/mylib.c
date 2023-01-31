#include "mylib.h"
#include <math.h>

void ligne(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%c",'*');
    }
}

void moyenne(int a,int b,int c)
{
    float average = (a+b+c)/3;
    return average;
}

void polynome(int a,int b,int c)
{
    int delta = b*b - 4*a*c;
    if (delta>0)
    {
        printf("Delta > 0 \n");
        float x1 = (-b - sqrtf(delta))/(2*a);
        float x2 = (-b + sqrtf(delta))/(2*a);
        printf("Les racines sont : x1=%f, x2=%f",x1,x2);
    }
    else if (delta = 0)
    {
        printf("Delta = 0 \n");
        int x = (-b)/(2*a);
        printf("La racine est : x=%f",&x);
    }
    else {printf("Delta < 0 \n");}

    return delta;
}

void triBulles(int tab[], int taille)
{
    tab[taille];
    int a;
    for (int i=0;i<taille;i++) //tri
    {
        for (int u=i+1;u<taille;u++)
        {
            if (tab[i]>tab[u])
            {
                a=tab[i];
                tab[i]=tab[u];
                tab[u]=a;
            }

        }
        printf(" %d", tab[i]);
    }
}

int facto(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return n*facto(n-1);
    }
}



