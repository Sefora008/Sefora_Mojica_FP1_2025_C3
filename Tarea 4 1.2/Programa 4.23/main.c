#include <stdio.h>

/* Función que intercambia los valores de dos variables enteras. */

void trueque(int *x, int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

/*Función que suma un número consigo mismo. */

int suma(int x)
{
    return (x + x);
}

void main (void)
{
    int x = 5, y = 10, z;
    suma (10);
    y = suma(10);
    printf("\nResultado de y = suma(10): %d", y);
    trueque(&x, &y);
    printf("\nDespués del trueque: x = %d, y = %d", x, y);
    z = suma(x);
    printf("\nz = suma(x) = %d", z);
}
