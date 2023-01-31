#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "image.h"
#include "string.h"


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

    img1.img = malloc(sizeof(pixel*) * sy); //on alloue de la memoire pour le tableau de sous tableaux.

    for (int i=0; i < sy; i++){// le nombre de sous tableaux     
        img1.img[i] = malloc(sizeof(pixel) * sx);//allocation pour chaque tableau dans le gros tableau.
    } 

    img1.sizeX = sx; //on affecte a la largeur de img1, sx.
    img1.sizeY = sy; //on affecte a la hauteur de img1, sy.
    
    for(int i = 0; i < sy ; i++){ //on itere du nombre de pixels de l'image.
        for(int j = 0; j < sx ; j++){

            pixel actpix = random_pixel(); //on cree un pixel actpix et lui affecte un pixel avec des valeurs aleatoires.
            img1.img[i][j] = actpix;//on affecte au pixel de la case i,j du tableau de pixels de img1, le pixel actpix.

        }
    }
    
    return img1; //on renvoi l'image
}


//Fonction qui ecrit dans fichier une image de pixels au format .ppm.
int save(image img2, char *name){

    int X = img2.sizeX; //on affecte la largeur de l'image img2 a X.
    int Y = img2.sizeY; //on affecte la hauteur de l'image img2 a Y.

    FILE *fichier = NULL; //on cree un pointeur sur fichier qui pointe vers NULL.
    fichier = fopen(name, "w"); //on ouvre le fichier pour ecrire dedans.
    fprintf(fichier, "P3\n%d %d\n255\n", X, Y); //on ecrit dans le fichier la base des fichier .ppm

    if (fichier != NULL){ //si le fichier s'est bien ouvert, donc il ne pointe pas vers NULL.
        for( int i = 0; i < Y; i++ ){ // on parcoure la hauteur
            for(int j = 0; j < X; j++){ // on parcoure la largeur

                unsigned char ar = img2.img[i][j].r;//on met le r du pixel a la case i,j dans ar
                unsigned char av = img2.img[i][j].v;//on met le v du pixel a la case i,j dans av
                unsigned char ab = img2.img[i][j].b;//on met le b du pixel a la case i,j dans ab

                fprintf(fichier, "%d %d %d\n", ar, av, ab);// on ecrit dans le fichier le pixel
            }
            fprintf(fichier, "\n");// on change de ligne
        }

        fclose(fichier); //on ferme le fichier
    }else printf("Le pointeur vers le fichier est null");//sinon on print dans la console que le fichier pointe vers NULL.
    return 0;
}

//fonction qui compte de combien de chiffre est fait un nombre, 9 = 1 chiffre, 99 = 2, 98738746 = 8.
int howMany (int nb){

    int retour;

    int tab[4] = {9, 99, 999, 9999};
    int tab_aux[4] = {1, 2, 3, 4};

    for(int i = 0; i < 4; i++){
        if (nb - tab[i] <= 0){
            retour = tab_aux[i];
            return retour;
        }
    }

    
}

// image qui charge une image au format .ppm
image load(char *name){

    int x,y;

    //savoir les dimension de l'image

    FILE *fichier = NULL; //on cree un pointeur sur fichier qui pointe vers NULL.
    fichier = fopen(name, "r"); //on ouvre le fichier pour lire dedans.

    if (fichier != NULL);
    {
        //on lit les dimensions
        fseek(fichier, 3, SEEK_SET);
        fscanf(fichier, "%d %d", &x, &y);
    }

    int pos = 9 + howMany(x) + howMany(y);

    image loaded;
    loaded.sizeX = x;
    loaded.sizeY = y;
 
    loaded.img = malloc(sizeof(pixel*) * y); //on alloue de la memoire pour le tableau de sous tableaux.

    for (int i=0; i < y; i++){// le nombre de sous tableaux     
        loaded.img[i] = malloc(sizeof(pixel) * x);//allocation pour chaque tableau dans le gros tableau.
    } 
    fclose(fichier);

    fichier = NULL; //on cree un pointeur sur fichier qui pointe vers NULL.
    fichier = fopen(name, "r"); //on ouvre le fichier pour lire dedans.
    
    if (fichier != NULL)
    {
        fseek(fichier, pos, SEEK_SET);

        for(int i = 0; i < y ; i++){ //on itere du nombre de pixels de l'image.
            for(int j = 0; j < x ; j++){

                pixel actpix; //on cree un pixel actpix et lui affecte un pixel avec des valeurs aleatoires.

                unsigned char a;
                unsigned char b;
                unsigned char c;

                fscanf(fichier, "%d %d %d", &c, &b, &a);

                actpix.b = a; 
                actpix.v = b;
                actpix.r = c;

                loaded.img[i][j] = actpix;//on affecte au pixel de la case i,j du tableau de pixels de img1, le pixel actpix.

            }
        }
    
        fclose(fichier);
    }
    return loaded;
}

