#include <stdio.h>

/* Prueba de variables globales, locales y estáticas.
El rpograma utiliza funciones en las que se usan diferentes tipos de
variables*/


int f1(void);
int f2(void);
int f3(void);                     /* Prototipos de funciones. */
int f4(void);

int K = 3;                      /* variable global. */

void main (void)
{
    int I;
    for (I = 1; I <= 3; I++)
    {
         printf("\nEl resultado de la función f1 es: %d", f1 ());
         printf("\nEl resultado de la función f2 es: %d", f2 ());
         printf("\nEl resultado de la función f3 es: %d", f3 ());
         printf("\nEl resultado de la función f4 es: %d", f4 ());
    }
}
int f1(void )
/* La función f1 utilizada la variable global. */
  {
      K += K;
      return (K);
  }
int f2(void )
/* La función f2 utilizada la variable local. */
  {
      int k = 1;
      K++;
      return (K);
  }
  int f3(void )
/* La función f3 utilizada la variable estática. */
  {
      static int k = 8;
      K += 2;
      return (K);
  }
  int f4(void )
/* La función f4 utiliza dos variables con el mismo nombre: local y global. */
  {
      int k = 5;
      K = K + K;               /* Uso de la variable local (K) y la global (::K) */
      return (K);
  }

