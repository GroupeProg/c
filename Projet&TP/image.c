#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int save(image img, char* nomFichier)
{
    int x = img.sizeX;
    int y = img.sizeY;

    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "w");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        fprintf(fichier,"P3\n%d %d\n255\n",x,y);

        for(int i=0;i<y;i++) //on recup les couleurs via dans le tab 2 dimensions
        {
            for(int u=0;u<x;u++)
            {
                unsigned char r = img.tab[i][u].r;
                unsigned char v = img.tab[i][u].v;
                unsigned char b = img.tab[i][u].b;
                fprintf(fichier,"%d %d %d\n",r,v,b);//on écrit les couleurs r g b = 0 0 0 = 1 pixel
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

image init(int sizeX,int sizeY)
{

    image img;
    img.sizeX = sizeX;
    img.sizeY = sizeY;

    img.tab = malloc(sizeof(pixel*)*sizeY); // alloue memoire pour ligne

    for(int i=0; i<sizeY;i++)
    {
        img.tab[i] = malloc(sizeof(pixel)*sizeX);//alloue memoire pour colonne
    }

    for(int i=0; i<sizeY;i++) 
    {
        for(int j=0; j<sizeX;j++)
        {
            pixel pix = initPixel();
            //printf("b=%d v=%d r=%d\n",pix.b,pix.v,pix.r);
            img.tab[i][j] = pix;

        }
    }



    return img;
}

pixel initPixel()
{
    pixel pix;
    int resR = rand() % 256;
    int resB = rand() % 256;
    int resV = rand() % 256;

    pix.r = resR;
    pix.b = resB;
    pix.v = resV;


    return pix;
}

int nbCarac(char* nomFichier)
{
    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "r");

    int nb_car = 0;
    int lines = 0;
    char f;

    while ((f=fgetc(fichier))!= EOF)
    {
        nb_car++;

        if (f == '\n' || f=='\0')
        {
            lines++;
        }
        if (lines == 1)
        {
            nb_car = 0;
        }
        else if (lines==3)
        {
            break;
        }

    }
    fclose(fichier);

    return nb_car;
}

image readImage(char* nomFichier)
{
    image img;
    int x;
    int y;



    FILE* fichier = NULL;
    fichier = fopen(nomFichier, "r");

    int numberChar;

    if (fichier != NULL)
    {
        fseek(fichier, 3,SEEK_SET); // on se place a la deuxieme ligne

        fscanf(fichier,"%d %d",&x,&y);

        img.sizeX = x;
        img.sizeY = y;

        numberChar = nbCarac(nomFichier); //nombre de caracteres a sauter

        fseek(fichier, 15,SEEK_SET); // on se place a la quatrieme ligne

        img.tab = malloc(sizeof(pixel*)*y); // alloue memoire pour ligne

        for(int i=0; i<y;i++)
        {
            img.tab[i] = malloc(sizeof(pixel)*x);//alloue memoire pour colonne
        }

        for(int i=0;i<img.sizeY;i++) //on recup les couleurs via dans le tab 2 dimensions
        {
            // trouver pk y = 0 dans for mais pas dans le reste ^
            for(int u=0;u<x;u++)
            {
                unsigned char a;
                unsigned char b;
                unsigned char c;

                fscanf(fichier,"%d %d %d",&c,&b,&a);
                img.tab[i][u].r = c;
                //fscanf(fichier,"%d",&v);
                //printf("v = %d",v);
                img.tab[i][u].v = b;
                //fscanf(fichier,"%d",&b);
                //printf("b = %d",b);
                img.tab[i][u].b = a;




            }
        }

        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier => readimage");
    }

    return img;
}



