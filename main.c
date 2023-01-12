#include <stdio.h>
#include <stdlib.h>

struct cellule
{
    int elem;
    struct cellule *suiv;
};

typedef struct cellule *T_pile;

T_pile creerVide() {
    T_pile p = NULL;
    return p;
}

T_pile empiler(T_pile p, int val) {
    T_pile newcase = (T_pile)malloc(sizeof(struct cellule));
    if (newcase == NULL){
        fprintf (stderr, "Memoire insuffisante\n");
        exit(EXIT_FAILURE);
    }
    else {
        newcase->elem = val;
        newcase->suiv = p;
        return newcase;
    }
}

T_pile depiler(T_pile p) {}

int main()
{
    T_pile a;
    a = creerVide();
    a = empiler(a, 12);
    printf("%d", a->elem);
}