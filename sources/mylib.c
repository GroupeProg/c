#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void q1(){
    char name[30], firstName[30];
    scanf("%s %s", &name, &firstName);
    printf("Bonjour %s %s", name, firstName);
}

void q2(){
    printf("%X %X", 38, 125);
}

void q3(int *i1, int *i2, int *i3){
    int c;
    c = *i1;
    *i1 = *i2;
    *i2 = *i3;
    *i3 = c;
}

void q4(){
    float i1;
    int i2;
    scanf("%f %d", &i1, &i2);
    float i3 = i1/i2;
    printf("%f", i3);
}

bool q5(int year){
    return (year%4 == 0 && year%100 != 0) || year%400==0;
}

void q6(int month){

    if(month < 0 || month > 12){
        printf("Nombre invalide");
    }

    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 jours");
            break;
        case 2:
            printf("Soit 28, soit 29 jours");
            break;
        default:
            printf("30 jours");
            break;
    }

}

int q7(int a, int b){
    int c = 0;
    for(int i = 0; i < b; i++){
        c+= a;
    }
    return c;
}

void q8(int h){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < h-i+1; j++){
            printf(" ");
        }
        for(int j = 0; j < i; j++){
            printf("%d", j);
        }
        for(int j = 0; j < i+1; j++){
            printf("%d", i-j);
        }
        printf("\n");
    }
}

int factorielle(int n){
    int i = 1, value = 1;

    while(++i < n+1){
        value *= i;
    }
    return value;
}

int somme(){
    int input = 1, value;
    while(input != 0){
        scanf("%d", &input);
        value+= input;
    }
    return value;
}

int longest_series(){
    int input = 1, value, count = 1, max, max_value;
    scanf("%d", &input);
    value = input;
    while(input != 0){
        scanf("%d", &input);
        if(value == input) count++;
        else {
            if(count > max) {
                max = count;
                max_value = value;
            }
            value = input;
            count = 1;
        }
    }
    printf("%d appeared %d times", max_value, max);
}

int is_perfect(int number){
    int sum;
    for(int i = 1; i < number ; i++){
        if(number%i == 0){
            sum+= i;
        }
    }

    return sum==number;

}

void fibonacci(int u1, int u2){
//
//    int i, value;
//    while(++i < 100){
//        value =
//        printf("i = %d, fibo = ");
//    }

    //TODO

}

int *tab100(){
    int *tab = (int*)malloc(sizeof(int)*100);
    printf("%i", sizeof(tab));
    for(int i = 0; i < 100; i++){
        *(tab+i) = (rand()%100)+1;
    }

    return tab;
}

int print_tab(int *tab){
    for(int i = 0; i < sizeof(tab); i++){
        printf("Int in %d position : %d\n", i, *(tab+i*4));
    }
}

void tab100_even(){

}
