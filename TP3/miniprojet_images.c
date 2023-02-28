#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "miniprojet_images.h"
pixel init_pix()
{
    srand(time(NULL));
    pixel pix;
    pix.r=rand() %256;
    pix.v=rand() %256;
    pix.b=rand() %256;
    return pix;
}

image init_image(int x, int y)
{
    image img1;
    img1.img=malloc(sizeof(pixel*)*y);

    for(int i=0; i<y; i++)
    {
        img1.img[i]=malloc(sizeof(pixel)*x);
    }
    img1.sizeX=x;
    img1.sizeY=y;
    pixel pix;
    for(int i=0; i<y;i++)
    {
        for(int y=0; y<x;y++)
        {
            pix=init_pix();
            img1.img[i][y]=pix;
        }
    }
    return img1;
}

void save(image img, char *f){
    int X=img.sizeX;
    int Y=img.sizeY;

    FILE *fichier=NULL;
    fichier=fopen(f, "w");
    fprintf(fichier,"P3\n%d %d\n255\n",X,Y);

    if(fichier!=NULL)
    {
        for(int i=0; i<Y;i++)
        {
            for(int y=0; y<X;y++)
            {
                unsigned char rouge=img.img[i][y].r;
                unsigned char vert=img.img[i][y].v;
                unsigned char bleu=img.img[i][y].b;
                fprintf(fichier, "%3d %3d %3d\n",rouge,vert,bleu);
            }
            fprintf(fichier,"\n");
        }
        fclose(fichier);
    }else printf("le pointeur est nul");
}

image load(char *i)
{
    char inutile[20];
    int x, y;
    FILE *fichier;
    fichier=fopen(i, "r");
    fgets(inutile, 100, fichier);
    fscanf(fichier, "%d %d",&x,&y);
    int l=ftell(fichier);
    fseek(fichier, l+2, SEEK_SET);
    fgets(inutile, 100, fichier);
    image img1=init_image(x,y);

    int ar, av, ab;

    for(int i=0; i<y; i++)
    {
        for(int a=0; a<x; a++)
        {
            fscanf(fichier, "%d %d %d", &ar, &av, &ab);
            img1.img[i][a].r=ar;
            img1.img[i][a].v=av;
            img1.img[i][a].b=ab;
        }
    }

    fclose(fichier);
    return img1;
}


image changetored(image img)
{
    int x=img.sizeX;
    int y=img.sizeY;
    for(int a=0; a<y; a++)
    {
        for(int b=0; b<x; b++)
        {
            img.img[a][b].b=0;
            img.img[a][b].v=0;
        }
    }
    return img;
}
image changetoblue(image img)
{
    int x=img.sizeX;
    int y=img.sizeY;
    for(int a=0; a<y; a++)
    {
        for(int b=0; b<x; b++)
        {
            img.img[a][b].r=0;
            img.img[a][b].v=0;
        }
    }
    return img;
}

image changetogreen(image img)
{
    int x=img.sizeX;
    int y=img.sizeY;
    for(int a=0; a<y; a++)
    {
        for(int b=0; b<x; b++)
        {
            img.img[a][b].b=0;
            img.img[a][b].r=0;
        }
    }
    return img;
}

image changetogrey(image img)
{
    int x=img.sizeX;
    int y=img.sizeY;
    for(int a=0; a<y; a++)
    {
        for(int b=0; b<x; b++)
        {
            unsigned char ar=img.img[a][b].r, ab=img.img[a][b].b, av=img.img[a][b].v;
            unsigned char moyenne=(ar+ab+av)/3;
            img.img[a][b].r=moyenne;
            img.img[a][b].b=moyenne;
            img.img[a][b].v=moyenne;
        }
    }
    return img;
}

image changetogreymax(image img)
{
    int x=img.sizeX;
    int y=img.sizeY;
    for(int a=0; a<y; a++)
    {
        for(int b=0; b<x; b++)
        {
            unsigned char ar=img.img[a][b].r, ab=img.img[a][b].b, av=img.img[a][b].v;
            unsigned char res;
            if(ar>=ab)
            {
                if(ar>av)
                {
                    res=ar;
                }else res=av;
            } else if(ab>av){
                res=ab;
            }else res=av;

            img.img[a][b].r=res;
            img.img[a][b].b=res;
            img.img[a][b].v=res;
        }
    }
    return img;
}

