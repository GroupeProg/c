#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include <stdio.h>

//Structure de donnees pixel qui comporte trois valeurs entieres r,v,b entre 0 et 255.
typedef struct{
    int r;
    int v;
    int b;
}pixel;

//Structure de donnees image, comportant un tableau a deux dimensions de pixels et le nombre de pixels en largeur sizeX et en hauteur sizeY.
typedef struct{
    int sizeX;
    int sizeY;
    pixel *img;
}image;


/* Prototypes. */
pixel init_pixel(int rouge, int vert, int bleu);//Fonction qui initialise un pixel.
pixel random_pixel(void);//Fonction qui initialise un pixel avec des valeurs random entre 0 et 256.
image init_image(int sx, int sy);//Fonction qui initialise une image.
int writePixel(FILE *fichier, pixel);//Fonction qui un pixel dans une fonction donnee.
image supLine(image pimg);//Fonction qui supprime la premiere ligne d'une image donnee.
int writeLine(FILE *fichier, image pimg);//Fonction qui la premiere ligne d'une image dans un fichier donnee.
int save(image *p, char *name);//Fonction qui ecrit une image entiere donnee dans un fichier donnee dans le format .ppm.






























#endif