#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "tp1.h"


/*
 * 
 * PREMIERS PROGRAMMES
 * 
 */

//Premiers programmes:
//Un programme qui demande a l’utilisateur son prenom, puis son nom, et affiche 'Bonjour prenom nom'.
int quisuisje(){
    char p[10],n[10];
    printf("Ton prenom? ");
    scanf("%s", p);
    printf("Ton nom? ");
    scanf("%s", n);
    printf("Dak %s %s, ty est un vrai BG toi.\n", p,n);
    return 0;
}

//Un programme qui permute deux valeurs entieres et les affiche avant et apres permutation.
int permute(){
    int a, b, c;
    printf("Un nombre ? ");
    scanf("%d", &a);
    printf("Un autre nombre ? ");
    scanf("%d", &b);
    printf("Dak, tes deux nombres sont : %d et %d.\n", a,b);
    c = a;
    a = b;
    b = c;
    printf("Tiens tes nombres apres permutation:  %d et %d.\n", a,b);
    return 0;
}

//Structures de controle:
//Un programme qui indique si une annee donnee par l’utilisateur est bissextile.
int year(){
    int y;
    printf("Une annee? ");
    scanf("%d", &y);
    if ((y%4 == 0 && y%100 != 0)||(y%400 == 0)){
        printf("Bissextile! ;p \n");      
    }
    else{
        printf("PAS Bissextile! ;p \n");
    }
    return 0;
}

// Afficher division, remarquer que faire un int sur un float prend seulement la valeur entière.
int division() {
    int a, b;
    printf("Valeur a : ");
    scanf("%d", &a);
    printf("\nValeur de b : ");
    scanf("%d", &b);
    printf("\n%d", (a/b));

    return 0;
}


/*
 * 
 * STRUCTURES DE CONTROLE
 * 
 */


//Un programme qui demande deux entiers a et b a l’utilisateur et calcule leur produit sans utiliser l’operateur ’*’.
int multi_aux(int a, int b) {
    if (a==0) {
        return 0;
    }
    else {
        return b + multi_aux(a-1, b);
    }
}

int multi() {
    int a, b;
    printf("Valeur a (positif) : ");
    scanf("%d", &a);
    printf("\nValeur de b (positif) : ");
    scanf("%d", &b);
    printf("Le résultat est %d !", multi_aux(a, b));
    
    return 0;
}

//Un programme qui demande a l’utilisateur un entier h, et affiche une pyramide.
int pyramide() {
    int h;
    printf("Valeur h (positif) : ");
    scanf("%d", &h);
    for(int i = 0; i<=h; i++) {
        int esp = h-i;
        for(int e = 0; e < esp; e++) {
            printf(" ");
        }
        for(int j = 0; j!=i; j++) {
            printf("%d", j);
        }
        for(int k = i-2; k>=0; k--) {
            printf("%d", k);
        }
        printf("\n");
    }
    return 0;
}

//Un algorithme avec une boucle while qui realise le calcul de n! (factorielle).
int factoriel() {
    int n, res = 1;
    printf("Valeur n! (positif) : ");
    scanf("%d", &n);
    while(n >= 1) {
        res *= n;
        n--;
    }
    printf("Le resultat est %d ! \n", res);
    return 0;
}

//un programme permettant de saisir une suite d’entiers et de faire leur somme. La saisie des entiers est interrompue lorsque l’utilisateur donne la valeur 0.
int sum(){
    int a, t = 0;
    do {
        printf("\nEntier : ");
        scanf("%d", &a);
        t += a;
    }while (a != 0);
    printf("\n La somme donne: %d \n", t);
    return 0;
}

int longue_cons(){
    int nbr, sum, temp_nbr;
    nbr = 0;
    sum = 0;
    temp_nbr = 0;
    int winner[2] = {0, 0};

    do {
        printf("\nEntier : ");
        scanf("%d", &nbr);
        if(nbr == temp_nbr) {
            sum += 1;
        }
        else {
            if(winner[1] < sum) {
                winner[0] = nbr;
                winner[1] = sum;
            }
            temp_nbr = nbr;
            sum = 1;
        }
    } while (nbr != 0);
    printf("Le nombre avec le plus d'appels est %d avec %d fois renseign&.", winner[0], winner[1]);

    return 0;
}

