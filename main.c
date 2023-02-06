#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "mini_projet_kaez\image.h"
#include "sources/tp2.h"

int main(){
    
    image randimage = init_image(9,9);
    save (randimage, "mini_projet_kaez/test.ppm");

    //image imageloaded = load("mini_projet_kaez/img.ppm");
    //save(imageloaded, "mini_projet_kaez/img2.ppm");

    contours("mini_projet_kaez/test.ppm","mini_projet_kaez/testcontours.ppm");


    return 0;
}
