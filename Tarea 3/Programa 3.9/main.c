#include <stdio.h>

/* Serie.
El programa imprime los términos y obtiene la suma de una determinada serie.

I, SSE y CAM: Variables de tipo entero. */

void main(void)
{
    int I = 2, CAM = 1;
    long SSE = 0;
    while (I <= 2500)
    {
        SSE = SSE +I;
        printf("\nt %d", I);
        if (CAM)
            {
                I += 6;
                CAM--;
            }
            else
            {
                I += 3;
                CAM++;
            }
    }
    printf("\nLa suma de la serie es: %d, SSE");
}
