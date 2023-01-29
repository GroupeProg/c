#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "sources/pile.h"
#include "sources/file.h"
#include "sources/tp1.h"
#include "sources/tp2.h"
#include "sources/tp3.h"
#include "sources/shaya.h"
#include "sources/tree.h"
#include "mini_projet_kaez/image.h"



int main(){

    image azer = init_image(10,1);
    image *pimage = &azer;
    save(pimage, "mini_projet_kaez/img.ppm");
   
    return 0;
}