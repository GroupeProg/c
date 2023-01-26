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

#include "mini_projet/image.h"

// TP2
int main(){
    
    image img = creerImageRandom(1920,1080);
    saveToPPM(img);
    return 0;
}