int nombre_parfait() {
    //Un nombre est parfait si la somme de ses diviseur vaut son nombre
    int nbr, sum, index;
    printf("\nEntier : ");
    scanf("%d", &nbr);

    int *parfait = (int *)malloc(nbr * sizeof(int));
    index = 0;
    sum = 0;

    for(int i = 1; i <= nbr; i++) {

        for(int j = 1; j < i; j++) {
            if(i%j == 0) {
                sum += j;
            }
        }

        if(i == sum){
            
            parfait[index] = i;
            index++;
        }
        sum = 0;
    }
    printf("\n");
    //Afficher les nombres parfaits
    printf("<%d> => ", index);
    for(int k = 0; k < index; k++) {
        if (k!=0)
        {
            printf(", ");
        }
        printf("%d", parfait[k]);
    }

    free(parfait);

    return 0;
}

//Fibonacci => Ui = Ui-1 + U1-2 -> Ui+1 = Ui + Ui-1, cependant je n'ai pas encore la technique pour pouvoir afficher d'énormes nombres
int fibonacci(){
    __int64 u0, u1, u2 = 0;
    printf("Nombre pour U0 : ");
    scanf("%lu", &u0);
    printf("\nNombre pour U1 : ");
    scanf("%lu", &u1);
    int i = 1;

    do{
        u2 = u1 + u0;
        u1 = u2;
        u0 = u1;
        i++;
        printf("%llu, ", u2);

    }while(i != 100);
    printf("\n\nu2 = %lu", u2);

    return 0;
}


/*
 * 
 * TABLEAUX
 * 
 */


int tableau() {
    int tab[100];
    for(int i = 0; i<100; i++) {
        tab[i] = i+1;
    }
    for (int i = 0; i < 100; i++)
    {
        printf("%d, ",tab[i]);
    }
}

int tableau_paire()
{
    int tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i] = i + 1;
    }
    for (int i = 0; i < 100; i += 2)
    {
        printf("Attention, ca affiche des nombres impaires car sur les index paires, on a n+1.\n");
        printf("%d, ", tab[i]);
    }
}

int random() {
    int min, max, val = 0;
    printf("Min : ");
    scanf("%d", &min);
    printf("\nMax : ");
    scanf("%d", &max);
    srand(time(NULL));

    while(val < min && val > max) {
        val = rand();
    }

    printf("%d", val);
    return 0;
}

int time_time()
{
    return difftime(time(NULL), (int)NULL);
}

int randint(int min, int max)
{
    int val = 0;
    srand(time_time());

    do {
        val = rand();
    }while((val < min) || (val > max));

    return val;
}

int *tab_rand() {

    int *tab = malloc(100 * sizeof(int));
    srand(time_time());

    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand()%999;
    }

    for (int i = 0 ; i < 100; i++) {
        printf("%3d|", tab[i]);
        if(i%5 == 4){
            printf("\n");
        }
    }

    return (int *)tab;
}

int *tab_rand_without_print()
{

    int *tab = malloc(100 * sizeof(int));
    srand(time_time());
    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand() % 999;
    }
    return (int *)tab;
}

int *tab_rand_without_print_limited(int limite)
{

    int *tab = malloc(limite * sizeof(int));
    srand(time_time());
    for (int i = 0; i < limite; i++)
    {
        tab[i] = rand() % 999;
    }
    return (int *)tab;
}

float moyenne() {
    int *tab = tab_rand_without_print();
    float moy = tab[0];
    for (int i = 1; i < 100; i++)
    {
        moy = (moy + tab[i])/2;
    }
    printf("%f", moy);

    return moy;
}

int *sep_pos_neg(){
    int *tab = tab_rand_without_print();
    int *pos = malloc(100 * sizeof(int));
    int *neg = malloc(100 * sizeof(int));

    int inpos, inneg = 0;
    for(int i = 0; i < 100; i++) {
        if(tab[i] < 0) {
            neg[inneg] = tab[i];
            inneg++;
        } else {
            pos[inpos] = tab[i];
            inpos++;
        }
    }

    return (int *)tab;
}

