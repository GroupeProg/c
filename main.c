#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sources/pile.h"
#include "sources/file.h"
#include "sources/tp1.h"
#include "sources/tp2.h"
#include "sources/tp3.h"
#include "sources/shaya.h"
#include "sources/tree.h"

// TP2
int main(){

    T_date date = saisieDate(1, fevrier, 2020);
    afficheDateWithDay(date);
    return 0;
}