image changetosepia(image img1)
{
    int x=img1.sizeX;
    int y=img1.sizeY;
    for(int a=0; a<y; a++)
    {
        for(int k=0; k<x; k++)
        {
            int ar, ab, av;
            ar=img1.img[a][k].r;
            ab=img1.img[a][k].b;
            av=img1.img[a][k].v;
            int r, v, b;
            r=((ar*0.393)+(av*0.769)+(ab*0.189));
            v=((ar*0.349)+(av*0.686)+(ab*0.168));
            b=((ar*0.272)+(av*0.534)+(ab*0.131));
            printf("%d %d %d", r, v,b);
            unsigned char rr, vv,bb;
            rr=r;
            vv=v;
            bb=b;
            if(r>255)
            {
                img1.img[a][k].r=255;
            }else {img1.img[a][k].r=rr;}

            if(v>255)
            {
                img1.img[a][k].v=255;
            }else {img1.img[a][k].v=vv;}

            if(b>255)
            {
                img1.img[a][k].b=255;
            }else {img1.img[a][k].b=bb;}
        }
    }
    return img1;
}
image lissageangles(image img, image res)
{
    int x=img.sizeX;
    int y=img.sizeY;

    for(int i=0; i<y; y++)
    {
        for(int j=0; j<x; j++)
        {
            //partie qui gère l'angle gauche
            if(i==0 && j==0)
            {

            }else if(i==0 && j==x-1) //gère l'angle droit
            {
                int r,v,b,r1,v1,b1,r2,v2,b2,r3,v3,b3;
                r=img.img[i][j-1].r;
                v=img.img[i][j-1].v;
                b=img.img[i][j-1].b;

                r1=img.img[i][j].r;
                v1=img.img[i][j].v;
                b1=img.img[i][j].b;

                r2=img.img[i+1][j-1].r;
                v2=img.img[i+1][j-1].v;
                b2=img.img[i+1][j-1].b;

                r3=img.img[i+1][j].r;
                v3=img.img[i+1][j].v;
                b3=img.img[i+1][j].b;

                int moy1, moy2, moy3;
                moy1=(r+r1+r2+r3)/4;
                moy2=(v+v1+v2+v3)/4;
                moy3=(b+b1+b2+b3)/4;

                unsigned char nouvr, nouvv, nouvb;
                nouvr=moy1;
                nouvv=moy2;
                nouvb=moy3;

                res.img[i][j].r=nouvr;
                res.img[i][j].v=nouvv;
                res.img[i][j].b=nouvb;
            }else if (i==y-1 && j==0)// gere l'angle en bas à gauche
            {
                int r,v,b,r1,v1,b1,r2,v2,b2,r3,v3,b3;
                r=img.img[i][j].r;
                v=img.img[i][j].v;
                b=img.img[i][j].b;

                r1=img.img[i][j+1].r;
                v1=img.img[i][j+1].v;
                b1=img.img[i][j+1].b;

                r2=img.img[i-1][j].r;
                v2=img.img[i-1][j].v;
                b2=img.img[i-1][j].b;

                r3=img.img[i-1][j+1].r;
                v3=img.img[i-1][j+1].v;
                b3=img.img[i-1][j+1].b;

                int moy1, moy2, moy3;
                moy1=(r+r1+r2+r3)/4;
                moy2=(v+v1+v2+v3)/4;
                moy3=(b+b1+b2+b3)/4;

                unsigned char nouvr, nouvv, nouvb;
                nouvr=moy1;
                nouvv=moy2;
                nouvb=moy3;

                res.img[i][j].r=nouvr;
                res.img[i][j].v=nouvv;
                res.img[i][j].b=nouvb;
            } else if(i==y-1 && j==x-1)// gère l'angle en bas à droite
            {
                int r,v,b,r1,v1,b1,r2,v2,b2,r3,v3,b3;
                r=img.img[i][j-1].r;
                v=img.img[i][j-1].v;
                b=img.img[i][j-1].b;

                r1=img.img[i][j].r;
                v1=img.img[i][j].v;
                b1=img.img[i][j].b;

                r2=img.img[i-1][j-1].r;
                v2=img.img[i-1][j-1].v;
                b2=img.img[i-1][j-1].b;

                r3=img.img[i-1][j].r;
                v3=img.img[i-1][j].v;
                b3=img.img[i-1][j].b;

                int moy1, moy2, moy3;
                moy1=(r+r1+r2+r3)/4;
                moy2=(v+v1+v2+v3)/4;
                moy3=(b+b1+b2+b3)/4;

                unsigned char nouvr, nouvv, nouvb;
                nouvr=moy1;
                nouvv=moy2;
                nouvb=moy3;

                res.img[i][j].r=nouvr;
                res.img[i][j].v=nouvv;
                res.img[i][j].b=nouvb;
            }

        }
    }
    return res;
}


