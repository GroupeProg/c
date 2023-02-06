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
    printf("%s", inutile);
    fscanf(fichier, "%d %d",&x,&y);
    printf("%d %d", x, y);
    int l=ftell(fichier);
    fseek(fichier, l+2, SEEK_SET);
    fgets(inutile, 100, fichier);
    printf("\n%s", inutile);
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

image changetosepia(image img)
{
    int x=img.sizeX;
    int y=img.sizeY;
    for(int a=0; a<y; a++)
    {
        for(int b=0; b<x; b++)
        {
            unsigned char ar=img.img[a][b].r, ab=img.img[a][b].b, av=img.img[a][b].v;
            img.img[a][b].r=ar+20;
            img.img[a][b].b=ab-10;
            img.img[a][b].v=av-10;
        }
    }
    return img;
}
