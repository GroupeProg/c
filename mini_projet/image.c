#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

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
 * On ne peut travailler qu'avec des fichiers ppm.
*/

char *int_to_str(int a) {
    char *chr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int puissance = 0;
    while(power(10, puissance) < a) {
        puissance++;
    }
    puissance--;
    char *chr_return = (char *)malloc(puissance * sizeof(char *));

    int b = a/power(10, puissance);

    chr_return[-1] = chr[b];
    puissance--;

    while(puissance >= 0){
        a -= b*power(10, puissance+1);
        b = a/power(10, puissance);
        chr_return[puissance] = chr[b];
    }

    str_upside_down(chr_return);
    return chr_return;
}

pixel creerPiexel(int r, int v, int b) {
    pixel pix;

    if(b+r+v <= 255){
        pix.blue = b;
        pix.rouge = r;
        pix.vert = v;
        char c = " ";
        char rc = (char)r;
        char bc = (char)b;
        char vc = (char)v;
        //strcat(c, rc);
        //strcat(c, bc);
       // strcat(c, vc);
        pix.cha = c;
        return pix;
    }
    else {
        pix.blue = 0;
        pix.rouge = 0;
        pix.vert = 0;
        pix.cha = "Error";
        return pix;
    }
}

void afficherPixel(pixel pix) {
    printf("Rouge : %d\nVert : %d\nBleu : %d", pix.rouge, pix.vert, pix.blue);
}