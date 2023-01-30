#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "mini_projet_kaez\image.h"


int main(){
    
    //image randimage = init_image(2,2);
    //save (randimage, "mini_projet_kaez/img.ppm");

    image imageloaded = load("mini_projet_kaez/img.ppm", 2, 2);

    save(imageloaded, "mini_projet_kaez/img2.ppm");

    return 0;
}
