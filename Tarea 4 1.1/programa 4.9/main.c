#include <stdio.h>

/* Paso de una función como parámetro por referencia. */

int Suma(int X, int Y)
/* La función suma regresa la suma de los parámetros de tipo entero X y Y. */

{
    return (X+Y);
}

int Resta(int X, int Y)
/* Esta funciónregresa la resta de los parámetros de tipo entero X y Y. */

{
    return (X-Y);
}
int Control(int (*apf) (int, int), int X, int Y)
{
    int RES;
    RES = (*apf) (X, Y);
    return (RES);
}

 void main (void)
{
    int R1, R2;
    R1 = Control(Suma, 15, 5);
    R2 = Control(Resta, 10, 4);
    printf("\nResultado 1: %d, R1");
    printf("\nResultado 2: %d, R2");
}
