#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

#define PIXEL_TYPE "p3"

#include "../sources/tp1.h"

/**
 *
 *  Les images seront dans le format PPM :
 *  Exemple :
 *  Afin d'afficher une échelle de gris avec le ppm, les valeurs des pixels vont être les suivants
 *
 *  P3
 *  24 7 <- La taille longueur largeur
 *  15 <- Les graduations de gris
 *  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 *  0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
 *  0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
 *  0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
 *  0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
 *  0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
 *  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 *
 *  On ne peut travailler qu'avec des fichiers ppm.
*/

//Transforme un nombre en chaine de caractère
char *int_to_str(int a) {
    char chr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int puissance = 0;

    while(power(10, puissance) < a) {
        puissance++;
    }

    puissance--;
    int taille  = puissance+1;
    char *chr_return = malloc(taille * sizeof(char));

    int b = a/power(10, puissance);

    chr_return[puissance] = chr[b];
    puissance--;
    while (puissance >= 0)
    {
        a -= b * power(10, puissance + 1);
        b = a / power(10, puissance); // Diviser pour n'avoir que la 10 puissance voulu
        chr_return[puissance] = chr[b];
        puissance--;
    }

    if(strlen(chr_return) > taille) {
        chr_return[taille] = '\0';
    }
    chr_return = str_upside_down(chr_return);
    return chr_return;
}

//Créé un pixel rvb
pixel creerPiexel(int r, int v, int b) {
    pixel pix;

    if(b + r + v <= 255){
        pix.blue = b;
        pix.rouge = r;
        pix.vert = v;
        return pix;
    }
    else {
        pix.blue = -1;
        pix.rouge = -1;
        pix.vert = -1;
        return pix;
    }
}

void afficherPixel(pixel pix) {
    printf("Rouge : %3d\nVert : %3d\nBleu : %3d", pix.rouge, pix.vert, pix.blue);
}

void creerImage(image Img) {
    
}