int power(int a, int b) {
    int result = 1;
    for(int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

unsigned int unsigned_power(unsigned int a, unsigned int b) {
    unsigned int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}

void print_tab(int *tab) {
    size_t size = sizeof(tab)/sizeof(tab[0]);
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d, ", tab[i]);
    }
    printf("]");
}

void print_tab_with_size(int *tab, size_t size) {
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", tab[i]);
    }
    printf("]");
}

int int_to_bin(int nbr) {
    int pow = 0;
    int nbr10 = 0;
    while(nbr > nbr10) {
        pow++;
        nbr10 = power(2, pow);
    }

    nbr10 = nbr;
    int *bin = malloc((pow+1) * sizeof(int));

    for(int i = pow; i >= 0; i--) {
        int supr = power(2, i);
        if (supr > nbr10)
        {
            bin[pow - i] = 0;
        }
        else {
            bin[pow - i] = 1;
            nbr10 -= supr;
        }
    }

    print_tab_with_size(bin, pow+1);

    return 0;
}

void print_tab_bin_loop(int limite, int milliseconds) {
    for (int i = 0; i <= limite; i++)
    {
        printf("%5d ", i);
        Sleep(milliseconds);
        int_to_bin(i);
        printf("\r");
    }
}

void tri_tab(int *tab, size_t size) {

    int temp = 0;
    int test = 1;

    while (test != 0)
    {
        test = 0;
        for(int i = 0; i < size; i++){
            if((tab[i] > tab[i+1]) && (i != size-1)){
                temp = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = temp;
                test++;
            }
        }
    }
}


/**
 * 
 * CHAINES DE CARACTERES
 * 
 */


#include <string.h>
/*

    strcmp = string comparaison - Permet de comparer deux chaines de caractères. ('a' = 'a')
        return int
    
    strcpy = string copy - Permet de copier l'intégralité d'une chaine de caractère dans une autre
                           /!\ Il faut que la chaine qui reçoit soit assez grande

    strcat = Rassembler deux chaines de caractères en une et une seule

    strlen = Affiche la taille de la chaine de caractère

*/

//Print 0 si c'est juste, Print -1 si c'est faux
void stringcmp(void) {
    char ch1[20];
    char ch2[20];
    printf("Veuillez ecrire ch1 : ");
    scanf("%s", ch1);
    printf("\nVeuillez ecrire ch2 : ");
    scanf("%s", ch2);

    printf("\n%d ", strcmp(ch1, ch2));
}

void stringcopy(void) {
    char ch1[20];
    char ch2[20];

    printf("Veuillez ecrire ch1 : ");
    scanf("%s", ch1);

    strcpy(ch2, ch1);
}

char *stringcatenation() {
    char ch1[20];
    char ch2[20];
    printf("Veuillez ecrire ch1 : ");
    scanf("%s", ch1);
    printf("\nVeuillez ecrire ch2 : ");
    scanf("%s", ch2);

    char *ch3 = strcat(ch1, ch2);
    return (char *)ch3;
}

void str_print(char *str) {
    printf("%s", str);
}

//Q4 - Si on écrit plus que ce qui est prévu à l'origine, le printf s'arrête à la limite du str ou s'arrête au premier espace
void printc(void) {
    char ch1[20];
    printf("Veuillez ecrire ch1 : ");
    scanf("%s", ch1);
    printf("\n%s", ch1);
}

void triangle_word(char *mot, int nbr){
    for(int i = 1; i <= nbr; i++) {
        if (i >= strlen(mot))
        {
            printf("Valeur de nombre de lignes trop grande.");
            break;
        }
        printf("%3d : ", i);
        for(int j = 0; j < i; j++) {
            printf("%c", mot[j]);
        }
        printf("\n");
    }
}

char *str_upside_down(char *str) {
    size_t size = strlen(str);
    char *strud = malloc(size-1);
    char *strsup = malloc(size-1);
    strsup = str;
    int index = 0;
    for (int i = size; i > 0; i--) {
        strud[index] = strsup[i-1];
        index++;
    }
    if(strlen(strud) > size) {
        strud[size] = '\0';
    }
    return (char *)strud;
}

int palindrome(char *str) {
    return strcmp(str, str_upside_down(str));
}