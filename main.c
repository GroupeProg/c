#include <stdio.h>
#include <stdlib.h>
#include "sources/pile.h"
#include "sources/file.h"
#include "sources/tp1.h"
#include "sources/shaya.h"
#include "sources/tree.h"
#include <string.h>


int main(){
    char *str;
    printf("Choisir un mot : ");
    scanf("%s", str);
    printf("%d", palindrome(str));
    return 0;
}