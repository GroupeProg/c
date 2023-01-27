#ifndef MP_H_INCLUDED
#define MP_H_INCLUDED

typedef struct{
    int rouge;
    int vert;
    int blue;
    char *chr;
} pixel;

typedef struct{
    pixel *pixel_tab;
    int X;
    int Y;
}image;

char *int_to_str(int a);
int str_to_int(char *str);
char *strcat3(char *a, char *b, char *c);
char *str_upside_down_2(char *str);

pixel creerPixel(int r, int v, int b);
image creerImage(int X, int Y);
image creerImageRandom(int X, int Y);
pixel creerPixelRandom(void);

void afficherPixel(pixel pix);
int saveToPPM(image img);
image loadFromPPM(char *path);

#endif // MP_H_INCLUDED
