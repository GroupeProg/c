#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ex1 premiers programmes

int q1()
{
    char nom[20];
    char prenom[20];
    printf("entrez votre prenom : ");
    scanf("%s", prenom);
    printf("entrez votre nom : ");
    scanf("%s", nom);
    printf("Bonjour %s %s ", prenom, nom);
    return 0;
}

int q2()
{
    int a=38, b=125;
    printf("%d %d",a, b);
    return 0;
}

int q3()
{
    int a, b, c;
    printf("valeur 1 : ");
    scanf("%d", &a);
    printf("valeur 2 :");
    scanf("%d", &b);
    c=a;
    a=b;
    b=c;
    printf("les valeurs inversees sont : %d %d",a,b);
    return 0;
}

int q4()
{
    int a, c;
    float b;
    printf("valeur 1 :");
    scanf("%d", &a);
    printf("valeur 2 : ");
    scanf("%f", &b);
    c=b/a;
    printf("%d", c);
    return 0;
}


//ex2 structures de contrôles


int ex2q1()
{
   int a;
   printf("entrez une annee :");
   scanf("%d", &a);
   if(((a%4==0) && (a%100!=0)) || (a%400==0)) {
    printf("l'annee %d est bissextile", a );
   } else printf("l'annee %d n'est pas bissextile", a);
   return 0;
}

int ex2q2()
{
  int mois;
  printf("Entrez le numero d'un mois : \n");
  scanf("%d", &mois);

  switch(mois) {
    case 1 :
    case 3 :
    case 5 :
    case 7 :
    case 8 :
    case 10 :
    case 12 : printf("le nombre de jour dans le mois est 31 jours \n"); break;
    case 2 : printf("le nombre de jour est soit 28 soit 29 jours \n"); break;
    case 4 :
    case 6 :
    case 9 :
    case 11: printf("le nombre de jours dans le mois est 30 jours \n"); break;
    default :printf("il ne s'agit pas d'un mois connard"); break;
  }
  return 0;
}

int ex2q3(){
    int a,b,res,i;
    scanf("%d %d", &a, &b);
    for(i=1; i<=b; i++){
        res=res+a;
    }
    printf("le resultat est %d", res);
    return 0;
}

int ex2q4(){
    int h;
    printf("entier : ");
    scanf("%3d", &h);
    for(int i=0; i<h; i++){
        for(int esp = 0; esp<h-i; esp++){
            printf("   ");
        }
        for(int y=0; y<i; y++){
            printf("%3d" ,y);
        }
        for(int z=i; z>=0; z--){
            printf("%3d", z);

        }
        printf("\n");

    }
    return 0;
}

int ex2q5(){
    int n, i=1,res=1;
    printf("entier : \n");
    scanf("%d", &n);
    while(i<=5){
        res=res*i;
        i = i+1;
    }
    printf("%d", res);
    return 0;
}

int ex2q6(){
    int res, h=1;
    while (h!=0){
        printf("entrez un nombre, tapez zero pour arreter : \n");
        scanf("%d", &h);
        res=res+h;
    }
    printf("resultat : %d", res);
    return 0;
}

int ex2q7(){
    int res, h=1;
    while (h!=0){
        printf("entrez un nombre, tapez zero pour arreter : \n");
        scanf("%d", &h);
        res=res+h;
    }
    printf("resultat : %d", res);
    return 0;
}
// exercice 3 tableaux

int ex3q1(){
    int i, tab[100];
    for(i=0; i<100; i++){
        tab[i]=i;
    }
    for(i=0; i<100; i++){
            printf(" %2d", tab[i]);
    }
    return 0;
}

int ex3q2(){
    int i, tab[100];
    for(i=0; i<100; i++){
        tab[i]=i;
    }
    for(i=0; i<100; i++){
            if(i%2==0){
                printf(" %2d", tab[i]);
            } else;

    }
    return 0;
}

int ex3q3(){
    srand(time(NULL));
    int min, max;
    printf("valeur min : ");
    scanf("%d", &min);
    printf("valeur max : ");
    scanf("%d", &max);
    printf("%d", min + rand() % (max+1 - min));
    return 0;
}

