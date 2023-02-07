#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "mini_projet_kaez\image.h"
#include "sources/tp2.h"

int main(){
    
    //image randimage = init_image(9,9);
    //image img = load("mini_projet_kaez/Sailor.ppm");

    //image imageloaded = load("mini_projet_kaez/img.ppm");
    //save(img, "mini_projet_kaez/SailorSaved.ppm");
    //sepia ("mini_projet_kaez/SailorSaved.ppm","mini_projet_kaez/SailorSepia.ppm");
    //contours("mini_projet_kaez/House2.ppm","mini_projet_kaez/House2Contours2.ppm");
    lissage("mini_projet_kaez/SailorSaved.ppm","mini_projet_kaez/SailorLissage.ppm", 3);

    return 0;
}
