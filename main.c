#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "mini_projet_kaez\image.h"
#include "sources/tp2.h"

int main(){
    
    //image randimage = init_image(2,2);
    //save (randimage, "mini_projet_kaez/img.ppm");

    //image imageloaded = load("mini_projet_kaez/img.ppm");
    //save(imageloaded, "mini_projet_kaez/img2.ppm");

    //sepia("mini_projet_kaez/House.256original.ppm","mini_projet_kaez/House.256sepia.ppm");
    int tab[10] = {3,6,3,7,9,9,4,4};
    printf("%d", minOfTab(tab, 8));

    return 0;
}
