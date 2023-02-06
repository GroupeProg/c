#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED

typedef enum day {
    lundi,
    mardi,
    mercredi,
    jeudi,
    vendredi,
    samedi,
    dimanche
} jour;

typedef enum month {janvier, fevrier, mars, avril, mai, juin, juillet, aout, septempbre, octobre, novembre, decembre} mois;

typedef struct datef{
    jour d;
    int day_nbr;
    mois m;
    int annee;
} date;

void afficheDate(date D);
char *afficheDate_aux(date D);

void test_pointeurs();
void test_pointeurs2();

int *tableau(int taille);

#endif // TP3_H_INCLUDED
