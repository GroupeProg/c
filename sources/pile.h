#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

typedef struct cellule *T_pile;
T_pile creerVide(void);
T_pile empiler(T_pile p, int val);
T_pile depiler(T_pile p);
void afficherPile(T_pile p);
int lenPile(T_pile p);

#endif
