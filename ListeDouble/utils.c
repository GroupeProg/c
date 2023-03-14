#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int getRandInt(int debutplage, int finplage){
    return (rand()%(finplage-debutplage+1) + debutplage);
};

float getRandFloat(float debutplage, float finplage){
    return debutplage + (float) (rand()) /( (float) (RAND_MAX/(finplage-debutplage)));
};
