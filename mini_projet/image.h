#ifndef MP_H_INCLUDED
#define MP_H_INCLUDED

typedef struct{
    int rouge;
    int vert;
    int blue;
    unsigned char;
} pixel;

typedef struct{
    pixel **pixel_tab;
    int X;
    int Y;
}image;

typedef struct{
    int **pixel_tab;
    int X;
    int Y;
}image_gris;

#endif // MP_H_INCLUDED
