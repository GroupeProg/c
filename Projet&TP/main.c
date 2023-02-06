#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main()
{
    image img;
    img = readImage("imgTest.ppm");
    save(img, "test.ppm");

    return 0;
}
