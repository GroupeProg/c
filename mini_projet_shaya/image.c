#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <errno.h>

#include "image.h"
#define PIXEL_TYPE "P3"

#include "../sources/tp1.h"

/**
 *
 *  Les images seront dans le format PPM :
 *  Exemple :
 *  Afin d'afficher une échelle de gris avec le ppm, les valeurs des pixels vont être les suivants
 *
 *  P2 <- P2 Gris, P3 RVB ASCII, P6 RVB Binaire
 *  24 7 <- La taille longueur largeur
 *  15 <- Les graduations de gris, inscrire 255 pour RVB
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


// Deuxième version d'inversion des caractères
char *str_upside_down_2(char *str_para)
{
    char *str = malloc(sizeof(str_para)-1);
    int taille = strlen(str_para);
    int index = taille-1;

    for(int i = 0; i < taille; i++){
        str[i] = str_para[index-i];
    }

    if(strlen(str) > taille) {
        str[taille] = '\0';
    }

    return str;
}

// Additionne 3 chaines de caractères avec un espace au milieu
char *strcat3(char *a, char *b, char *c)
{
    int size = sizeof(a)*2 + sizeof(b)*2 + sizeof(c)*2 + sizeof(" ") * 3;
    char *d = (char *)malloc(size);
    d[0] = '\0';
    char *espace = " ";
    strcat(d, a);
    strcat(d, espace);
    strcat(d, b);
    strcat(d, espace);
    strcat(d, c);
    strcat(d, espace);
    return d;
}

//Transforme un nombre en chaine de caractère
char *int_to_str(int a) {
    if(a == 0) {
        return "0";
    }

    char chr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int puissance = 0;

    while(power(10, puissance) <= a) {
        puissance++;
    }

    puissance--;
    int taille  = puissance+1;
    char *chr_return = malloc(taille * sizeof(char) + 1);

    int b = a/power(10, puissance); // ex : a = 1256, b = 1000, a = 256
    chr_return[puissance] = chr[b];
    puissance--;

    while (puissance >= 0)
    {

        a -= b * power(10, puissance + 1); //
        b = a / power(10, puissance);      // Diviser pour n'avoir que la 10 puissance voulu
        chr_return[puissance] = chr[b];
        puissance--;
    }

    if(strlen(chr_return) > taille) {
        chr_return[taille] = '\0';
    }
    chr_return = str_upside_down_2(chr_return);
    if(chr_return[0] == '\0'){
        printf("ERROR pour %d !", a);
        errno = 23;
    }
    return chr_return;
}

/**
 * Fonction qui permet de retourner un nombre à partir d'une chaine de caractère.
 * Il est possible de renseigner des nombre pour un char afin de donner un nombre ascii
 * 1 = 49
 * 2 = 50
 * ...
 * 9 = 57
*/
int str_to_int(char *str) {

    int int_return = 0;
    int taille = strlen(str);
    char *chr_ud = str_upside_down_2(str);

    for(int i = 0; i < strlen(str); i++){
        int str = (int)(chr_ud[i]);
        int current_int;

        switch (str)
        {
        case 48:
            current_int = 0;
            break;

        case 49:
            current_int = 1;
            break;

        case 50:
            current_int = 2;
            break;

        case 51:
            current_int = 3;
            break;

        case 52:
            current_int = 4;
            break;

        case 53:
            current_int = 5;
            break;

        case 54:
            current_int = 6;
            break;

        case 55:
            current_int = 7;
            break;

        case 56:
            current_int = 8;
            break;

        case 57:
            current_int = 9;
            break;

        default:
            return int_return;
            break;
        }

        int_return += current_int * power(10, i);
    }
    return int_return;

}

//Créé un pixel rvb
pixel creerPixel(int r, int v, int b) {
    pixel pix;

    if(b + r + v <= 255*3){
        pix.blue = b;
        pix.rouge = r;
        pix.vert = v;

        pix.chr = strcat3(
            int_to_str(r),
            int_to_str(v),
            int_to_str(b)
        );

        return pix;
    }
    else {
        pix.blue = -1;
        pix.rouge = -1;
        pix.vert = -1;
        pix.chr = "Error";
        return pix;
    }
}

// Créer un pixel avec des valeurs aléatoires
pixel creerPixelRandom()
{
        int r, v, b, test = 0;
        test = rand() % 12;

        r = rand() % 256;
        v = rand() % 256;
        b = rand() % 256;

        pixel pix;
        pix.rouge = r;
        pix.vert = v;
        pix.blue = b;
        pix.chr = strcat3(
            int_to_str(r),
            int_to_str(v),
            int_to_str(b));

        return pix;
}

void afficherPixel(pixel pix) {
    printf("Rouge : %3d\nVert  : %3d\nBleu  : %3d", pix.rouge, pix.vert, pix.blue);
}

//Créer la base d'une image 
image creerImage(int X, int Y) {
    image img;
    img.X = X;
    img.Y = Y;
    img.pixel_tab = (pixel *)malloc(X * Y * sizeof(pixel));

    return img;
}

// Crééer une image avec des pixel random
image creerImageRandom(int X, int Y)
{
    srand(clock() + time(NULL) * CLOCKS_PER_SEC);
    image img;
    img.X = X;
    img.Y = Y;
    img.pixel_tab = malloc(X * Y * sizeof(pixel) - 1);
    img.nbrPix = 0;

    for(int i = 0; i < (img.X * img.Y); i++) {
        img.nbrPix++;
        img.pixel_tab[i] = creerPixelRandom();
    }

    return img;
}

