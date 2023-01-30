#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "image.h"


//Fonction qui ecrit dans un fichier un pixel.
int writePixel(FILE *fichier, pixel pix){
    fprintf(fichier, "%d %d %d\n", pix.r, pix.v, pix.b);
    //si pix.r = 255, pix.v = 255, pix.b = 255 :
    //cela devrait ecrire dans le fichier: 255 255 255
    return 0;
}

/*fonction qui supprime la premiere ligne d'une image.
image supLine(image pimg){
    int X = pimg.sizeX; //on affecte la largeur de l'image pimg a X.
    int Y = pimg.sizeY; //on affecte la hauteur de l'image pimg a Y.

    int len = (X * Y)-(X); //len sera la taille en pixels de la nouvelle image; X * Y  c'est la taille total de pixels dans l'image, et -X pour enlever une ligne.

    image *cpimg = (image *)malloc(sizeof(image)); //on alloue de la memoire pour la nouvelle image cpimg.

    assert( cpimg != NULL ); //on teste si le malloc a bien pu allouer la memoire demandee.

    for(int i = 0; i < len; i++){ //on parcoure le tableau de pixels de l'image originale le meme nombre de fois que de cases dans le tableau de la nouvelle image.

        cpimg->img[i] = pimg.img[i + X]; //la case i de la nouvelle image va prendre la case i + la largeur de l'image originale.

        //exemple: tab_original = {pixel1, pixel2, pixel3, pixel4, pixel5, pixel6} pour X = 3 et Y = 2.
        //concretement dans le fichier cela serait : pixel1
        //                                           pixel2
        //                                           pixel3
        //
        //                                           pixel4
        //                                           pixel5
        //                                           pixel6
        //quand i = 0 la case i du nouveau tableau vaudra la case i du tableau original + X, donc elle vaudra p4
        //quand i = 1 elle vaudra p5 et quand i = 2, p6
        //donc new_tab =  {pixel4, pixel5, pixel6}
        //et on a effectue cette operation 3 fois car (X * Y)-X = (3 * 2)-3 = (6)-3 = 3
        //en gros, on veut que le nouveau tableau fasse le meme nombre de pixel que l'original moins le nombre de pixel de une ligne
    }
    cpimg->sizeY = Y - 1; //la hauteur de la nouvelle image est donc la meme que celle d'origine - 1
    cpimg->sizeX = X; //la largeur ne change pas, mais on est obliger de l'affecter car nous ne l'avons pas fait precedemment dans la fonction. nous avons juste touche au tableau et la hauteur
    free(pimg.img); //on libere la memoire du tableau originale qui avait ete alloue dans la fonction init_image.
    return *cpimg; //on renvoi la nouvelle image.
}*/

//fonction qui ecrit dans un fichier la premiere ligne de pixels d'une image.
int writeLine(FILE *fichier, image pimg){
    int X = pimg.sizeX; //on affecte la largeur de l'image pimg a X.

    for(int i = 0; i < X; i++){ //on parcoure autant de fois qu'il y a de pixels dans la premiere ligne.
        pixel pix = pimg.img[0][i]; //on cree un pixel pix qui contient le pixel de la case i.
        writePixel(fichier, pix); //on ecrit le pixel pix dans le fichier.
    }
    fprintf(fichier, "\n");//on revient a la ligne dans le fichier pour que ce soit pret pour ecrire la prochaine ligne.
    return 0;
}
/**

//Fonction qui ecrit dans fichier une image de pixels au format .ppm.
int save(image *pimg, char *name){

    image img2 = *pimg; //on cree une nouvelle image dans laquelle on met l'image originale.
    int X = img2.sizeX; //on affecte la largeur de l'image img2 a X.
    int Y = img2.sizeY; //on affecte la hauteur de l'image img2 a Y.

    FILE *fichier = NULL; //on cree un pointeur sur fichier qui point vers NULL.
    fichier = fopen(name, "w"); //on ouvre le fichier pour ecrire dedans.

    if (fichier != NULL){ //si le fichier s'est bien ouvert, donc il ne pointe pas vers NULL.

        fprintf(fichier, "P3\n%d %d\n255\n", X, Y); on ecrit dans le fichier la base des fichier .ppm, ce qui ferait:  P3
        *                                                                                                                X Y (hauteur et largeur)
        *                                                                                                                255

        writeLine(fichier, img2); //on ecrit dans le fichier la premiere ligne de img2.

        for(int i = 1; i < Y ; i++){ //on repete autant de fois qu'il y a de lignes (hauteur)
            img2 = supLine(img2); //img2 maintennt contient l'image originale moins la premiere ligne.
            writeLine(fichier, img2); //on ecrit la premier ligne de img2 dans le fichier (qui serait en fait la deuxieme ligne de l'image originale)

        }
        fclose(fichier); //on ferme le fichier
    }else printf("Le pointeur vers le fichier est null");//sinon on print dans la console que le fichier pointe vers NULL.
    return 0;
}
**/
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
int save(image *pimg, char *name){

    image img2 = *pimg; //on cree une nouvelle image dans laquelle on met l'image originale.
    int X = img2.sizeX; //on affecte la largeur de l'image img2 a X.
    int Y = img2.sizeY; //on affecte la hauteur de l'image img2 a Y.

    FILE *fichier = NULL; //on cree un pointeur sur fichier qui point vers NULL.
    fichier = fopen(name, "w"); //on ouvre le fichier pour ecrire dedans.
    fprintf(fichier, "P3\n%d %d\n255\n", X, Y); //on ecrit dans le fichier la base des fichier .ppm

    if (fichier != NULL){ //si le fichier s'est bien ouvert, donc il ne pointe pas vers NULL.
        for( int i = 0; i < Y; i++ ){
            for(int j = 0; j < X; j++){
                fprintf(fichier, "%d %d %d\n", img2.img[i][j].r, img2.img[i][j].v, img2.img[i][j].b);
            }
            fprintf(fichier, "\n");
        }

        fclose(fichier); //on ferme le fichier
    }else printf("Le pointeur vers le fichier est null");//sinon on print dans la console que le fichier pointe vers NULL.
    return 0;
}
