#include <stdio.h>

/* Fibonacci.
El programa calcula y escribe los primeros 5o números de Fibonacci.

I, PRI, SEG, SIG: Variables de tipo entero. */

void main(void)
{
    int I, PRI = 0, SEG = 1, SIG;
    printf("\nt %d \t %d", PRI, SEG);
    for (I = 3; I <= 50; I++)
    {
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;
        printf("\nt%d", SIG);
    }
}
