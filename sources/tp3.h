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
    int jour_mois;
    int annee;

} T_date;

void afficheDate(T_date d);
T_date saisieDate(int jour_du_mois, T_mois mois, int annee);
void afficheDateWithDay(T_date date);
T_date date_zero(void);
int bissextile(int annee);
int get_nbr_jour(T_jour mois, int annee);
const char *get_day_name(T_jour jour);
const char *get_mounth_name(T_jour mois);
int get_days_from_date_zero(T_date date);
int get_day_enum(T_date date);
T_date saisieDate_with_prompt(void);
void modifie_annee(T_date *date, int annee);

#endif