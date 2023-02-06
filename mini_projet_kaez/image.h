#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include <stdio.h>

//Structure de donnees pixel qui comporte trois valeurs entieres r,v,b entre 0 et 255.
typedef struct{
    unsigned char r;
    unsigned char v;
    unsigned char b;
}pixel;

//Structure de donnees image, comportant un tableau a deux dimensions de pixels et le nombre de pixels en largeur sizeX et en hauteur sizeY.
typedef struct{
    pixel **img;
    int sizeX;
    int sizeY;
}image;


/* Prototypes. */
pixel init_pixel(unsigned char rouge, unsigned char vert, unsigned char bleu);//Fonction qui initialise un pixel.
pixel random_pixel(void);//Fonction qui initialise un pixel avec des valeurs random entre 0 et 256.
image init_image(int sx, int sy);//Fonction qui initialise une image.
int save(image img, char *name);//Fonction qui ecrit une image entiere donnee dans un fichier donnee dans le format .ppm.
int howMany (int nb);
image load(char *name);
int levels (char *name,char *newname, char *level);
int greymoy (char *name,char *newname);
unsigned char max(unsigned char a, unsigned char b);
int greymax (char *name,char *newname);
int sepia (char *name,char *newname);
pixel moy4pixl (pixel pix1, pixel pix2, pixel pix3, pixel pix4);
pixel moy6pixl (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6);
pixel moy9pixl (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6, pixel pix7, pixel pix8, pixel pix9);
int lissage (char *name,char *newname);
pixel moy4pixc (pixel pix1, pixel pix2, pixel pix3, pixel pix4);
pixel moy6pixc (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6);
pixel moy9pixc (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6, pixel pix7, pixel pix8, pixel pix9);




























#endif