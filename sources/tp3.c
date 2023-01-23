#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#include "tp3.h"
#include "tp1.h"



void afficheDate(T_date d) {

    printf("%d/", d.jour);
    printf("%d/", d.mois);
    printf("%d", d.annee);
}

void afficheDateWithDay(T_date date) {

    date.jour = get_day_enum(date);
    printf(get_day_name(date.jour));
    printf(" %d ", date.jour_mois);
    printf(get_mounth_name(date.mois));
    printf(" %d", date.annee);
}

//Sans besoin de faire la Q6, on voit normalement que celui retourné n'a pas la même valeur-espace mémoire


T_date saisieDate(int jour_du_mois, T_mois mois, int annee)
{
    T_date date;
    date.annee = annee;
    date.mois = mois;
    date.jour_mois = jour_du_mois;

    return date;
}

// Retourne la
T_date date_zero()
{
    T_date date0 = saisieDate(1, janvier, 1970);
    date0.jour = jeudi;
    return date0;
}

//Sert à déterminer si une année est Bissextile ou non
int bissextile(int annee)
{
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int nbr_jour(T_jour mois, int annee) {

    switch (mois)
    {
    case janvier:
    case mars:
    case mai:
    case juillet:
    case aout:
    case octobre:
    case decembre:
        return 31;
        break;

    case avril:
    case juin:
    case septembre:
    case novembre:
        return 30;
        break;

    case fevrier:
        if (bissextile(annee) == 0)
        {
            return 29;
        }
        else
        {
            return 28;
        }
        break;

    default:
        break;
    }
}

const char *get_day_name(T_jour jour) {
    switch(jour) {
        case lundi: 
            return "Lundi";
        case mardi:
            return "Mardi";
        case mercredi:
            return "Mercredi";
        case jeudi:
            return "Jeudi";
        case vendredi:
            return "Vendredi";
        case samedi:
            return "Samedi";
        case dimanche:
            return "Dimanche";
        default: break;
    }
}

const char *get_mounth_name(T_jour mois)
{
    switch (mois)
    {
    case janvier:
        return "Janvier";
    case fevrier:
        return "Fevrier";
    case mars:
        return "Mars";
    case avril:
        return "Avril";
    case mai:
        return "Mai";
    case juin:
        return "Juin";
    case juillet:
        return "Juillet";
    case aout:
        return "Aout";
    case septembre:
        return "Septembre";
    case octobre:
        return "Octobre";
    case novembre:
        return "Novembre";
    case decembre:
        return "Decembre";
    default:
        break;
    }
}

int get_days_from_date_zero(T_date date) {
    T_date zero = date_zero();
    int cumul = 0;
    
    for(int i = zero.annee; i < date.annee; i++) {
        for(int j = 1; j <= decembre; j++) {
            cumul += nbr_jour(j, i);
        }
    }

    for(int mounth = 1; mounth < date.mois; mounth++) {
        cumul += nbr_jour(mounth, date.annee);
    }

    cumul += date.jour_mois;

    return cumul-1;
}

int get_day_enum(T_date date) {
    T_date zero = date_zero();
    int jour = zero.jour + get_days_from_date_zero(date);
    return ((jour-1)%7)+1;
}

T_date saisieDate_with_prompt()
{
    printf("Bonjour, selectionner jour dans le mois");
    //flemme pour l'instant
}