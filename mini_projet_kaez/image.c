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


            int r,v,b;
            r = img1.img[i][j].r;
            v = img1.img[i][j].v;
            b = img1.img[i][j].b;

            int tr = ((0.393 * r) + (0.769 * v) + (0.189 * b));

            int tv = ((0.349 * r) + (0.686 * v) + (0.168 * b));

            int tb = ((0.272 * r) + (0.534 * v) + (0.131 * b));

            unsigned char a2,b2,c2;

            a2 = tr;
            b2 = tv;
            c2 = tb;


            if (tr > 255){
                img1.img[i][j].r = 255;
            }
            else { img1.img[i][j].r = a2;
            }

            if (tv > 255){
                img1.img[i][j].v = 255;
            }
            else { img1.img[i][j].v = b2;
            }

            if (tb > 255){
                img1.img[i][j].b = 255;
            }
            else { img1.img[i][j].b = c2;
            }

        }
    }


    save(img1, newname);
    return 0;
}

//fonction qui renvoi un pixel avec la moyenne de 3 autres.
pixel moy4pixl (pixel pix1, pixel pix2, pixel pix3, pixel pix4){
    pixel res;
    unsigned char moyr = (pix1.r + pix2.r + pix3.r + pix4.r)/4;
    unsigned char moyv = (pix1.v + pix2.v + pix3.v + pix4.v)/4;
    unsigned char moyb = (pix1.b + pix2.b + pix3.b + pix4.b)/4;

    res.r = moyr;
    res.v = moyv;
    res.b = moyb;

    return res;
}

//fonction qui renvoi un pixel avec la moyenne de 6 autres.
pixel moy6pixl (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6){
    pixel res;
    unsigned char moyr = (pix1.r + pix2.r + pix3.r + pix4.r + pix5.r + pix6.r)/6;
    unsigned char moyv = (pix1.v + pix2.v + pix3.v + pix4.v + pix5.v + pix6.v)/6; 
    unsigned char moyb = (pix1.b + pix2.b + pix3.b + pix4.b + pix5.b + pix6.b)/6;

    res.r = moyr;
    res.v = moyv;
    res.b = moyb;

    return res;
}

//fonction qui renvoi un pixel avec la moyenne de 5 autres.
pixel moy9pixl (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6, pixel pix7, pixel pix8, pixel pix9){
    pixel res;
    unsigned char moyr = (pix1.r + pix2.r + pix3.r + pix4.r + pix5.r + pix6.r + pix7.r + pix8.r + pix9.r)/9;
    unsigned char moyv = (pix1.v + pix2.v + pix3.v + pix4.v + pix5.v + pix6.v + pix7.v + pix8.v + pix9.v)/9; 
    unsigned char moyb = (pix1.b + pix2.b + pix3.b + pix4.b + pix5.b + pix6.b + pix7.b + pix8.b + pix9.b)/9;

    res.r = moyr;
    res.v = moyv;
    res.b = moyb;

    return res;
}

