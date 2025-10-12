#include <stdio.h>

/* Múltiplo.
El programa, al recibir como datos dos números enteros, determina si
el segundo es múltiplo del primero. */

int multiplo(int, int);

int main(void)
{
    int NU1, NU2, RES;
    printf("\nIngresa los dos números: ");
    scanf("%d %d", &NU1, &NU2);
    RES = multiplo(NU1, NU2);
    if (RES)
    printf("\nEl segundo número es múltiplo del primero");
    printf("\nEl segundo número no es múltiplo del primero");
}

int multiplo(int N1, int N2)
{
    int RES;
    if ((N2 % N1) == 0)
        RES = 1;
    else
        RES = 0;
    return (RES);
}
