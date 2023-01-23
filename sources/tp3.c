#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#include "tp3.h"
#include "tp2.h"
#include "tp1.h"

#define annee_zero 1970
#define jour_zero jeudi


// Permet d'afficher une date créée à partir de T_date.
void afficheDate(T_date d) {

    printf("%d/", d.jour);
    printf("%d/", d.mois);
    printf("%d", d.annee);
}


// Permet d'afficher une date avec le jour, le numéro de jour, le mois et l'année.
void afficheDateWithDay(T_date date) {

    date.jour = get_day_enum(date);
    printf(get_day_name(date.jour));
    printf(" %d ", date.jour_mois);
    printf(get_mounth_name(date.mois));
    printf(" %d", date.annee);
}

//Sans besoin de faire la Q6, on voit normalement que celui retourné n'a pas la même valeur-espace mémoire

// Renvoie une date avec le jour du mois, le mois et l'année.
T_date saisieDate(int jour_du_mois, T_mois mois, int annee)
{
    T_date date;
    date.annee = annee;
    date.mois = mois;
    date.jour_mois = jour_du_mois;

    return date;
}

// Retourne la date du premier jour de l'ordinateur.
T_date date_zero()
{
    T_date date0 = saisieDate(1, janvier, annee_zero);
    date0.jour = jour_zero;
    return date0;
}

//Sert à déterminer si une année est Bissextile ou non.
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

// Renvoie le nombre de jour pour un mois en particulier. Ne pas oublier de renseigner l'année.
int get_nbr_jour(T_jour mois, int annee) {

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

// Renvoie en string le jour avec l'énumération de son propre jour.
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

// Renvoie en string le mois avec l'énumération de son propre mois.
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

// Renvoie le nombre de jour écoulé depuis le jour 1 de l'ordinateur.
int get_days_from_date_zero(T_date date) {
    T_date zero = date_zero();
    int cumul = 0;
    
    for(int i = zero.annee; i < date.annee; i++) {
        for(int j = 1; j <= decembre; j++) {
            cumul += get_nbr_jour(j, i);
        }
    }

    for(int mounth = 1; mounth < date.mois; mounth++) {
        cumul += get_nbr_jour(mounth, date.annee);
    }

    cumul += date.jour_mois;

    return cumul-1;
}

// Renvoie le numéro du jour de la semaine avec une date.
int get_day_enum(T_date date) {
    T_date zero = date_zero();
    int jour = zero.jour + get_days_from_date_zero(date);
    return ((jour-1)%7)+1;
}


// Modifie l'année de la date
void modifie_annee(T_date *date, int annee) {
    date->annee = annee;
}

// Demande à l'utilisateur avec un petit programme la date qu'il souhaite en tatonant
T_date saisieDate_with_prompt()
{
    
    int annee;
    T_mois mois;
    printf("Bonjour, selectionnez l'annee : ");
    scanf("%d", &annee);
    printf("\nQuel mois ? : ");
    scanf("%d", &mois);
    printf("\n\n     %s %4d", get_mounth_name(mois), annee);
    printf("\n Lu Ma Me Je Ve Sa Di");
    int jour_max = get_nbr_jour(mois, annee);

    T_date date = saisieDate(1, mois, annee);
    T_jour jour = get_day_enum(date);

    printf("\n");
    int i = 1;
    for (i; i < (int)(jour); i++)
    {
        printf("   ");
    }
    for(int j = 1; j <= jour_max; j++){
        if((j+i-1)%7 == 1) {
            printf("\n");
        }
        printf("%3d", j);
    }

    printf("\n\nQuel jour dans le mois de %s %d ? : ", get_mounth_name(mois), annee);
    
    int jour_renseigne = 285;

    while((jour_renseigne <= 0) || (jour_renseigne > jour_max)) {
        scanf("%d", &jour_renseigne);
        if ((jour_renseigne <= 0) || (jour_renseigne > jour_max)) {
            printf("\nRenseignez un jour valide ! : ");
        }
        else {
            break;
        }
    }

    date.jour_mois = jour_renseigne;
    printf("Vous avez selectionne ");
    afficheDateWithDay(date);

    return date;
}

//Afficher un calendrier d'un mois de l'année, les deux sont choisis. 
void calendar(T_mois mois, int annee) {

    printf("\n     %s %4d", get_mounth_name(mois), annee);
    printf("\n Lu Ma Me Je Ve Sa Di");
    int jour_max = get_nbr_jour(mois, annee);

    T_date date = saisieDate(1, mois, annee);
    T_jour jour = get_day_enum(date);

    printf("\n");
    int i = 1;
    for (i; i < (int)(jour); i++)
    {
        printf("   ");
    }
    for (int j = 1; j <= jour_max; j++)
    {
        if ((j + i - 1) % 7 == 1)
        {
            printf("\n");
        }
        printf("%3d", j);
    }
}

/**
 * 
 * 
 * Pointeurs
 * 
 * 
*/

//Initialise un pointeur, le modifie, et pointe vers un pointeur
void pointeurs() {
    int a = 6;
    int *p = &a;
    
    //Adresse de a
    printf("%p\n", a);

    //Adresse de p
    printf("%p", p);

    //Valeur à la valeur pointée
    printf("\n%d", *p);

    //Adresse de la variable pointée
    printf("\n%p", *p);

    int *ptr = p;
    printf("\n%d", *ptr);
    *ptr = 1212;

    printf("\n%d", *ptr);
}

//Fonction pour tester la navigation d'un tableau sans utiliser le dit tableau, seulement avec un autre pointeur
void tab_with_pointeur() {

}

//Pointeurs à finir plus tard$

/**
 * 
 * 
 * Tableaux bis repetita
 * 
 * 
*/

float *allocTabFloat(int size) {
    return (float *)malloc(sizeof(float *) * size);
}

void allocTabFloatPrompt() {
    int size;
    printf("Donnez la taille du tableau : ");
    scanf("%d", &size);
    float *tab = allocTabFloat(size);
}

