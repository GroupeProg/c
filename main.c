#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "mini_projet_kaez\image.h"


int main(){

/*
//je cree une image
    image img1;


//intialisation de sizeX et sizeY de l'image
    img1.sizeX = 5; 
    img1.sizeY = 6; 

//affectation et creation de variables X, Y et len
    int Y, X;
    Y = img1.sizeY;
    X = img1.sizeX;
    int len = X * Y;

//alloc de memoire pour l'image
    img1.img = malloc(sizeof(pixel)*len); 

//print le x et le y
    printf("\nx : %d y : %d", img1.sizeX, img1.sizeY);

//creation de tableau double et alloc de memoire
    pixel **tabl = malloc(sizeof(pixel)*len);


    for(int i = 0; i < Y ; i++){ // je parcoure la hauteur
        for(int j = 0; j < X ; j++){ // je parcoure la largeur

            // je cree un pixel random
            pixel actpix = random_pixel();

            //la valeur du tableau i,j prend le pixel
            tabl[i][j] = actpix;

        }
    }

//le tableau de l'image prend le tableau tabl
    img1.img = tabl;


    for(int i = 0; i < Y ; i++){ // je parcoure la hauteur
        for(int j = 0; j < X ; j++){// je parcoure la largeur

            unsigned char ar = tabl[i][j].r;
            unsigned char av = tabl[i][j].v;
            unsigned char ab = tabl[i][j].b;

            //print les r,v,b du pixel i,j
            printf("\n%d %d %d", ar, av, ab);

        }
        //tabulation
        printf("\n");
    }
    
    //libere la memoire de tabl
    free(tabl);

    return 0;
*/
/*

    pixel pix1 = random_pixel();
    pixel pix2 = random_pixel();
    pixel pix3 = random_pixel();
    pixel pix4 = random_pixel();


    printf("\nle pixel 1: %d %d %d", pix1.r, pix1.v, pix1.b);
    printf("\nle pixel 2: %d %d %d", pix2.r, pix2.v, pix2.b);
    printf("\nle pixel 3: %d %d %d", pix3.r, pix3.v, pix3.b);
    printf("\nle pixel 4: %d %d %d", pix4.r, pix4.v, pix4.b);

    
return 0;
*/
/*
    tabl[0][0] = pix1;
    tabl[0][1] = pix2;
    tabl[1][0] = pix3;
    tabl[1][1] = pix4;
    


    //image img1 = init_image(1,1); //on cree une image img1.

    
    int ar = img1.img[0][0].r;
    int av = img1.img[0][0].v;
    int ab = img1.img[0][0].b;

    int br = img1.img[0][1].r;
    int bv = img1.img[0][1].v;
    int bb = img1.img[0][1].b;

    int cr = img1.img[1][0].r;
    int cv = img1.img[1][0].v;
    int cb = img1.img[1][0].b;

    int dr = img1.img[1][1].r;
    int dv = img1.img[1][1].v;
    int db = img1.img[1][1].b;
*/


    image *abc = init_image(1,1);
    int Y,X;
    Y = abc->sizeY;
    X = abc->sizeX;
    pixel **tab = malloc(sizeof(pixel) * X * Y);
    tab = abc->img;

    for( int i = 0; i < Y; i++ ){
            for(int j = 0; j < X; j++){

                unsigned char ar = tab[i][j].r;
                unsigned char av = tab[i][j].v;
                unsigned char ab = tab[i][j].b;
                printf("%d %d %d\n", ar, av, ab);
            }
            printf("\n");
        }

    //image *pimage = &azer;
    //save(pimage, "mini_projet_kaez/img.ppm");

   



}
