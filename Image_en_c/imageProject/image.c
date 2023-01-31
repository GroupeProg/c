#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int save(image img, char *nf)
{
    int x = img.sizeX;
    int y = img.sizeY;

    FILE* fichier = NULL;
    fichier = fopen("test.txt", "r+");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        fprintf(fichier,"P3\n%d %d\n255\n",x,y);

        for(int i=0;i<x;i++) //on recup les couleurs via dans le tab 2 dimensions
        {
            for(int u=0;u<y;u++)
            {
                unsigned char r = img.tab[i][u].r;
                unsigned char v = img.tab[i][u].v;
                unsigned char b = img.tab[i][u].b;
                fprintf(fichier,"%d\t%d\t%d\n",r,v,b);//on ecrit les couleurs r g b = 0 0 0 = 1 pixel
            }
            fprintf(fichier,"\n");
        }
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}