image contour(image img)
{
    int x=img.sizeX;//on recupère la taille x et y de l'image
    int y=img.sizeY;

    image res=init_image(x,y); //créé une deuxième image au même dimension pour créer la nouvelle image modifiée
    //partie pour les angles

    //angle haut gauche
    int r,v,b,r1,v1,b1,r2,v2,b2,r3,v3,b3;
    r=img.img[0][0].r;
    v=img.img[0][0].v;
    b=img.img[0][0].b;

    r1=img.img[0][1].r;
    v1=img.img[0][1].v;
    b1=img.img[0][1].b;

    r2=img.img[1][0].r;
    v2=img.img[1][0].v;
    b2=img.img[1][0].b;

    r3=img.img[1][1].r;
    v3=img.img[1][1].v;
    b3=img.img[1][1].b;

    int moy1, moy2, moy3;
    moy1=(5*r+(-1.33*r1)+(-1.33*r2)+(r3*-1.33))/4;
    moy2=(5*v+(-1.33*v1)+(-1.33*v2)+(-1.33*v3))/4;
    moy3=((5*b)+(-1.33*b1)+(-1.33*b2)+(-1.33*b3))/4;

    unsigned char nouvr, nouvv, nouvb;
    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[0][0].r=nouvr;
    res.img[0][0].v=nouvv;
    res.img[0][0].b=nouvb;

    //angle haut droite
    r=img.img[0][x-1].r;
    v=img.img[0][x-1].v;
    b=img.img[0][x-1].b;

    r1=img.img[0][x-2].r;
    v1=img.img[0][x-2].v;
    b1=img.img[0][x-2].b;

    r2=img.img[1][x-1].r;
    v2=img.img[1][x-1].v;
    b2=img.img[1][x-1].b;

    r3=img.img[1][x-2].r;
    v3=img.img[1][x-2].v;
    b3=img.img[1][x-2].b;

    moy1=(5*r+(-1.33*r1)+(-1.33*r2)+(r3*-1.33))/4;
    moy2=(5*v+(-1.33*v1)+(-1.33*v2)+(-1.33*v3))/4;
    moy3=((5*b)+(-1.33*b1)+(-1.33*b2)+(-1.33*b3))/4;

    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[0][x-1].r=nouvr;
    res.img[0][x-1].v=nouvv;
    res.img[0][x-1].b=nouvb;

    //angle bas gauche
    r=img.img[y-2][0].r;
    v=img.img[y-2][0].v;
    b=img.img[y-2][0].b;

    r1=img.img[y-2][1].r;
    v1=img.img[y-2][1].v;
    b1=img.img[y-2][1].b;

    r2=img.img[y-1][0].r;
    v2=img.img[y-1][0].v;
    b2=img.img[y-1][0].b;

    r3=img.img[y-1][1].r;
    v3=img.img[y-1][1].v;
    b3=img.img[y-1][1].b;

    moy1=(-1.33*r+(-1.33*r1)+(5*r2)+(r3*-1.33))/4;
    moy2=(1.33*v+(-1.33*v1)+(5*v2)+(-1.33*v3))/4;
    moy3=((-1.33*b)+(-1.33*b1)+(5*b2)+(-1.33*b3))/4;

    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[y-1][0].r=nouvr;
    res.img[y-1][0].v=nouvv;
    res.img[y-1][0].b=nouvb;

    //angle bas droite

    r=img.img[y-1][x-1].r;
    v=img.img[y-1][x-1].v;
    b=img.img[y-1][x-1].b;

    r1=img.img[y-1][x-2].r;
    v1=img.img[y-1][x-2].v;
    b1=img.img[y-1][x-2].b;

    r2=img.img[y-2][x-1].r;
    v2=img.img[y-2][x-1].v;
    b2=img.img[y-2][x-1].b;

    r3=img.img[y-2][x-2].r;
    v3=img.img[y-2][x-2].v;
    b3=img.img[y-2][x-2].b;

    moy1=(5*r+(-1.33*r1)+(-1.33*r2)+(r3*-1.33))/4;
    moy2=(5*v+(-1.33*v1)+(-1.33*v2)+(-1.33*v3))/4;
    moy3=((5*b)+(-1.33*b1)+(-1.33*b2)+(-1.33*b3))/4;

    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[y-1][x-1].r=nouvr;
    res.img[y-1][x-1].v=nouvv;
    res.img[y-1][x-1].b=nouvb;


    //boucle pour faire la ligne du haut

    for(int j=1; j<x-1; j++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[0][j-1].r;
            pix1v=img.img[0][j-1].v;
            pix1b=img.img[0][j-1].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[0][j].r;
            pix2v=img.img[0][j].v;
            pix2b=img.img[0][j].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[0][j+1].r;
            pix3v=img.img[0][j+1].v;
            pix3b=img.img[0][j+1].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[1][j-1].r;
            pix4v=img.img[1][j-1].v;
            pix4b=img.img[1][j-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[1][j].r;
            pix5v=img.img[1][j].v;
            pix5b=img.img[1][j].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[1][j+1].r;
            pix6v=img.img[1][j+1].v;
            pix6b=img.img[1][j+1].b;

            int moyr, moyv, moyb;
            moyr=(-0.8*pix1r+(5*pix2r)+(-0.8*pix3r)+(-0.8*pix4r)+(-0.8*pix5r)+(-0.8*pix6r))/6;
            moyv=(-0.8*pix1v+(5*pix2v)+(-0.8*pix3v)+(-0.8*pix4v)+(-0.8*pix5v)+(-0.8*pix6v))/6;
            moyb=(-0.8*pix1b+(5*pix2b)+(-0.8*pix3b)+(-0.8*pix4b)+(-0.8*pix5b)+(-0.8*pix6b))/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[0][j].r=nr;
            res.img[0][j].v=nv;
            res.img[0][j].b=nb;
        }

    //boucle pour faire la ligne du bas

    for(int j=1; j<x-1; j++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[x-1][j-1].r;
            pix1v=img.img[x-1][j-1].v;
            pix1b=img.img[x-1][j-1].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[x-1][j].r;
            pix2v=img.img[x-1][j].v;
            pix2b=img.img[x-1][j].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[x-1][j+1].r;
            pix3v=img.img[x-1][j+1].v;
            pix3b=img.img[x-1][j+1].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[x-2][j-1].r;
            pix4v=img.img[x-2][j-1].v;
            pix4b=img.img[x-2][j-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[x-2][j].r;
            pix5v=img.img[x-2][j].v;
            pix5b=img.img[x-2][j].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[x-2][j+1].r;
            pix6v=img.img[x-2][j+1].v;
            pix6b=img.img[x-2][j+1].b;

            int moyr, moyv, moyb;
             moyr=(-0.8*pix1r+(5*pix2r)+(-0.8*pix3r)+(-0.8*pix4r)+(-0.8*pix5r)+(-0.8*pix6r))/6;
            moyv=(-0.8*pix1v+(5*pix2v)+(-0.8*pix3v)+(-0.8*pix4v)+(-0.8*pix5v)+(-0.8*pix6v))/6;
            moyb=(-0.8*pix1b+(5*pix2b)+(-0.8*pix3b)+(-0.8*pix4b)+(-0.8*pix5b)+(-0.8*pix6b))/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[x-1][j].r=nr;
            res.img[x-1][j].v=nv;
            res.img[x-1][j].b=nb;
        }

    //boucle qui gère la ligne de gauche
    for(int i=1; i<y-1; i++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[i-1][0].r;
            pix1v=img.img[i-1][0].v;
            pix1b=img.img[i-1][0].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[i][0].r;
            pix2v=img.img[i][0].v;
            pix2b=img.img[i][0].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[i+1][0].r;
            pix3v=img.img[i+1][0].v;
            pix3b=img.img[i+1][0].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[i-1][1].r;
            pix4v=img.img[i-1][1].v;
            pix4b=img.img[i-1][1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[i][1].r;
            pix5v=img.img[i][1].v;
            pix5b=img.img[i][1].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[i+1][1].r;
            pix6v=img.img[i+1][1].v;
            pix6b=img.img[i+1][1].b;

            int moyr, moyv, moyb;
             moyr=(-0.8*pix1r+(5*pix2r)+(-0.8*pix3r)+(-0.8*pix4r)+(-0.8*pix5r)+(-0.8*pix6r))/6;
            moyv=(-0.8*pix1v+(5*pix2v)+(-0.8*pix3v)+(-0.8*pix4v)+(-0.8*pix5v)+(-0.8*pix6v))/6;
            moyb=(-0.8*pix1b+(5*pix2b)+(-0.8*pix3b)+(-0.8*pix4b)+(-0.8*pix5b)+(-0.8*pix6b))/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[i][0].r=nr;
            res.img[i][0].v=nv;
            res.img[i][0].b=nb;
        }

    //boucle qui gère la ligne de droite
    for(int i=1; i<y-1; i++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[i-1][x-2].r;
            pix1v=img.img[i-1][x-2].v;
            pix1b=img.img[i-1][x-2].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[i][x-2].r;
            pix2v=img.img[i][x-2].v;
            pix2b=img.img[i][x-2].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[i+1][x-2].r;
            pix3v=img.img[i+1][x-2].v;
            pix3b=img.img[i+1][x-2].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[i-1][x-1].r;
            pix4v=img.img[i-1][x-1].v;
            pix4b=img.img[i-1][x-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[i][x-1].r;
            pix5v=img.img[i][x-1].v;
            pix5b=img.img[i][x-1].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[i+1][x-1].r;
            pix6v=img.img[i+1][x-1].v;
            pix6b=img.img[i+1][x-1].b;

            int moyr, moyv, moyb;
            moyr=(-0.8*pix1r+(-0.8*pix2r)+(-0.8*pix3r)+(-0.8*pix4r)+(5*pix5r)+(-0.8*pix6r))/6;
            moyv=(-0.8*pix1v+(-0.8*pix2v)+(-0.8*pix3v)+(-0.8*pix4v)+(5*pix5v)+(-0.8*pix6v))/6;
            moyb=(-0.8*pix1b+(-0.8*pix2b)+(-0.8*pix3b)+(-0.8*pix4b)+(5*pix5b)+(-0.8*pix6b))/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[i][x-1].r=nr;
            res.img[i][x-1].v=nv;
            res.img[i][x-1].b=nb;
        }


    //boucle qui gère l'intérieur de l'image
    for(int i=1; i<y-1; i++)
    {
        for(int j=1; j<x-1; j++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[i-1][j-1].r;
            pix1v=img.img[i-1][j-1].v;
            pix1b=img.img[i-1][j-1].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[i-1][j].r;
            pix2v=img.img[i-1][j].v;
            pix2b=img.img[i-1][j].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[i-1][j+1].r;
            pix3v=img.img[i-1][j+1].v;
            pix3b=img.img[i-1][j+1].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[i][j-1].r;
            pix4v=img.img[i][j-1].v;
            pix4b=img.img[i][j-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[i][j].r;
            pix5v=img.img[i][j].v;
            pix5b=img.img[i][j].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[i][j+1].r;
            pix6v=img.img[i][j+1].v;
            pix6b=img.img[i][j+1].b;

            int pix7r, pix7v, pix7b;
            pix7r=img.img[i+1][j-1].r;
            pix7v=img.img[i+1][j-1].v;
            pix7b=img.img[i+1][j-1].b;

            int pix8r, pix8v, pix8b;
            pix8r=img.img[i+1][j].r;
            pix8v=img.img[i+1][j].v;
            pix8b=img.img[i+1][j].b;

            int pix9r, pix9v, pix9b;
            pix9r=img.img[i+1][j+1].r;
            pix9v=img.img[i+1][j+1].v;
            pix9b=img.img[i+1][j+1].b;

            int moyr, moyv, moyb;
            moyr=(-0.5*pix1r+(-0.5*pix2r)+(-0.5*pix3r)+(-0.5*pix4r)+(5*pix5r)+(-0.5*pix6r)+(-0.5*pix7r)+(-0.5*pix8r)+(-0.5*pix9r))/9;
            moyv=(-0.5*pix1v+(-0.5*pix2v)+(-0.5*pix3v)+(-0.5*pix4v)+(5*pix5v)+(-0.5*pix6v)+(-0.5*pix7v)+(-0.5*pix8v)+(-0.5*pix9v))/9;
            moyb=(-0.5*pix1b+(-0.5*pix2b)+(-0.5*pix3b)+(-0.5*pix4b)+(5*pix5b)+(-0.5*pix6b)+(-0.5*pix7b)+(-0.5*pix8b)+(-0.5*pix9b))/9;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[i][j].r=nr;
            res.img[i][j].v=nv;
            res.img[i][j].b=nb;
        }

    }
    return res;
}


image lissage(image img)
{
    int x=img.sizeX;//on recupère la taille x et y de l'image
    int y=img.sizeY;

    image res=init_image(x,y); //créé une deuxième image au même dimension pour créer la nouvelle image modifiée
    //partie pour les angles

    //angle haut gauche
    int r,v,b,r1,v1,b1,r2,v2,b2,r3,v3,b3;
    r=img.img[0][0].r;
    v=img.img[0][0].v;
    b=img.img[0][0].b;

    r1=img.img[0][1].r;
    v1=img.img[0][1].v;
    b1=img.img[0][1].b;

    r2=img.img[1][0].r;
    v2=img.img[1][0].v;
    b2=img.img[1][0].b;

    r3=img.img[1][1].r;
    v3=img.img[1][1].v;
    b3=img.img[1][1].b;

    int moy1, moy2, moy3;
    moy1=(r+r1+r2+r3)/4;
    moy2=(v+v1+v2+v3)/4;
    moy3=(b+b1+b2+b3)/4;

    unsigned char nouvr, nouvv, nouvb;
    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[0][0].r=nouvr;
    res.img[0][0].v=nouvv;
    res.img[0][0].b=nouvb;

    //angle haut droite
    r=img.img[0][x-1].r;
    v=img.img[0][x-1].v;
    b=img.img[0][x-1].b;

    r1=img.img[0][x-2].r;
    v1=img.img[0][x-2].v;
    b1=img.img[0][x-2].b;

    r2=img.img[1][x-1].r;
    v2=img.img[1][x-1].v;
    b2=img.img[1][x-1].b;

    r3=img.img[1][x-2].r;
    v3=img.img[1][x-2].v;
    b3=img.img[1][x-2].b;

    moy1=(r+r1+r2+r3)/4;
    moy2=(v+v1+v2+v3)/4;
    moy3=(b+b1+b2+b3)/4;

    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[0][x-1].r=nouvr;
    res.img[0][x-1].v=nouvv;
    res.img[0][x-1].b=nouvb;

    //angle bas gauche
    r=img.img[y-2][0].r;
    v=img.img[y-2][0].v;
    b=img.img[y-2][0].b;

    r1=img.img[y-2][1].r;
    v1=img.img[y-2][1].v;
    b1=img.img[y-2][1].b;

    r2=img.img[y-1][0].r;
    v2=img.img[y-1][0].v;
    b2=img.img[y-1][0].b;

    r3=img.img[y-1][1].r;
    v3=img.img[y-1][1].v;
    b3=img.img[y-1][1].b;

    moy1=(r+r1+r2+r3)/4;
    moy2=(v+v1+v2+v3)/4;
    moy3=(b+b1+b2+b3)/4;

    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[y-1][0].r=nouvr;
    res.img[y-1][0].v=nouvv;
    res.img[y-1][0].b=nouvb;

    //angle bas droite

    r=img.img[y-1][x-1].r;
    v=img.img[y-1][x-1].v;
    b=img.img[y-1][x-1].b;

    r1=img.img[y-1][x-2].r;
    v1=img.img[y-1][x-2].v;
    b1=img.img[y-1][x-2].b;

    r2=img.img[y-2][x-1].r;
    v2=img.img[y-2][x-1].v;
    b2=img.img[y-2][x-1].b;

    r3=img.img[y-2][x-2].r;
    v3=img.img[y-2][x-2].v;
    b3=img.img[y-2][x-2].b;

    moy1=(r+r1+r2+r3)/4;
    moy2=(v+v1+v2+v3)/4;
    moy3=(b+b1+b2+b3)/4;

    nouvr=moy1;
    nouvv=moy2;
    nouvb=moy3;

    res.img[y-1][x-1].r=nouvr;
    res.img[y-1][x-1].v=nouvv;
    res.img[y-1][x-1].b=nouvb;


    //boucle pour faire la ligne du haut

    for(int j=1; j<x-1; j++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[0][j-1].r;
            pix1v=img.img[0][j-1].v;
            pix1b=img.img[0][j-1].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[0][j].r;
            pix2v=img.img[0][j].v;
            pix2b=img.img[0][j].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[0][j+1].r;
            pix3v=img.img[0][j+1].v;
            pix3b=img.img[0][j+1].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[1][j-1].r;
            pix4v=img.img[1][j-1].v;
            pix4b=img.img[1][j-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[1][j].r;
            pix5v=img.img[1][j].v;
            pix5b=img.img[1][j].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[1][j+1].r;
            pix6v=img.img[1][j+1].v;
            pix6b=img.img[1][j+1].b;

            int moyr, moyv, moyb;
            moyr=(pix1r+pix2r+pix3r+pix4r+pix5r+pix6r)/6;
            moyv=(pix1v+pix2v+pix3v+pix4v+pix5v+pix6v)/6;
            moyb=(pix1b+pix2b+pix3b+pix4b+pix5b+pix6b)/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[0][j].r=nr;
            res.img[0][j].v=nv;
            res.img[0][j].b=nb;
        }

    //boucle pour faire la ligne du bas

    for(int j=1; j<x-1; j++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[x-1][j-1].r;
            pix1v=img.img[x-1][j-1].v;
            pix1b=img.img[x-1][j-1].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[x-1][j].r;
            pix2v=img.img[x-1][j].v;
            pix2b=img.img[x-1][j].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[x-1][j+1].r;
            pix3v=img.img[x-1][j+1].v;
            pix3b=img.img[x-1][j+1].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[x-2][j-1].r;
            pix4v=img.img[x-2][j-1].v;
            pix4b=img.img[x-2][j-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[x-2][j].r;
            pix5v=img.img[x-2][j].v;
            pix5b=img.img[x-2][j].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[x-2][j+1].r;
            pix6v=img.img[x-2][j+1].v;
            pix6b=img.img[x-2][j+1].b;

            int moyr, moyv, moyb;
            moyr=(pix1r+pix2r+pix3r+pix4r+pix5r+pix6r)/6;
            moyv=(pix1v+pix2v+pix3v+pix4v+pix5v+pix6v)/6;
            moyb=(pix1b+pix2b+pix3b+pix4b+pix5b+pix6b)/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[x-1][j].r=nr;
            res.img[x-1][j].v=nv;
            res.img[x-1][j].b=nb;
        }

    //boucle qui gère la ligne de gauche
    for(int i=1; i<y-1; i++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[i-1][0].r;
            pix1v=img.img[i-1][0].v;
            pix1b=img.img[i-1][0].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[i][0].r;
            pix2v=img.img[i][0].v;
            pix2b=img.img[i][0].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[i+1][0].r;
            pix3v=img.img[i+1][0].v;
            pix3b=img.img[i+1][0].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[i-1][1].r;
            pix4v=img.img[i-1][1].v;
            pix4b=img.img[i-1][1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[i][1].r;
            pix5v=img.img[i][1].v;
            pix5b=img.img[i][1].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[i+1][1].r;
            pix6v=img.img[i+1][1].v;
            pix6b=img.img[i+1][1].b;

            int moyr, moyv, moyb;
            moyr=(pix1r+pix2r+pix3r+pix4r+pix5r+pix6r)/6;
            moyv=(pix1v+pix2v+pix3v+pix4v+pix5v+pix6v)/6;
            moyb=(pix1b+pix2b+pix3b+pix4b+pix5b+pix6b)/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[i][0].r=nr;
            res.img[i][0].v=nv;
            res.img[i][0].b=nb;
        }

    //boucle qui gère la ligne de droite
    for(int i=1; i<y-1; i++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[i-1][x-2].r;
            pix1v=img.img[i-1][x-2].v;
            pix1b=img.img[i-1][x-2].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[i][x-2].r;
            pix2v=img.img[i][x-2].v;
            pix2b=img.img[i][x-2].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[i+1][x-2].r;
            pix3v=img.img[i+1][x-2].v;
            pix3b=img.img[i+1][x-2].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[i-1][x-1].r;
            pix4v=img.img[i-1][x-1].v;
            pix4b=img.img[i-1][x-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[i][x-1].r;
            pix5v=img.img[i][x-1].v;
            pix5b=img.img[i][x-1].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[i+1][x-1].r;
            pix6v=img.img[i+1][x-1].v;
            pix6b=img.img[i+1][x-1].b;

            int moyr, moyv, moyb;
            moyr=(pix1r+pix2r+pix3r+pix4r+pix5r+pix6r)/6;
            moyv=(pix1v+pix2v+pix3v+pix4v+pix5v+pix6v)/6;
            moyb=(pix1b+pix2b+pix3b+pix4b+pix5b+pix6b)/6;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[i][x-1].r=nr;
            res.img[i][x-1].v=nv;
            res.img[i][x-1].b=nb;
        }


    //boucle qui gère l'intérieur de l'image
    for(int i=1; i<y-1; i++)
    {
        for(int j=1; j<x-1; j++)
        {
            int pix1r, pix1v, pix1b;
            pix1r=img.img[i-1][j-1].r;
            pix1v=img.img[i-1][j-1].v;
            pix1b=img.img[i-1][j-1].b;

            int pix2r, pix2v, pix2b;
            pix2r=img.img[i-1][j].r;
            pix2v=img.img[i-1][j].v;
            pix2b=img.img[i-1][j].b;

            int pix3r, pix3v, pix3b;
            pix3r=img.img[i-1][j+1].r;
            pix3v=img.img[i-1][j+1].v;
            pix3b=img.img[i-1][j+1].b;

            int pix4r, pix4v, pix4b;
            pix4r=img.img[i][j-1].r;
            pix4v=img.img[i][j-1].v;
            pix4b=img.img[i][j-1].b;

            int pix5r, pix5v, pix5b;
            pix5r=img.img[i][j].r;
            pix5v=img.img[i][j].v;
            pix5b=img.img[i][j].b;

            int pix6r, pix6v, pix6b;
            pix6r=img.img[i][j+1].r;
            pix6v=img.img[i][j+1].v;
            pix6b=img.img[i][j+1].b;

            int pix7r, pix7v, pix7b;
            pix7r=img.img[i+1][j-1].r;
            pix7v=img.img[i+1][j-1].v;
            pix7b=img.img[i+1][j-1].b;

            int pix8r, pix8v, pix8b;
            pix8r=img.img[i+1][j].r;
            pix8v=img.img[i+1][j].v;
            pix8b=img.img[i+1][j].b;

            int pix9r, pix9v, pix9b;
            pix9r=img.img[i+1][j+1].r;
            pix9v=img.img[i+1][j+1].v;
            pix9b=img.img[i+1][j+1].b;

            int moyr, moyv, moyb;
            moyr=(pix1r+pix2r+pix3r+pix4r+pix5r+pix6r+pix7r+pix8r+pix9r)/9;
            moyv=(pix1v+pix2v+pix3v+pix4v+pix5v+pix6v+pix7v+pix8v+pix9v)/9;
            moyb=(pix1b+pix2b+pix3b+pix4b+pix5b+pix6b+pix7b+pix8b+pix9b)/9;

            unsigned char nr, nv, nb;
            nr=moyr;
            nv=moyv;
            nb=moyb;

            res.img[i][j].r=nr;
            res.img[i][j].v=nv;
            res.img[i][j].b=nb;
        }

    }
    return res;
}