//Fonction qui transforme une image en niveau de rouge, vert ou bleu
int levels (char *name,char *newname, char *level){

    image img1 = load(name);

    int x,y;
    x = img1.sizeX;
    y = img1.sizeY;


    unsigned char new = 0;

    for( int i = 0; i < y; i++ ){ // on parcoure la hauteur
        for(int j = 0; j < x; j++){ // on parcoure la largeur

            if(strcmp(level,"rouge") == 0)
            {

                img1.img[i][j].v = new;//le pixel vert devient 0
                img1.img[i][j].b = new;//le pixel bleu devient 0
            }

            if(strcmp(level,"vert") == 0)
            {
                img1.img[i][j].r = new;//le pixel rouge devient 0
                img1.img[i][j].b = new;//le pixel bleu devient 0                
                
            }

            if(strcmp(level,"bleu") == 0)
            {
                img1.img[i][j].v = new;//le pixel vert devient 0
                img1.img[i][j].r = new;//le pixel rouge devient 0
            }
        }
    }

    save(img1, newname);
    return 0;
}


//Fonction qui transforme une image en noir et blanc
int greymoy (char *name,char *newname){

    image img1 = load(name);

    int x,y;
    x = img1.sizeX;
    y = img1.sizeY;

    for( int i = 0; i < y; i++ ){ // on parcoure la hauteur
        for(int j = 0; j < x; j++){ // on parcoure la largeur


            unsigned char r,v,b;
            r = img1.img[i][j].r;
            v = img1.img[i][j].v;
            b = img1.img[i][j].b;

            unsigned char moy = (r+v+b)/3;

            img1.img[i][j].r = moy;
            img1.img[i][j].v = moy;
            img1.img[i][j].b = moy;

        }
    }

    save(img1, newname);
    return 0;
}

unsigned char max(unsigned char a, unsigned char b){
    if (a > b)
        return a;
    else return b;
}

//Fonction qui transforme une image en noir et blanc
int greymax (char *name,char *newname){

    image img1 = load(name);

    int x,y;
    x = img1.sizeX;
    y = img1.sizeY;

    for( int i = 0; i < y; i++ ){ // on parcoure la hauteur
        for(int j = 0; j < x; j++){ // on parcoure la largeur


            unsigned char r,v,b;
            r = img1.img[i][j].r;
            v = img1.img[i][j].v;
            b = img1.img[i][j].b;

            unsigned char rv = max(r,v);

            unsigned char maxOfRvb = max(rv,b);

            img1.img[i][j].r = maxOfRvb;
            img1.img[i][j].v = maxOfRvb;
            img1.img[i][j].b = maxOfRvb;

        }
    }

    save(img1, newname);
    return 0;
}

//Fonction qui transforme une image en sepia
int sepia (char *name,char *newname){

    image img1 = load(name);

    int x,y;
    x = img1.sizeX;
    y = img1.sizeY;

    for( int i = 0; i < y; i++ ){ // on parcoure la hauteur
        for(int j = 0; j < x; j++){ // on parcoure la largeur


            unsigned char r,v,b;
            r = img1.img[i][j].r;
            v = img1.img[i][j].v;
            b = img1.img[i][j].b;

            unsigned char tr = ((0.393 * r) + (0.769 * v) + (0.189 * b));

            unsigned char tv = ((0.349 * r) + (0.686 * v) + (0.168 * b));

            unsigned char tb = ((0.272 * r) + (0.534 * v) + (0.131 * b));



            if (tr > 255){
                img1.img[i][j].r = 255;
            }
            else { img1.img[i][j].r = tr;
            }

            if (tv > 255){
                img1.img[i][j].v = 255;
            }
            else { img1.img[i][j].v = tv;
            }

            if (tb > 255){
                img1.img[i][j].b = 255;
            }
            else { img1.img[i][j].b = tb;
            }

        }
    }

    save(img1, newname);
    return 0;
}

