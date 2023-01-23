#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#include "tp3.h"



void afficheDate(T_date d) {

    printf("%d/", d.jour);
    printf("%d/", d.mois);
    printf("%d", d.annee);
}


T_date date_jma(T_jour jour, T_mois mois, int annee){
    T_date date;
    date.annee = annee;
    date.mois = mois;
    date.jour = jour;

    return date;
}

