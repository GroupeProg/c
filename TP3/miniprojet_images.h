#ifndef MINIPROJET_IMAGES_H_INCLUDED
#define MINIPROJET_IMAGES_H_INCLUDED

typedef struct mypixel{
    unsigned char r;
    unsigned char v;
    unsigned char b;
} pixel;

typedef struct myimage{
    pixel **img;
    int sizeX;
    int sizeY;
}image;

pixel init_pix();

image init_image(int x, int y);
void save(image img, char* f);
image load(char *i);
image changetored(image img);
image changetoblue(image img);
image changetogreen(image img);
image changetogrey(image img);
image changetogreymax(image img);
image changetosepia(image img);


#endif // MINIPROJET_IMAGES_H_INCLUDED
