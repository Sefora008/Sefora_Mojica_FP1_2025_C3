#include <stdio.h>

/* Superficie del triángulo.
El programa, al recibir como datos la base y la altura de un triángulo,
cancula su superficie.

BAS, ALT y SUP: variables de tipo real. */

void main (void)
{
    float BAS, ALT, SUP;
    printf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT / 2;
    printf("\nLA superficie del triángulo es: %5.2f", SUP);
    }
