#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mp.h"

/**
 *
 *  Les images seront dans le format PPM :
 *  Exemple :
 *  Afin d'afficher une échelle de gris avec le ppm, les valeurs des pixels vont être les suivants
 *
 *  24 7 <- La taille longueur largeur
 *  15 <- Les graduations de gris
 *  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 *  0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
 *  0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
 *  0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
 *  0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
 *  0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
 *  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 *
 * On ne peut travailler qu'avec des fichiers ppm.
*/
