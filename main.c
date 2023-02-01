#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "mini_projet_kaez\image.h"
#include "sources/tp2.h"

int main(){
    
    //image randimage = init_image(1920,1080);
    //save (randimage, "mini_projet_kaez/test.ppm");

    //image imageloaded = load("mini_projet_kaez/img.ppm");
    //save(imageloaded, "mini_projet_kaez/img2.ppm");

    lissage("mini_projet_kaez/House2.ppm","mini_projet_kaez/House2lissage.ppm");


    return 0;
}
