#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED

typedef enum{
    lundi       = 1,
    mardi       = 2,
    mercredi    = 3,
    jeudi       = 4,
    vendredi    = 5,
    samedi      = 6,
    dimanche    = 7
}T_jour;

typedef enum {
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
}T_mois;

typedef struct{

    T_jour jour;
    T_mois mois;
    int annee;

} T_date;

void afficheDate(T_date d);
T_date dateVide( void );

#endif
