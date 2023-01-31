#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED



enum jour {Lundi, Mardi, Mercredi, Jeudi, Vendredi, Samedi, Dimanche};

enum mois {Janvier, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre};

typedef enum jour t_jour;
typedef enum mois t_mois;

struct date {
    int numeroJour;
    enum jour j;
    enum mois m;
    int annee;
};
typedef struct date t_date;

const char* getMonthName(mois);
const char* getDayName(jour);
void afficheDate(t_date D);
void tabPointeur(int taille);
float *allocTabFloat(int size);
int remplitTab(float *tab,int size);
t_date saisieDate();
/*-----------------------------------------------------------------------------------------*/
typedef struct {
    unsigned char r;
    unsigned char v;
    unsigned char b;
}pixel;

typedef struct {
    pixel** tab;
    int sizeX;
    int sizeY;
}image;
#endif // MYLIB_H_INCLUDED