int ex3q4(){
    int tab[100], i, res;
    srand(time(NULL));
    for(i=0; i<100; i++){
        res = rand() % 999;
        tab[i] = res;
        printf(" %4d ", tab[i]);
    }
    return 0;
}

int ex3q5(){
    srand(time(NULL));
    float tab[10], moy, nb;
    for(int i=0; i<10; i++){
        tab[i]=rand() % 9;
        printf("%f ", tab[i]);
    }
    for(int y=0; y<10; y++){
        moy= moy + tab[y];
        nb= nb +1;
    }
    printf(" \n");
    printf("moyenne : %f ", (moy/nb));
    return 0;
}

int ex3q6(){
    srand(time(NULL));
    int tab[10], min, max, val, imin, imax;
     for(int i=0; i<10; i++){
        tab[i]=rand() % 9;
        printf("%d ", tab[i]);
    }
    min=tab[0];
    for(int i=1; i<10; i++){
        val = tab[i];
        if (val<min) {
            min = val;
            imin = i;
        } else if (val>max){
            max=val;
            imax=i;
        } else;
    }
    printf("min: %d, indice : %d, max : %d, indice : %d", min, imin, max, imax);
    return 0;
}

//a revoir
int ex3q7(){
    srand(time(NULL));
    int tabpos[100], tabneg[100];
    int tab[100];
    for(int i=0; i<100; i++){
        tab[i]= (-100) + rand() % 200;
        printf("%3d ", tab[i]);
    }
    for(int y=0; y<100; y++){
        if (tab[y]>=0){
            tabpos[y]=tab[y];
        }else tabneg[y]=tab[y];
    }
    printf("\ntableau positif :\n");
    for(int i=0; i<100; i++){
        if(tabpos[i]==tab[i]){
            printf("%3d ", tabpos[i]);
        }else;
    }
    printf("\ntableau negatif \n");
    for(int i=0; i<100; i++){
        if(tabneg[i]==tab[i]){
            printf("%3d ", tabneg[i]);
        }else;
    }
    return 0;
}

int ex3q8(int n){
    int tab[100];
    int i=0;
    while(n>=1){
        if(n%2==1){
            tab[i]=1;
            i=i+1;
        }else {
            tab[i]=0;
            i=i+1;
        }
        n=n/2;
    }
    for(int y=i-1; y>=0; y--){
        printf("%d ", tab[y]);
    }
}


//exercice 4 chaines de caracteres

int ex4q1(){
    char mot[40], word[40];
    printf("mot 1 : ");
    scanf("%s", mot);
    printf("mot 2 : ");
    scanf("%s", word);
     if (strcmp(mot,word) ==0){
        printf("les mots sont egaux");
     }else printf("les mots ne sont pas egaux");
     return 0;
}

int ex4q2(){
    char res[40], mot[40];
    printf("entrez un mot");
    scanf("%s", mot);
    strcpy(res, mot);
    printf("%s", res);
    return 0;
}

int ex4q3(){
    char mot[10]="je suis ", reste[10]="ton pere";
    printf("%s", strcat(mot, reste));
    return 0;
}

int ex4q5(){
    char mot[100];
    int n;
    printf("mot :");
    scanf("%s", mot);
    printf("longueur :");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("%d : ",i+1);
        for(int y=0; y<=i; y++){
            printf("%c", mot[y]);
        }
        printf("\n");
    }
    return 0;
}

int ex4q6(){
    char mot[40];
    int len;
    printf(" entrez un mot :");
    scanf("%s", mot);
    len = strlen(mot);
    for(int i=len-1; i>=0; i--){
        printf("%c", mot[i]);
    }
    return 0;
}

int ex4q7(){
    char mot[40], inv[40];
    int len;
    printf(" entrez un mot :");
    scanf("%s", mot);
    len = strlen(mot);
    for(int i=len-1; i>=0; i--){
        inv[len-i-1]=mot[i];
    }
    if (strcmp(mot, inv)==0){
        printf("le mot %s est un palindrome", mot);
    }else printf("le mot %s n'est pas un palindrome, inverse : %s", mot, inv);
    return 0;
}

