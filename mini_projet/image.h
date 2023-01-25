#ifndef MP_H_INCLUDED
#define MP_H_INCLUDED

typedef struct{
    int rouge;
    int vert;
    int blue;
    unsigned char *cha;
} pixel;

typedef struct{
    pixel **pixel_tab;
    int X;
    int Y;
}image;

char *int_to_str(int a);
pixel creerPiexel(int r, int v, int b);
void afficherPixel(pixel pix);

#endif // MP_H_INCLUDED