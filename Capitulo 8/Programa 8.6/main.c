#include <stdio.h>
#include <string.h>

/* Comercializadora farmacéutica.
El programa maneja información sobre ventas, inventario, reabastecimiento y
nuevos productos de una comercializadora farmacéutica. */

typedef struct
{
   int clave;
   char nombre[15];
   float precio;
   int existencia;
} producto;

void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);


void main(void)
{
    producto INV[100];
    int TAM, OPE;
    do
    {
       printf("Ingrese el número de productos: ");
       scanf("%d", &TAM);
    }
    while (TAM > 100 | | TAM < 1);
    printf("\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2 –Reabastecimiento \n\t\t3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t 0 - Salir: ");
    scanf(”%d”, &OPE);
    while (OPE)
    {
     switch (OPE)
     {
        case 1: Ventas(INV, TAM);
            break;
        case 2: Reabastecimiento(INV, TAM);
            break;
        case 3: Nuevos_Productos(INV, &TAM);
            break;
        case 4: Inventario(INV, TAM);
            break;
        };
     printf("\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2 –Reabastecimiento\n\t\t 3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t 0 - Salir: ");
     scanf("%d”, &OPE);
}