// Permet de sauvegarder des fichier au format pixel-image en PPM
int saveToPPM(image img, char *path) {
    FILE *fichier = fopen(path, "w");
    int nbr_pixel = img.X * img.Y;

    fputs(PIXEL_TYPE, fichier); // On inscrit le type de PPM
    fputc('\n', fichier);
    fputs(int_to_str(img.X), fichier); // On renseigne les dimensions
    fputc(' ', fichier);
    fputs(int_to_str(img.Y), fichier);
    fputc('\n', fichier);
    fputs("255", fichier); // Le 255 indique qu'on travaille sur du RVB
    fputc('\n', fichier);

    for (int i = 0; i < nbr_pixel; i++)
    {

        if ((i % img.X == 0) && (i >= img.X))
        {
            fputc('\n', fichier);
        }

        if(errno != 0) {
            printf("ERREUR ! %d\n", errno);
            return errno;
        }

        fputs(img.pixel_tab[i].chr, fichier);
    }
    fclose(fichier);
    return 0;
}

// Fonction permettant de récupérer un fichier PPM et de le charger
image loadFromPPM(char *path) {
    image img;
    FILE *fichier = fopen(path, "r+");
    if(errno == 22) {
        perror("Erreur 22 : Impossible d'ouvrir le fichier !");
    }

    char recup;

    // Avoir la taille du fichier
    fseek(fichier, 0L, SEEK_END);
    size_t size_file = ftell(fichier);
    fseek(fichier, 0L, 0);

    char *contenu = (char *)malloc(size_file * sizeof(char));
    int i = 0;

    while (recup != EOF)
    {
        recup = fgetc(fichier); // On lit le caractère
        contenu[i] = recup;
        i++;
    }
    contenu[i] = '\0';
    i = 3;

    char type[] = {contenu[0], contenu[1], '\0'};
    char *xi = (char *)malloc(10 * sizeof(char));
    char *yi = (char *)malloc(10 * sizeof(char));
    int x, y;

    recup = contenu[i];

    while(recup != ' ') {
        xi[i-3] = recup;
        i++;
        recup = contenu[i];
    }
    xi[i-3] = '\0';
    x = str_to_int(xi);

    i++;
    recup = contenu[i];
    while(recup != '\n') {
        yi[i-4-strlen(xi)] = contenu[i];
        i++;
        recup = contenu[i];
    }
    yi[i - 4 - strlen(xi)] = '\0';
    y = str_to_int(yi);

    img.X = x;
    img.Y = y;

    int decalage = 5 + strlen(xi) + strlen(yi);

    i++;

    char *nuance_str = malloc(3 * sizeof(char));
    int nuance;

    recup = contenu[i];
    while (recup != '\n')
    {
        nuance_str[i - decalage] = recup;
        i++;
        recup = contenu[i];
    }
    nuance_str[i - decalage] = '\0';

    nuance = str_to_int(nuance_str);

    decalage += 4;

    char *a = malloc(sizeof(char));

    pixel *pixtab = malloc(x * y * sizeof(pixel)*2);

    int index = 0;

    while(recup != '\0') {
        pixel pix;
        int r, v, b = 0;
        char *rc = malloc(3 * sizeof(char));
        char *vc = malloc(3 * sizeof(char));
        char *bc = malloc(3 * sizeof(char));

        recup = contenu[i];
        
        if (recup == ' ' || recup == '\n' || recup == '\0')
        {
            i++;
            recup = contenu[i];
        }

        for(int j = 0; j < 4; j++) {
            recup = contenu[i];
            if (recup == ' ')// || recup == '\n' || recup == '\0')
            {
                rc[j] = '\0';
                break;
            }
            rc[j] = recup;
            i++;
        }

        recup = contenu[i];

        if (recup == ' ')// || recup == '\n')
        {
            i++;
            recup = contenu[i];
        }

        for (int k = 0; k < 4; k++)
        {
            recup = contenu[i];
            if (recup == ' ')// || recup == '\n')
            {
                vc[k] = '\0';
                break;
            }
            vc[k] = recup;
            i++;
        }

        recup = contenu[i];

        if (recup == ' ')// || recup == '\n')
        {
            i++;
            recup = contenu[i];
        }

        for (int l = 0; l < 4; l++)
        {
            recup = contenu[i];
            if (recup == ' ')// || recup == '\n')
            {
                bc[l] = '\0';
                break;
            }
            bc[l] = recup;
            i++;
        }

        r = str_to_int(rc);
        v = str_to_int(vc);
        b = str_to_int(bc);

        pix = creerPixel(r, v, b);
        if(pix.rouge == -1) {
            printf("ERROR ON PIX NUMBER %d\n", index);
            break;
        }

        pixtab[index] = pix;

        if(index == (x * y)-1) {
            break;
        }
        index++;
    }
    index++;
    img.nbrPix = index;
    img.pixel_tab = pixtab;
    fclose(fichier);
    return img;
}

void imagePixel(image img) {
    for(int i = 0; i < img.X * img.Y; i++) {
        afficherPixel(img.pixel_tab[i]);
        printf("\n---------\n");
    }
}

// Transformer en Sepia et placer un filtre
// Se concentrer sur les contour pour faire un cadre