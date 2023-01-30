#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "image.h"


//fonction qui initialise un pixel en lui donnant les valeurs de rvb.
pixel init_pixel(unsigned char rouge, unsigned char vert, unsigned char bleu){
    pixel pix; // on cree le pixel pix.

    pix.r = rouge; //on affecte au r de pix la valeur de rouge.
    pix.v = vert; //on affecte au v de pix la valeur de vert.
    pix.b = bleu; //on affecte au b de pix la valeur de bleu.

    return pix; //on renvoi le pixel.
}

//fonction qui initalise un pixel avec des valeurs aleatoires.
pixel random_pixel(){
    int tab_of_colors[3]; //on cree un tableau avec 3 cases pour y stocker la valeur de r, v et b.

    for(int i = 0 ; i < 3; i++){ //on itere 3 fois pour mettre dans le tableau les trois valeurs.

        tab_of_colors[i] = rand()%256; //la case i du tableau prend un entier aleatoire entre 0 et 256.
    }

    unsigned char rouge = tab_of_colors[0]; //donc on cree un entier rouge pour y mettre la premiere valeur du tableau.
    unsigned char vert = tab_of_colors[1]; //on cree un entier vert pour y mettre la deuxieme valeur du tableau.
    unsigned char bleu = tab_of_colors[2]; //on cree un entier bleu pour y mettre la troisieme valeur du tableau.

    pixel pix = init_pixel(rouge, vert, bleu); // on cree un pixel pix et on lui affecte un pixel initialise avec les valeurs de rouge, vert et bleu.

    return pix; //on renvoi le pixel.
}

//fonction qui initialise une image avec des pixels de couleur aleatoire en lui donnant les dimensions de sa hauteur et sa largeur.
image init_image(int sx, int sy){
    int len = sx * sy; //len est un entier qui contient le nombre de pixels de l'image.(hauteur * largeur)

    image img1; //on cree une image img1.

    img1.img = malloc(sizeof(pixel*) * sy); //on alloue de la memoire pour la nouvelle image cpimg.

    for (int i=0; i < sy; i++){
        // allocation de chaque tableau à 1 dimension
        img1.img[i] = malloc(sizeof(pixel) * sx);
    } 

    img1.sizeX = sx; //on affecte a la largeur de img1, sx.
    img1.sizeY = sy; //on affecte a la hauteur de img1, sy.


    
    for(int i = 0; i < sy ; i++){ //on itere du nombre de pixels de l'image.
        for(int j = 0; j < sx ; j++){
            pixel actpix = random_pixel(); //on cree un pixel actpix et lui affecte un pixel avec des valeurs aleatoires.
            img1.img[i][j] = actpix;//on affecte au pixel de la case i du tableau de pixels de img1, le pixel actpix.

        }
    }
    

    return img1; //on renvoi l'image
}




//Fonction qui ecrit dans fichier une image de pixels au format .ppm.
int save(image img2, char *name){

    int X = img2.sizeX; //on affecte la largeur de l'image img2 a X.
    int Y = img2.sizeY; //on affecte la hauteur de l'image img2 a Y.

    FILE *fichier = NULL; //on cree un pointeur sur fichier qui point vers NULL.
    fichier = fopen(name, "w"); //on ouvre le fichier pour ecrire dedans.
    fprintf(fichier, "P3\n%d %d\n255\n", X, Y); //on ecrit dans le fichier la base des fichier .ppm

    if (fichier != NULL){ //si le fichier s'est bien ouvert, donc il ne pointe pas vers NULL.
        for( int i = 0; i < Y; i++ ){
            for(int j = 0; j < X; j++){

                unsigned char ar = img2.img[i][j].r;
                unsigned char av = img2.img[i][j].v;
                unsigned char ab = img2.img[i][j].b;

                fprintf(fichier, "%d %d %d\n", ar, av, ab);
            }
            fprintf(fichier, "\n");
        }

        fclose(fichier); //on ferme le fichier
    }else printf("Le pointeur vers le fichier est null");//sinon on print dans la console que le fichier pointe vers NULL.
    return 0;
}
