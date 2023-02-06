#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//Exercice 1: tableaux

int ex1q1(){
    srand(time(NULL));
    int max = 99, min = 10;
    int tab[200];
    for(int i=0; i<200; i++){
        tab[i]=min + rand()% max-min;
    }
    for(int y=0; y<200; y++){
        if(tab[y]>tab[y+1]){
            int a=tab[y], b=tab[y+1] ;
            tab[y]=b;
            tab[y+1]=a;
        }
    }
    printf("\n");
    for(int z=0; z<200; z++){
        printf("%3d ", tab[z]);
    }
    return 0;
}

int ex1q2(){
    srand(time(NULL));
    int max = 99, min = 10;
    int tab[200];
    for(int i=0; i<200; i++){
            tab[i]=min + rand()% max-min;
        }
        printf("tableau avant : \n");
        for(int b=0; b<200; b++){
            printf("%3d ", tab[b]);
        }
        for(int a=0; a<200; a++){
                for(int y=0; y<200; y++){
                    if(tab[y]>tab[y+1]){
                    int a=tab[y], b=tab[y+1] ;
                    tab[y]=b;
                    tab[y+1]=a;
                }
            }
        }
        printf("\n tableaux apres \n");
        for(int z=0; z<200; z++){
            printf("%3d ", tab[z]);
        }
        return 0;
}

//exercice 2

void ligne(int n){
    for(int i=0; i<n; i++){
            printf("*");
    }
}

float moyenne(int a, int b, int c){
    float res=(a+b+c)/3;
    return res;
}

void polynome(int a, int b , int c){
    //calcul discriminant
    float d= (b*b)-(4*a*c);
    printf("d: %f \n", d);
    if(d>0){
        float x, y;
        x=(-b-sqrtf(d))/(2*a);
        y=(-b+sqrtf(d))/(2*a);
        printf("les racines sont %f et %f", x, y);
    }else if(d==0){
        float x=(-b)/2*a;
        printf("la racine est %f", x);
    } else printf("aucune racine");
}

int tribulles(int tab[], int taille){
        for(int a=0; a<taille; a++){
                for(int y=0; y<taille; y++){
                    if(tab[y]>tab[y+1]){
                    int a=tab[y];
                    tab[y]=tab[y+1];
                    tab[y+1]=a;
                }
            }

        }
        printf("tableau trier : ");
            for(int i=0; i<taille; i++){
                printf("%d  ", tab[i]);
            }
        return tab[10];
}
/*void moyennematiere(int tab[], int n, int m){
    int res;
    float resu;
    for(int i=0; i<10; i++){
        printf("%d  ", tab[i]);
        printf("%d  ", tab[i])
    }
    resu= res/n;
    printf("moyenne de la matiere %d est : %f \n", m, resu);
}*/
//probleme avec moyenne for ne monte pas

float moyennemat(int tab[], int n){
    float res;
    for(int i=0; i<n; i++){
        res = res + tab[i];
    }
    res = res/n;
    return res;
}
void ex2q6(int n, int m){
    int tab[n][m];
    srand(time(NULL));
    for(int i=0; i<n; i++){
        for(int y=0; y<m; y++){
            tab[i][y]=rand() % 10;
            printf("%d ", tab[i][y]);
        } printf("\n");
    }
    for(int i=0; i<n; i++){
        printf("moyenne de l'etudiant %d : ", i+1);
        float res=moyenne(tab[i][0],tab[i][1],tab[i][2]);
        printf("%f \n", res);
    }
    int mat1[n];
    for(int y=0; y<m; y++){
        for(int i=0; i<n; i++){
                mat1[i]=tab[i][y];
                printf("%d", mat1[i]);
        }
        float moy1=moyennemat(mat1, n);
        printf("moyenne matiere %d : %f  ", y+1, moy1);
        int bnote=tribulles(mat1, n);
        printf("meilleure note de la matiere : %d \n", bnote);
    }
}

int facto(int n)
{
    if(n<=1) return 1;
    else return n*facto(n-1);
}

int fibo(int U0, int U1, int n){
    if(n>0){
        int U2=U0+U1;
        fibo(U1, U2, n-1);
    }else printf("resultat : %d", U0);
}


void tableaurec(int tab[], int taille, int ind, int res){
    if(ind<taille){
        if(tab[res]<=tab[ind]){
            tableaurec(tab,taille,ind+1,res);
        }else tableaurec(tab,taille,ind+1,ind);
    } else printf("la valeur la plus petite est : %d d'indice %d dans le tableau", tab[res], res);
}
