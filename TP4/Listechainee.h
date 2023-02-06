#ifndef LISTECHAINEE_H_INCLUDED
#define LISTECHAINEE_H_INCLUDED

typedef struct cell
{
    char val;
    struct cell *next;
} *pile;

pile creerPileVide();

bool estVide(pile P);

pile empiler(pile P, char v);


#endif // LISTECHAINEE_H_INCLUDED
