#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

enum jour {
    lundi       = 1,
    mardi       = 2,
    mercredi    = 3,
    jeudi       = 4,
    vendredi    = 5,
    samedi      = 6,
    dimanche    = 7
    };

enum mois {
    janvier     = 1,
    fevrier     = 2,
    mars        = 3,
    avril       = 4,
    mai         = 5,
    juin        = 6,
    juillet     = 7,
    aout        = 8,
    septembre   = 9,
    octobre     = 10,
    novembre    = 11,
    decembre    = 12
    };

struct date{
    enum jour jour;
    enum mois mois;
    int annee;
};

typedef struct date Date;

void afficheDate(Date d) {
    printf("%d/", d.annee);
    printf("%d/", d.mois);
    printf("%d/", d.jour);
}