#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "mini_projet_kaez\image.h"
#include "sources/tp2.h"

int main(){
    
    image randimage = init_image(50,50);
    save (randimage, "mini_projet_kaez/imgtest.ppm");

    //image imageloaded = load("mini_projet_kaez/img.ppm");
    //save(imageloaded, "mini_projet_kaez/img2.ppm");

    sepia("mini_projet_kaez/imgtest.ppm","mini_projet_kaez/imgtestSepia.ppm");


    return 0;
}
