#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

typedef struct {
    unsigned char r;
    unsigned char v;
    unsigned char b;
}pixel;

typedef struct {
    pixel** tab;
    int sizeX;
    int sizeY;
}image;


#endif // IMAGE_H_INCLUDED
