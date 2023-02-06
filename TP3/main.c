#include <stdio.h>
#include <stdlib.h>
#include "TP3.h"
#include "tableau.h"
#include "miniprojet_images.h"

int main()
{
    FILE *i, *ii;
    i="maison.ppm"; ii="image2.ppm";/*
    int l=ftell(i);
    printf("%d", l);
    /*fseek(i, 7, SEEK_SET);
    char chaine[100];
    fgets(chaine, 100, i);
    l=ftell(i);
    printf("%d", l);
    printf("%s", chaine);
    fclose(i);*/
    image img1;
    img1=load(i);
    image img2=changetogrey(img1);
    img2=changetosepia(img2);
    save(img2, ii);
}