//Fonction qui lisse une image
int lissage_aux(char *name,char *newname){

    image img1 = load(name);

    int x,y;
    x = img1.sizeX;
    y = img1.sizeY;

    image imglisse;
    imglisse.sizeX = x;
    imglisse.sizeY = y;

    imglisse.img = malloc(sizeof(pixel*) * y); //on alloue de la memoire pour le tableau de sous tableaux.

    for (int i=0; i < y; i++){// le nombre de sous tableaux     
        imglisse.img[i] = malloc(sizeof(pixel) * x);//allocation pour chaque tableau dans le gros tableau.
    } 

    for( int i = 0; i < y; i +=3 ){ // on parcoure la hauteur
        for(int j = 0; j < x; j +=3){ // on parcoure la largeur

            //Fenetre:                           //debut de la fenetre suivante
                //[i]  [j] | [i]  [j+1] | [i]  [j+2] | [i]  [j+3]
                //-----------------------------------|
                //[i+1][j] | [i+1][j+1] | [i+1][j+2] | [i+1][j+3]
                //-----------------------------------|
                //[i+2][j] | [i+2][j+1] | [i+2][j+2] | [i+2][j+3]
                //- - - - - - - - - - - - - - - - - - 
                //[i+3][j] | [i+3][j+1] | [i+3][j+2] | [i+3][j+3]

                //sous la forme:
                // pix1     | pix2       | pix3    | pixAlpha
                //---------------------------------|
                // pix4     | pix5       | pix6    | pixBeta
                //---------------------------------|
                // pix7     | pix8       | pix9    | pixGama
                //- - - - - - - - - - - - - - - - - 
                // pixDelta | pixEpsilon | pixZeta | pixEta



            //si on est en haut
            if (i == 0){

                 //si on est au bord de gauche
                if (j == 0){  

                    //on definit chaque pixel actuel dans la fenetre.
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i+3][j].r;
                    pixDelta.v = img1.img[i+3][j].v;
                    pixDelta.b = img1.img[i+3][j].b;

                    pixEpsilon.r = img1.img[i+3][j+1].r;
                    pixEpsilon.v = img1.img[i+3][j+1].v;
                    pixEpsilon.b = img1.img[i+3][j+1].b;

                    pixZeta.r = img1.img[i+3][j+2].r;
                    pixZeta.v = img1.img[i+3][j+2].v;
                    pixZeta.b = img1.img[i+3][j+2].b;

                    pixEta.r = img1.img[i+3][j+3].r;
                    pixEta.v = img1.img[i+3][j+3].v;
                    pixEta.b = img1.img[i+3][j+3].b;



                    //le pix1
                    imglisse.img[i][j] = moy4pixl(pix1,pix2,pix5,pix4);
                    //le pix2
                    imglisse.img[i][j+1] = moy6pixl(pix1,pix2,pix3,pix4,pix5,pix6);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy6pixl(pix1,pix2,pix4,pix5,pix7,pix8);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixl(pix4,pix5,pix7,pix8,pixDelta,pixEpsilon);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixl(pix4,pix5,pix6,pix7,pix8,pix9,pixDelta,pixEpsilon,pixZeta);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixl(pix5,pix6,pix8,pix9,pixGama,pixBeta,pixEpsilon,pixZeta,pixEta);
 
                }
                 //si on est au bord de droite
                if (j == x - 3){

                    //on definit chaque pixel actuel dans la fenetre.
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i+3][j].r;
                    pixDelta.v = img1.img[i+3][j].v;
                    pixDelta.b = img1.img[i+3][j].b;

                    pixEpsilon.r = img1.img[i+3][j+1].r;
                    pixEpsilon.v = img1.img[i+3][j+1].v;
                    pixEpsilon.b = img1.img[i+3][j+1].b;

                    pixZeta.r = img1.img[i+3][j+2].r;
                    pixZeta.v = img1.img[i+3][j+2].v;
                    pixZeta.b = img1.img[i+3][j+2].b;

                    pixEta.r = img1.img[i+3][j-1].r;
                    pixEta.v = img1.img[i+3][j-1].v;
                    pixEta.b = img1.img[i+3][j-1].b;



                    //le pix1
                    imglisse.img[i][j] = moy6pixl(pix1,pix2,pix4,pix5,pixAlpha,pixBeta);
                    //le pix2
                    imglisse.img[i][j+1] = moy6pixl(pix1,pix2,pix3,pix4,pix5,pix6);
                    //le pix3
                    imglisse.img[i][j+2] = moy4pixl(pix2,pix3,pix5,pix6);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixl(pix1,pix2,pix4,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy6pixl(pix2,pix3,pix5,pix6,pix8,pix9);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixl(pix4,pix5,pix7,pix8,pixDelta,pixEpsilon,pixBeta,pixGama,pixEta);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixl(pix4,pix5,pix6,pix7,pix8,pix9,pixDelta,pixEpsilon,pixZeta);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixl(pix5,pix6,pix8,pix9,pixEpsilon,pixZeta);
 
                }
                 //sinon on est juste en haut
                else{
                    //sinon on est juste en haut

                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i+3][j].r;
                    pixDelta.v = img1.img[i+3][j].v;
                    pixDelta.b = img1.img[i+3][j].b;

                    pixEpsilon.r = img1.img[i+3][j+1].r;
                    pixEpsilon.v = img1.img[i+3][j+1].v;
                    pixEpsilon.b = img1.img[i+3][j+1].b;

                    pixZeta.r = img1.img[i+3][j+2].r;
                    pixZeta.v = img1.img[i+3][j+2].v;
                    pixZeta.b = img1.img[i+3][j+2].b;

                    pixEta.r = img1.img[i+3][j+3].r;
                    pixEta.v = img1.img[i+3][j+3].v;
                    pixEta.b = img1.img[i+3][j+3].b;

                    pixTheta.r = img1.img[i+3][j-1].r;
                    pixTheta.v = img1.img[i+3][j-1].v;
                    pixTheta.b = img1.img[i+3][j-1].b;

                    pixIota.r = img1.img[i+2][j-1].r;
                    pixIota.v = img1.img[i+2][j-1].v;
                    pixIota.b = img1.img[i+2][j-1].b;

                    pixKappa.r = img1.img[i+1][j-1].r;
                    pixKappa.v = img1.img[i+1][j-1].v;
                    pixKappa.b = img1.img[i+1][j-1].b;

                    pixLambda.r = img1.img[i][j-1].r;
                    pixLambda.v = img1.img[i][j-1].v;
                    pixLambda.b = img1.img[i][j-1].b;




                    //le pix1
                    imglisse.img[i][j] = moy6pixl(pix1,pix2,pix5,pix4,pixLambda,pixKappa);
                    //le pix2
                    imglisse.img[i][j+1] = moy6pixl(pix1,pix2,pix3,pix4,pix5,pix6);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixl(pix1,pix2,pix4,pix5,pix7,pix8,pixLambda,pixKappa,pixIota);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixl(pix4,pix5,pix7,pix8,pixDelta,pixEpsilon,pixKappa,pixTheta,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixl(pix4,pix5,pix6,pix7,pix8,pix9,pixDelta,pixEpsilon,pixZeta);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixl(pix5,pix6,pix8,pix9,pixGama,pixBeta,pixEpsilon,pixZeta,pixEta);
                }
            }
            
             //si on est en bas
            if (i == y - 3){

                 //si on est au bord de gauche
                if (j == 0){

                    //on definit chaque pixel actuel dans la fenetre.
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j+3].r;
                    pixEta.v = img1.img[i-1][j+3].v;
                    pixEta.b = img1.img[i-1][j+3].b;



                    //le pix1
                    imglisse.img[i][j] = moy6pixl(pix1,pix2,pix4,pix5,pixDelta,pixEpsilon);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixl(pix4,pix5,pix6,pix1,pix2,pix3,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixl(pix5,pix6,pix2,pix3,pixAlpha,pixBeta,pixEpsilon,pixZeta,pixEta);
                    //le pix4
                    imglisse.img[i+1][j] = moy6pixl(pix1,pix2,pix4,pix5,pix7,pix8);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy4pixl(pix4,pix5,pix7,pix8);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy6pixl(pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixl(pix5,pix6,pix8,pix9,pixGama,pixBeta);

                    
                }
                 //si on est au bord de droite
                if (j == x - 3){

                    //on definit chaque pixel actuel dans la fenetre.                    
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j-1].r;
                    pixEta.v = img1.img[i-1][j-1].v;
                    pixEta.b = img1.img[i-1][j-1].b;



                    //le pix1
                    imglisse.img[i][j] = moy9pixl(pix1,pix2,pix4,pix5,pixAlpha,pixBeta,pixEpsilon,pixEta,pixDelta);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixl(pix2,pix3,pix5,pix6,pixEpsilon,pixZeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixl(pix1,pix2,pix4,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy6pixl(pix2,pix3,pix5,pix6,pix8,pix9);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixl(pix4,pix5,pix7,pix8,pixBeta,pixGama);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy6pixl(pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy4pixl(pix5,pix6,pix8,pix9);                    
                }
                 //sinon on est juste en bas
                else{
                    //si on est juste en bas
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j+3].r;
                    pixEta.v = img1.img[i-1][j+3].v;
                    pixEta.b = img1.img[i-1][j+3].b;

                    pixTheta.r = img1.img[i-1][j-1].r;
                    pixTheta.v = img1.img[i-1][j-1].v;
                    pixTheta.b = img1.img[i-1][j-1].b;

                    pixIota.r = img1.img[i+2][j-1].r;
                    pixIota.v = img1.img[i+2][j-1].v;
                    pixIota.b = img1.img[i+2][j-1].b;

                    pixKappa.r = img1.img[i+1][j-1].r;
                    pixKappa.v = img1.img[i+1][j-1].v;
                    pixKappa.b = img1.img[i+1][j-1].b;

                    pixLambda.r = img1.img[i][j-1].r;
                    pixLambda.v = img1.img[i][j-1].v;
                    pixLambda.b = img1.img[i][j-1].b;




                    //le pix1
                    imglisse.img[i][j] = moy9pixl(pix1,pix2,pix5,pix4,pixLambda,pixKappa,pixTheta,pixDelta,pixEpsilon);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta,pixEpsilon,pixZeta,pixEta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixl(pix1,pix2,pix4,pix5,pix7,pix8,pixLambda,pixKappa,pixIota);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixl(pix4,pix5,pix7,pix8,pixKappa,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy6pixl(pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixl(pix5,pix6,pix8,pix9,pixGama,pixBeta);
                }
            }else{
                //si on est juste a gauche
                if (i != 0 && i != y-3 && j == 0){

                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;
            
                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j+3].r;
                    pixEta.v = img1.img[i-1][j+3].v;
                    pixEta.b = img1.img[i-1][j+3].b;

                    pixTheta.r = img1.img[i+3][j].r;
                    pixTheta.v = img1.img[i+3][j].v;
                    pixTheta.b = img1.img[i+3][j].b;

                    pixIota.r = img1.img[i+3][j+3].r;
                    pixIota.v = img1.img[i+3][j+3].v;
                    pixIota.b = img1.img[i+3][j+3].b;

                    pixKappa.r = img1.img[i+3][j+2].r;
                    pixKappa.v = img1.img[i+3][j+2].v;
                    pixKappa.b = img1.img[i+3][j+2].b;

                    pixLambda.r = img1.img[i+3][j+1].r;
                    pixLambda.v = img1.img[i+3][j+1].v;
                    pixLambda.b = img1.img[i+3][j+1].b;



                    //le pix1
                    imglisse.img[i][j] = moy6pixl(pix1,pix2,pix5,pix4,pixDelta,pixEpsilon);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta,pixEpsilon,pixZeta,pixEta);
                    //le pix4
                    imglisse.img[i+1][j] = moy6pixl(pix1,pix2,pix4,pix5,pix7,pix8);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixl(pix4,pix5,pix7,pix8,pixTheta,pixLambda);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixl(pix4,pix5,pix6,pix7,pix8,pix9,pixTheta,pixLambda,pixKappa);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixl(pix5,pix6,pix8,pix9,pixGama,pixBeta,pixLambda,pixKappa,pixIota);
                }
                //si on est juste a droite
                if(i != 0 && i != y-3 && j == x-3){

                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j-1].r;
                    pixEta.v = img1.img[i-1][j-1].v;
                    pixEta.b = img1.img[i-1][j-1].b;

                    pixTheta.r = img1.img[i+3][j].r;
                    pixTheta.v = img1.img[i+3][j].v;
                    pixTheta.b = img1.img[i+3][j].b;

                    pixIota.r = img1.img[i+3][j-1].r;
                    pixIota.v = img1.img[i+3][j-1].v;
                    pixIota.b = img1.img[i+3][j-1].b;

                    pixKappa.r = img1.img[i+3][j+2].r;
                    pixKappa.v = img1.img[i+3][j+2].v;
                    pixKappa.b = img1.img[i+3][j+2].b;

                    pixLambda.r = img1.img[i+3][j+1].r;
                    pixLambda.v = img1.img[i+3][j+1].v;
                    pixLambda.b = img1.img[i+3][j+1].b;

                    //le pix1
                    imglisse.img[i][j] = moy9pixl(pix1,pix2,pix5,pix4,pixDelta,pixEpsilon,pixAlpha,pixBeta,pixEta);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixl(pix2,pix3,pix5,pix6,pixEpsilon,pixZeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixl(pix1,pix2,pix4,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy6pixl(pix2,pix3,pix5,pix6,pix8,pix9);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixl(pix4,pix5,pix7,pix8,pixTheta,pixLambda,pixBeta,pixGama,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixl(pix4,pix5,pix6,pix7,pix8,pix9,pixTheta,pixLambda,pixKappa);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixl(pix5,pix6,pix8,pix9,pixLambda,pixKappa);

                }
                //sinon on est juste au milieu
                if(i != 0 && i != y-3 && j != 0 && j != x-3){
                    
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda,pixMu,pixNu,pixXi,pixPi,pixRho;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j-1].r;
                    pixEta.v = img1.img[i-1][j-1].v;
                    pixEta.b = img1.img[i-1][j-1].b;

                    pixTheta.r = img1.img[i+3][j].r;
                    pixTheta.v = img1.img[i+3][j].v;
                    pixTheta.b = img1.img[i+3][j].b;

                    pixIota.r = img1.img[i+3][j-1].r;
                    pixIota.v = img1.img[i+3][j-1].v;
                    pixIota.b = img1.img[i+3][j-1].b;

                    pixKappa.r = img1.img[i+3][j+2].r;
                    pixKappa.v = img1.img[i+3][j+2].v;
                    pixKappa.b = img1.img[i+3][j+2].b;

                    pixLambda.r = img1.img[i+3][j+1].r;
                    pixLambda.v = img1.img[i+3][j+1].v;
                    pixLambda.b = img1.img[i+3][j+1].b;

                    pixMu.r = img1.img[i-1][j+3].r;
                    pixMu.v = img1.img[i-1][j+3].v;
                    pixMu.b = img1.img[i-1][j+3].b;

                    pixNu.r = img1.img[i][j+3].r;
                    pixNu.v = img1.img[i][j+3].v;
                    pixNu.b = img1.img[i][j+3].b;

                    pixXi.r = img1.img[i+1][j+3].r;
                    pixXi.v = img1.img[i+1][j+3].v;
                    pixXi.b = img1.img[i+1][j+3].b;

                    pixPi.r = img1.img[i+2][j+3].r;
                    pixPi.v = img1.img[i+2][j+3].v;
                    pixPi.b = img1.img[i+2][j+3].b;

                    pixRho.r = img1.img[i+3][j+3].r;
                    pixRho.v = img1.img[i+3][j+3].v;
                    pixRho.b = img1.img[i+3][j+3].b;

                    //le pix1
                    imglisse.img[i][j] = moy9pixl(pix1,pix2,pix5,pix4,pixDelta,pixEpsilon,pixAlpha,pixBeta,pixEta);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pixEpsilon,pixZeta,pixMu,pixNu,pixXi);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixl(pix1,pix2,pix4,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixl(pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixl(pix2,pix3,pix5,pix6,pix8,pix9,pixNu,pixXi,pixPi);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixl(pix4,pix5,pix7,pix8,pixTheta,pixLambda,pixBeta,pixGama,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixl(pix4,pix5,pix6,pix7,pix8,pix9,pixTheta,pixLambda,pixKappa);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixl(pix5,pix6,pix8,pix9,pixLambda,pixKappa,pixXi,pixPi,pixRho);

                }
            }
             
        }
        
    }
    save(imglisse, newname);
    return 0;

}

//Fonction qui lisse une image avec un iveau de lissage
int lissage(char *name,char *newname, int niveau){
    lissage_aux (name,newname);
    for(int i = 0; i < niveau-1; i++){
        lissage_aux (newname,newname);
    }
}

//fonction qui renvoi un pixel avec la moyenne de 3 autres.
pixel moy4pixc (pixel pix1, pixel pix2, pixel pix3, pixel pix4){
    pixel res;

    unsigned char moyr = ((5 * pix1.r) + ((-1.33) * pix2.r) + ((-1.33) * pix3.r) + ((-1.33) * pix4.r))/4;
    unsigned char moyv = ((5 * pix1.v) + ((-1.33) * pix2.v) + ((-1.33) * pix3.v) + ((-1.33) * pix4.v))/4;
    unsigned char moyb = ((5 * pix1.b) + ((-1.33) * pix2.b) + ((-1.33) * pix3.b) + ((-1.33) * pix4.b))/4;

    int a1,b1,c1;
    a1 = moyr;
    b1 = moyv;
    c1 = moyb;

    unsigned char max,min;
    max = 255;
    min = 0;

    if(a1 >=255)
    {
        res.r = max;
    }else{
        if(a1 <= 0)
        {
            res.r = min;
        }else {res.r = moyr;}
        }

    if (b1 >=255)
    {
        res.v = max;
    }else{
        if(b1 <= 0)
        {
            res.v = min;
        }else {res.v = moyv;}
        }

    if (c1 >=255)
    {
        res.b = max;
    } else{
        if(c1 <= 0)
        {
            res.b = min;
        }else {res.b = moyb;}
        }

    return res;
}

//fonction qui renvoi un pixel avec la moyenne de 6 autres.
pixel moy6pixc (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6){
    pixel res;
    unsigned char moyr = ((5 * pix1.r) + ((-0.8) * pix2.r) + ((-0.8) * pix3.r) + ((-0.8) * pix4.r) + ((-0.8) * pix5.r) + ((-0.8) * pix6.r))/6;
    unsigned char moyv = ((5 * pix1.v) + ((-0.8) * pix2.v) + ((-0.8) * pix3.v) + ((-0.8) * pix4.v) + ((-0.8) * pix5.v) + ((-0.8) * pix6.v))/6; 
    unsigned char moyb = ((5 * pix1.b) + ((-0.8) * pix2.b) + ((-0.8) * pix3.b) + ((-0.8) * pix4.b) + ((-0.8) * pix5.b) + ((-0.8) * pix6.b))/6;

    int a1,b1,c1;
    a1 = moyr;
    b1 = moyv;
    c1 = moyb;

    unsigned char max,min;
    max = 255;
    min = 0;

    if(a1 >=255)
    {
        res.r = max;
    }else{
        if(a1 <= 0)
        {
            res.r = min;
        }else {res.r = moyr;}
        }

    if (b1 >=255)
    {
        res.v = max;
    }else{
        if(b1 <= 0)
        {
            res.v = min;
        }else {res.v = moyv;}
        }

    if (c1 >=255)
    {
        res.b = max;
    } else{
        if(c1 <= 0)
        {
            res.b = min;
        }else {res.b = moyb;}
        }

    return res;
}

//fonction qui renvoi un pixel avec la moyenne de 5 autres.
pixel moy9pixc (pixel pix1, pixel pix2, pixel pix3, pixel pix4, pixel pix5, pixel pix6, pixel pix7, pixel pix8, pixel pix9){
    pixel res;
    unsigned char moyr = ((5 * pix1.r) + ((-0.5) * pix2.r) + ((-0.5) * pix3.r) + ((-0.5) * pix4.r) + ((-0.5) * pix5.r) + ((-0.5) * pix6.r) + ((-0.5) * pix7.r) + ((-0.5) * pix8.r) + ((-0.5) * pix9.r))/9;
    unsigned char moyv = ((5 * pix1.v) + ((-0.5) * pix2.v) + ((-0.5) * pix3.v) + ((-0.5) * pix4.v) + ((-0.5) * pix5.v) + ((-0.5) * pix6.v) + ((-0.5) * pix7.v) + ((-0.5) * pix8.v) + ((-0.5) * pix9.v))/9; 
    unsigned char moyb = ((5 * pix1.b) + ((-0.5) * pix2.b) + ((-0.5) * pix3.b) + ((-0.5) * pix4.b) + ((-0.5) * pix5.b) + ((-0.5) * pix6.b) + ((-0.5) * pix7.b) + ((-0.5) * pix8.b) + ((-0.5) * pix9.b))/9;

    int a1,b1,c1;
    a1 = moyr;
    b1 = moyv;
    c1 = moyb;

    unsigned char max,min;
    max = 255;
    min = 0;

    if(a1 >=255)
    {
        res.r = max;
    }else{
        if(a1 <= 0)
        {
            res.r = min;
        }else {res.r = moyr;}
        }

    if (b1 >=255)
    {
        res.v = max;
    }else{
        if(b1 <= 0)
        {
            res.v = min;
        }else {res.v = moyv;}
        }

    if (c1 >=255)
    {
        res.b = max;
    } else{
        if(c1 <= 0)
        {
            res.b = min;
        }else {res.b = moyb;}
        }

    return res;
}

//Fonction qui fait ressortir les contours d'une image
int contours (char *name,char *newname){

    image img1 = load(name);

    int x,y;
    x = img1.sizeX;
    y = img1.sizeY;

    image imglisse;
    imglisse.sizeX = x;
    imglisse.sizeY = y;

    imglisse.img = malloc(sizeof(pixel*) * y); //on alloue de la memoire pour le tableau de sous tableaux.

    for (int i=0; i < y; i++){// le nombre de sous tableaux     
        imglisse.img[i] = malloc(sizeof(pixel) * x);//allocation pour chaque tableau dans le gros tableau.
    } 

    for( int i = 0; i < y; i +=3 ){ // on parcoure la hauteur
        for(int j = 0; j < x; j +=3){ // on parcoure la largeur

            //Fenetre:                           //debut de la fenetre suivante
                //[i]  [j] | [i]  [j+1] | [i]  [j+2] | [i]  [j+3]
                //-----------------------------------|
                //[i+1][j] | [i+1][j+1] | [i+1][j+2] | [i+1][j+3]
                //-----------------------------------|
                //[i+2][j] | [i+2][j+1] | [i+2][j+2] | [i+2][j+3]
                //- - - - - - - - - - - - - - - - - - 
                //[i+3][j] | [i+3][j+1] | [i+3][j+2] | [i+3][j+3]

                //sous la forme:
                // pix1     | pix2       | pix3    | pixAlpha
                //---------------------------------|
                // pix4     | pix5       | pix6    | pixBeta
                //---------------------------------|
                // pix7     | pix8       | pix9    | pixGama
                //- - - - - - - - - - - - - - - - - 
                // pixDelta | pixEpsilon | pixZeta | pixEta



            //si on est en haut
            if (i == 0){

                 //si on est au bord de gauche
                if (j == 0){  

                    //on definit chaque pixel actuel dans la fenetre.
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i+3][j].r;
                    pixDelta.v = img1.img[i+3][j].v;
                    pixDelta.b = img1.img[i+3][j].b;

                    pixEpsilon.r = img1.img[i+3][j+1].r;
                    pixEpsilon.v = img1.img[i+3][j+1].v;
                    pixEpsilon.b = img1.img[i+3][j+1].b;

                    pixZeta.r = img1.img[i+3][j+2].r;
                    pixZeta.v = img1.img[i+3][j+2].v;
                    pixZeta.b = img1.img[i+3][j+2].b;

                    pixEta.r = img1.img[i+3][j+3].r;
                    pixEta.v = img1.img[i+3][j+3].v;
                    pixEta.b = img1.img[i+3][j+3].b;



                    //le pix1
                    imglisse.img[i][j] = moy4pixc(pix1,pix2,pix5,pix4);
                    //le pix2
                    imglisse.img[i][j+1] = moy6pixc(pix2,pix1,pix3,pix4,pix5,pix6);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixc(pix3,pix2,pix5,pix6,pixAlpha,pixBeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy6pixc(pix4,pix2,pix1,pix5,pix7,pix8);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixc(pix6,pix3,pix5,pix2,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixc(pix7,pix5,pix4,pix8,pixDelta,pixEpsilon);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixc(pix8,pix5,pix6,pix7,pix4,pix9,pixDelta,pixEpsilon,pixZeta);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixc(pix9,pix6,pix8,pix5,pixGama,pixBeta,pixEpsilon,pixZeta,pixEta);
 
                }
                 //si on est au bord de droite
                if (j == x - 3){

                    //on definit chaque pixel actuel dans la fenetre.
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i+3][j].r;
                    pixDelta.v = img1.img[i+3][j].v;
                    pixDelta.b = img1.img[i+3][j].b;

                    pixEpsilon.r = img1.img[i+3][j+1].r;
                    pixEpsilon.v = img1.img[i+3][j+1].v;
                    pixEpsilon.b = img1.img[i+3][j+1].b;

                    pixZeta.r = img1.img[i+3][j+2].r;
                    pixZeta.v = img1.img[i+3][j+2].v;
                    pixZeta.b = img1.img[i+3][j+2].b;

                    pixEta.r = img1.img[i+3][j-1].r;
                    pixEta.v = img1.img[i+3][j-1].v;
                    pixEta.b = img1.img[i+3][j-1].b;



                    //le pix1
                    imglisse.img[i][j] = moy6pixc(pix1,pix2,pix4,pix5,pixAlpha,pixBeta);
                    //le pix2
                    imglisse.img[i][j+1] = moy6pixc(pix2,pix1,pix3,pix4,pix5,pix6);
                    //le pix3
                    imglisse.img[i][j+2] = moy4pixc(pix3,pix2,pix5,pix6);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixc(pix4,pix2,pix1,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy6pixc(pix6,pix3,pix5,pix2,pix8,pix9);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixc(pix7,pix5,pix4,pix8,pixDelta,pixEpsilon,pixBeta,pixGama,pixEta);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixc(pix8,pix5,pix6,pix7,pix4,pix9,pixDelta,pixEpsilon,pixZeta);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixc(pix9,pix6,pix8,pix5,pixEpsilon,pixZeta);
 
                }
                 //sinon on est juste en haut
                else{
                    //sinon on est juste en haut

                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i+3][j].r;
                    pixDelta.v = img1.img[i+3][j].v;
                    pixDelta.b = img1.img[i+3][j].b;

                    pixEpsilon.r = img1.img[i+3][j+1].r;
                    pixEpsilon.v = img1.img[i+3][j+1].v;
                    pixEpsilon.b = img1.img[i+3][j+1].b;

                    pixZeta.r = img1.img[i+3][j+2].r;
                    pixZeta.v = img1.img[i+3][j+2].v;
                    pixZeta.b = img1.img[i+3][j+2].b;

                    pixEta.r = img1.img[i+3][j+3].r;
                    pixEta.v = img1.img[i+3][j+3].v;
                    pixEta.b = img1.img[i+3][j+3].b;

                    pixTheta.r = img1.img[i+3][j-1].r;
                    pixTheta.v = img1.img[i+3][j-1].v;
                    pixTheta.b = img1.img[i+3][j-1].b;

                    pixIota.r = img1.img[i+2][j-1].r;
                    pixIota.v = img1.img[i+2][j-1].v;
                    pixIota.b = img1.img[i+2][j-1].b;

                    pixKappa.r = img1.img[i+1][j-1].r;
                    pixKappa.v = img1.img[i+1][j-1].v;
                    pixKappa.b = img1.img[i+1][j-1].b;

                    pixLambda.r = img1.img[i][j-1].r;
                    pixLambda.v = img1.img[i][j-1].v;
                    pixLambda.b = img1.img[i][j-1].b;




                    //le pix1
                    imglisse.img[i][j] = moy6pixc(pix1,pix2,pix5,pix4,pixLambda,pixKappa);
                    //le pix2
                    imglisse.img[i][j+1] = moy6pixc(pix2,pix1,pix3,pix4,pix5,pix6);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixc(pix3,pix2,pix5,pix6,pixAlpha,pixBeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixc(pix4,pix2,pix1,pix5,pix7,pix8,pixLambda,pixKappa,pixIota);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixc(pix6,pix3,pix5,pix2,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixc(pix7,pix5,pix4,pix8,pixDelta,pixEpsilon,pixKappa,pixTheta,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixc(pix8,pix5,pix6,pix7,pix4,pix9,pixDelta,pixEpsilon,pixZeta);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixc(pix9,pix6,pix8,pix5,pixGama,pixBeta,pixEpsilon,pixZeta,pixEta);
                }
            }
            
             //si on est en bas
            if (i == y - 3){

                 //si on est au bord de gauche
                if (j == 0){

                    //on definit chaque pixel actuel dans la fenetre.
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j+3].r;
                    pixEta.v = img1.img[i-1][j+3].v;
                    pixEta.b = img1.img[i-1][j+3].b;



                    //le pix1
                    imglisse.img[i][j] = moy6pixc(pix1,pix2,pix4,pix5,pixDelta,pixEpsilon);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixc(pix2,pix5,pix6,pix1,pix4,pix3,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixc(pix3,pix6,pix2,pix5,pixAlpha,pixBeta,pixEpsilon,pixZeta,pixEta);
                    //le pix4
                    imglisse.img[i+1][j] = moy6pixc(pix4,pix2,pix1,pix5,pix7,pix8);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixc(pix6,pix3,pix5,pix2,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy4pixc(pix7,pix5,pix4,pix8);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy6pixc(pix8,pix5,pix6,pix7,pix4,pix9);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixc(pix9,pix6,pix8,pix5,pixGama,pixBeta);

                    
                }
                 //si on est au bord de droite
                if (j == x - 3){

                    //on definit chaque pixel actuel dans la fenetre.                    
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j-1].r;
                    pixEta.v = img1.img[i-1][j-1].v;
                    pixEta.b = img1.img[i-1][j-1].b;



                    //le pix1
                    imglisse.img[i][j] = moy9pixc(pix1,pix2,pix4,pix5,pixAlpha,pixBeta,pixEpsilon,pixEta,pixDelta);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixc(pix2,pix1,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixc(pix3,pix2,pix5,pix6,pixEpsilon,pixZeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixc(pix4,pix2,pix1,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy6pixc(pix6,pix3,pix5,pix2,pix8,pix9);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixc(pix7,pix5,pix4,pix8,pixBeta,pixGama);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy6pixc(pix8,pix5,pix6,pix7,pix4,pix9);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy4pixc(pix9,pix6,pix8,pix5);                    
                }
                 //sinon on est juste en bas
                else{
                    //si on est juste en bas
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j+3].r;
                    pixEta.v = img1.img[i-1][j+3].v;
                    pixEta.b = img1.img[i-1][j+3].b;

                    pixTheta.r = img1.img[i-1][j-1].r;
                    pixTheta.v = img1.img[i-1][j-1].v;
                    pixTheta.b = img1.img[i-1][j-1].b;

                    pixIota.r = img1.img[i+2][j-1].r;
                    pixIota.v = img1.img[i+2][j-1].v;
                    pixIota.b = img1.img[i+2][j-1].b;

                    pixKappa.r = img1.img[i+1][j-1].r;
                    pixKappa.v = img1.img[i+1][j-1].v;
                    pixKappa.b = img1.img[i+1][j-1].b;

                    pixLambda.r = img1.img[i][j-1].r;
                    pixLambda.v = img1.img[i][j-1].v;
                    pixLambda.b = img1.img[i][j-1].b;




                    //le pix1
                    imglisse.img[i][j] = moy9pixc(pix1,pix2,pix5,pix4,pixLambda,pixKappa,pixTheta,pixDelta,pixEpsilon);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixc(pix2,pix1,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixc(pix3,pix2,pix5,pix6,pixAlpha,pixBeta,pixEpsilon,pixZeta,pixEta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixc(pix4,pix2,pix1,pix5,pix7,pix8,pixLambda,pixKappa,pixIota);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixc(pix6,pix3,pix5,pix2,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixc(pix7,pix5,pix4,pix8,pixKappa,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy6pixc(pix8,pix5,pix6,pix7,pix4,pix9);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixc(pix9,pix6,pix8,pix5,pixGama,pixBeta);
                }
            }else{
                //si on est juste a gauche
                if (i != 0 && i != y-3 && j == 0){

                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j+3].r;
                    pixAlpha.v = img1.img[i][j+3].v;
                    pixAlpha.b = img1.img[i][j+3].b;

                    pixBeta.r = img1.img[i+1][j+3].r;
                    pixBeta.v = img1.img[i+1][j+3].v;
                    pixBeta.b = img1.img[i+1][j+3].b;

                    pixGama.r = img1.img[i+2][j+3].r;
                    pixGama.v = img1.img[i+2][j+3].v;
                    pixGama.b = img1.img[i+2][j+3].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;
            
                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j+3].r;
                    pixEta.v = img1.img[i-1][j+3].v;
                    pixEta.b = img1.img[i-1][j+3].b;

                    pixTheta.r = img1.img[i+3][j].r;
                    pixTheta.v = img1.img[i+3][j].v;
                    pixTheta.b = img1.img[i+3][j].b;

                    pixIota.r = img1.img[i+3][j+3].r;
                    pixIota.v = img1.img[i+3][j+3].v;
                    pixIota.b = img1.img[i+3][j+3].b;

                    pixKappa.r = img1.img[i+3][j+2].r;
                    pixKappa.v = img1.img[i+3][j+2].v;
                    pixKappa.b = img1.img[i+3][j+2].b;

                    pixLambda.r = img1.img[i+3][j+1].r;
                    pixLambda.v = img1.img[i+3][j+1].v;
                    pixLambda.b = img1.img[i+3][j+1].b;



                    //le pix1
                    imglisse.img[i][j] = moy6pixc(pix1,pix2,pix5,pix4,pixDelta,pixEpsilon);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixc(pix2,pix1,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixc(pix3,pix2,pix5,pix6,pixAlpha,pixBeta,pixEpsilon,pixZeta,pixEta);
                    //le pix4
                    imglisse.img[i+1][j] = moy6pixc(pix4,pix2,pix1,pix5,pix7,pix8);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixc(pix6,pix3,pix5,pix2,pixAlpha,pixBeta,pix8,pix9,pixGama);
                    //le pix7
                    imglisse.img[i+2][j] = moy6pixc(pix7,pix5,pix4,pix8,pixTheta,pixLambda);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixc(pix8,pix5,pix6,pix7,pix4,pix9,pixTheta,pixLambda,pixKappa);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixc(pix9,pix6,pix8,pix5,pixGama,pixBeta,pixLambda,pixKappa,pixIota);
                }
                //si on est juste a droite
                if(i != 0 && i != y-3 && j == x-3){

                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j-1].r;
                    pixEta.v = img1.img[i-1][j-1].v;
                    pixEta.b = img1.img[i-1][j-1].b;

                    pixTheta.r = img1.img[i+3][j].r;
                    pixTheta.v = img1.img[i+3][j].v;
                    pixTheta.b = img1.img[i+3][j].b;

                    pixIota.r = img1.img[i+3][j-1].r;
                    pixIota.v = img1.img[i+3][j-1].v;
                    pixIota.b = img1.img[i+3][j-1].b;

                    pixKappa.r = img1.img[i+3][j+2].r;
                    pixKappa.v = img1.img[i+3][j+2].v;
                    pixKappa.b = img1.img[i+3][j+2].b;

                    pixLambda.r = img1.img[i+3][j+1].r;
                    pixLambda.v = img1.img[i+3][j+1].v;
                    pixLambda.b = img1.img[i+3][j+1].b;

                    //le pix1
                    imglisse.img[i][j] = moy9pixc(pix1,pix2,pix5,pix4,pixDelta,pixEpsilon,pixAlpha,pixBeta,pixEta);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixc(pix2,pix1,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy6pixc(pix3,pix2,pix5,pix6,pixEpsilon,pixZeta);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixc(pix4,pix2,pix1,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy6pixc(pix6,pix3,pix5,pix2,pix8,pix9);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixc(pix7,pix5,pix4,pix8,pixTheta,pixLambda,pixBeta,pixGama,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixc(pix8,pix5,pix6,pix7,pix4,pix9,pixTheta,pixLambda,pixKappa);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy6pixc(pix9,pix6,pix8,pix5,pixLambda,pixKappa);

                }
                //sinon on est juste au milieu
                if(i != 0 && i != y-3 && j != 0 && j != x-3){
                    
                    pixel pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9,pixAlpha,pixBeta,pixGama,pixDelta,pixEpsilon,pixZeta,pixEta,pixTheta,pixIota,pixKappa,pixLambda,pixMu,pixNu,pixXi,pixPi,pixRho;
                    pix1.r = img1.img[i][j].r;
                    pix1.v = img1.img[i][j].v;
                    pix1.b = img1.img[i][j].b;

                    pix2.r = img1.img[i][j+1].r;
                    pix2.v = img1.img[i][j+1].v;
                    pix2.b = img1.img[i][j+1].b;

                    pix3.r = img1.img[i][j+2].r;
                    pix3.v = img1.img[i][j+2].v;
                    pix3.b = img1.img[i][j+2].b;

                    pix4.r = img1.img[i+1][j].r;
                    pix4.v = img1.img[i+1][j].v;
                    pix4.b = img1.img[i+1][j].b;

                    pix5.r = img1.img[i+1][j+1].r;
                    pix5.v = img1.img[i+1][j+1].v;
                    pix5.b = img1.img[i+1][j+1].b;

                    pix6.r = img1.img[i+1][j+2].r;
                    pix6.v = img1.img[i+1][j+2].v;
                    pix6.b = img1.img[i+1][j+2].b;

                    pix7.r = img1.img[i+2][j].r;
                    pix7.v = img1.img[i+2][j].v;
                    pix7.b = img1.img[i+2][j].b;

                    pix8.r = img1.img[i+2][j+1].r;
                    pix8.v = img1.img[i+2][j+1].v;
                    pix8.b = img1.img[i+2][j+1].b;

                    pix9.r = img1.img[i+2][j+2].r;
                    pix9.v = img1.img[i+2][j+2].v;
                    pix9.b = img1.img[i+2][j+2].b;

                    pixAlpha.r = img1.img[i][j-1].r;
                    pixAlpha.v = img1.img[i][j-1].v;
                    pixAlpha.b = img1.img[i][j-1].b;

                    pixBeta.r = img1.img[i+1][j-1].r;
                    pixBeta.v = img1.img[i+1][j-1].v;
                    pixBeta.b = img1.img[i+1][j-1].b;

                    pixGama.r = img1.img[i+2][j-1].r;
                    pixGama.v = img1.img[i+2][j-1].v;
                    pixGama.b = img1.img[i+2][j-1].b;

                    pixDelta.r = img1.img[i-1][j].r;
                    pixDelta.v = img1.img[i-1][j].v;
                    pixDelta.b = img1.img[i-1][j].b;

                    pixEpsilon.r = img1.img[i-1][j+1].r;
                    pixEpsilon.v = img1.img[i-1][j+1].v;
                    pixEpsilon.b = img1.img[i-1][j+1].b;

                    pixZeta.r = img1.img[i-1][j+2].r;
                    pixZeta.v = img1.img[i-1][j+2].v;
                    pixZeta.b = img1.img[i-1][j+2].b;

                    pixEta.r = img1.img[i-1][j-1].r;
                    pixEta.v = img1.img[i-1][j-1].v;
                    pixEta.b = img1.img[i-1][j-1].b;

                    pixTheta.r = img1.img[i+3][j].r;
                    pixTheta.v = img1.img[i+3][j].v;
                    pixTheta.b = img1.img[i+3][j].b;

                    pixIota.r = img1.img[i+3][j-1].r;
                    pixIota.v = img1.img[i+3][j-1].v;
                    pixIota.b = img1.img[i+3][j-1].b;

                    pixKappa.r = img1.img[i+3][j+2].r;
                    pixKappa.v = img1.img[i+3][j+2].v;
                    pixKappa.b = img1.img[i+3][j+2].b;

                    pixLambda.r = img1.img[i+3][j+1].r;
                    pixLambda.v = img1.img[i+3][j+1].v;
                    pixLambda.b = img1.img[i+3][j+1].b;

                    pixMu.r = img1.img[i-1][j+3].r;
                    pixMu.v = img1.img[i-1][j+3].v;
                    pixMu.b = img1.img[i-1][j+3].b;

                    pixNu.r = img1.img[i][j+3].r;
                    pixNu.v = img1.img[i][j+3].v;
                    pixNu.b = img1.img[i][j+3].b;

                    pixXi.r = img1.img[i+1][j+3].r;
                    pixXi.v = img1.img[i+1][j+3].v;
                    pixXi.b = img1.img[i+1][j+3].b;

                    pixPi.r = img1.img[i+2][j+3].r;
                    pixPi.v = img1.img[i+2][j+3].v;
                    pixPi.b = img1.img[i+2][j+3].b;

                    pixRho.r = img1.img[i+3][j+3].r;
                    pixRho.v = img1.img[i+3][j+3].v;
                    pixRho.b = img1.img[i+3][j+3].b;

                    //le pix1
                    imglisse.img[i][j] = moy9pixc(pix1,pix2,pix5,pix4,pixDelta,pixEpsilon,pixAlpha,pixBeta,pixEta);
                    //le pix2
                    imglisse.img[i][j+1] = moy9pixc(pix2,pix1,pix3,pix4,pix5,pix6,pixDelta,pixEpsilon,pixZeta);
                    //le pix3
                    imglisse.img[i][j+2] = moy9pixc(pix3,pix2,pix5,pix6,pixEpsilon,pixZeta,pixMu,pixNu,pixXi);
                    //le pix4
                    imglisse.img[i+1][j] = moy9pixc(pix4,pix2,pix1,pix5,pix7,pix8,pixAlpha,pixBeta,pixGama);
                    //le pix5
                    imglisse.img[i+1][j+1] = moy9pixc(pix5,pix2,pix3,pix4,pix1,pix6,pix7,pix8,pix9);
                    //le pix6
                    imglisse.img[i+1][j+2] = moy9pixc(pix6,pix3,pix5,pix2,pix8,pix9,pixNu,pixXi,pixPi);
                    //le pix7
                    imglisse.img[i+2][j] = moy9pixc(pix7,pix5,pix4,pix8,pixTheta,pixLambda,pixBeta,pixGama,pixIota);
                    //le pix8
                    imglisse.img[i+2][j+1] = moy9pixc(pix8,pix5,pix6,pix7,pix4,pix9,pixTheta,pixLambda,pixKappa);
                    //le pix9
                    imglisse.img[i+2][j+2] = moy9pixc(pix9,pix6,pix8,pix5,pixLambda,pixKappa,pixXi,pixPi,pixRho);

                }
            }
             
        }
        
    }
    save(imglisse, newname);
    return 0;

}



