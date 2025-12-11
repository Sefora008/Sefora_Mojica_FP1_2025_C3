#include <stdio.h>
#include <string.h>

#define ARCHIVO "vehiculos.txt"
#define MAXC  80

/* Archivo de vehiculos:
Archivo de vehículos (texto, acceso secuencial)
guarda vehículos (Marca;Modelo;Precio;Año) en un archivo de texto
y permite listar o agregar sin borrar los anteriores.*/


typedef struct
{
    char marca[MAXC];
    char modelo[MAXC];
    float precio;
    int anno;
} Vehiculo;

void agregarVehiculo(void);
void listarVehiculos(void);
void limpia_newline(char *s);

int main(void)
{
    int opcion;
    do
    {
        printf("\nMENU VEHICULOS\n");
        printf("1. Lista de vehiculos\n");
        printf("2. Agregar vehiculo (sin borrar anteriores)\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) ;
            opcion = -1;
        }
        getchar();
        switch (opcion)
        {
            case 1:
                listarVehiculos();
                break;
            case 2:
                agregarVehiculo();
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }
    while (opcion != 0);
    return 0;
}

void limpia_newline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

void agregarVehiculo(void)
{
    Vehiculo v;
    FILE *fp;
    printf("\nAgregar vehiculo\n");
    printf("Marca: ");
    if (fgets(v.marca, MAXC, stdin) == NULL) { printf("Error lectura.\n"); return; }
    limpia_newline(v.marca);
    printf("Modelo: ");
    if (fgets(v.modelo, MAXC, stdin) == NULL) { printf("Error lectura.\n"); return; }
    limpia_newline(v.modelo);
    printf("Precio (ej. 12345.67): ");
    if (scanf("%f", &v.precio) != 1)
    {
        int c; while ((c = getchar()) != '\n' && c != EOF) ;
        printf("Precio invalido.\n"); return;
    }
    printf("Año (ej. 2020): ");
    if (scanf("%d", &v.anno) != 1)
    {
        int c; while ((c = getchar()) != '\n' && c != EOF) ;
        printf("Año invalido.\n"); return;
    }
    getchar();
    fp = fopen(ARCHIVO, "a");
    if (fp == NULL)
    {
        printf("No se puede abrir el archivo para escritura.\n");
        return;
    }
    fprintf(fp, "%s;%s;%.2f;%d\n", v.marca, v.modelo, v.precio, v.anno);
    fclose(fp);
    printf("Vehiculo agregado correctamente.\n");
}

void listarVehiculos(void)
{
    FILE *fp;
    char marca[MAXC], modelo[MAXC];
    float precio;
    int anio;
    fp = fopen(ARCHIVO, "r");
    if (fp == NULL)
    {
        printf("\nNo existe el archivo o no se puede abrir. Aun no hay vehiculos.\n");
        return;
    }
    printf("\n--- Lista de vehiculos ---\n");
    printf("%-20s | %-20s | %10s | %4s\n", "Marca", "Modelo", "Precio", "Año");
    printf("\n");
    while (fscanf(fp, " %79[^;];%79[^;];%f;%d%*c", marca, modelo, &precio, &anio) == 4)
    {
        printf("%-20s | %-20s | %10.2f | %4d\n", marca, modelo, precio, anio);
    }
    fclose(fp);
}
