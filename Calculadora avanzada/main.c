// =============================================
//  CALCULUS C - Calculadora Básica y Simple
// =============================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====== Prototipos ======
void limpiar_buffer();
void operaciones_basicas();
void mostrar_historial();
void guardar_historial(const char *texto);

// ====== Variables globales ======
char historial[100][200];
int contador_historial = 0;

// =============================================
//  UTILIDAD: Limpieza de Buffer
// =============================================
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// =============================================
//  MAIN
// =============================================
int main() {
    int opcion;
    printf("==== CALCULUS C (Basico) ====");
    do {
        printf("--- MENU PRINCIPAL ---");
        printf("[1] Operaciones basicas (double)");
        printf("[2] Ver historial de operaciones");
        printf("[3] Salir");
        printf("Seleccione una opcion: ");

        if (scanf(" %d", &opcion) != 1)
        {
            limpiar_buffer();
            opcion = 0;
        }

        switch (opcion) {
            case 1: operaciones_basicas(); break;
            case 2: mostrar_historial(); break;
            case 3: printf("Saliendo del programa... Hasta pronto!"); break;
            default: printf("Opcion invalida.\n");
        }

    } while (opcion != 3);

    return 0;
}

// =============================================
//  FUNCION HISTORIAL
// =============================================
void guardar_historial(const char *texto) {
    if (contador_historial < 100) {
        snprintf(historial[contador_historial], 200, "%s", texto);
        contador_historial++;
    } else {
        printf("[ADVERTENCIA] Historial lleno. No se guardaran mas operaciones.");
    }
}

void mostrar_historial() {
    printf("--- HISTORIAL DE OPERACIONES ---");
    if (contador_historial == 0) {
        printf("No hay operaciones registradas.");
        return;
    }

    for (int i = 0; i < contador_historial; i++)
        {
        printf("[%02d] %s\n", i + 1, historial[i]);
    }
}

// =============================================
//  FUNCION 1: Operaciones basicas
// =============================================
void operaciones_basicas() {
    double a, b, resultado;
    int op;
    char buffer[200];

    printf("--- OPERACIONES BASICAS ---");
    printf("[1] Sumar[2] Restar[3] Multiplicar[4] Dividir");
    printf("Seleccione una operacion: ");

    if (scanf(" %d", &op) != 1) {
        puts("Entrada invalida.");
        limpiar_buffer();
        return;
    }

    if (op < 1 || op > 4) {
        puts("Operacion invalida.");
        return;
    }

    printf("Ingrese el primer numero: ");
    if (scanf(" %lf", &a) != 1) {
        puts("Entrada invalida.");
        limpiar_buffer();
        return;
    }

    printf("Ingrese el segundo numero: ");
    if (scanf(" %lf", &b) != 1) {
        puts("Entrada invalida.");
        limpiar_buffer();
        return;
    }

    switch (op) {
        case 1:
            resultado = a + b;
            snprintf(buffer, 200, "Suma: %.2lf + %.2lf = %.2lf", a, b, resultado);
            break;
        case 2:
            resultado = a - b;
            snprintf(buffer, 200, "Resta: %.2lf - %.2lf = %.2lf", a, b, resultado);
            break;
        case 3:
            resultado = a * b;
            snprintf(buffer, 200, "Multiplicacion: %.2lf x %.2lf = %.2lf", a, b, resultado);
            break;
        case 4:
            if (b != 0)
                snprintf(buffer, 200, "Division: %.2lf / %.2lf = %.2lf", a, b, a / b);
            else
                snprintf(buffer, 200, "Error: Division entre cero");
            break;
    }

    printf("%s", buffer);
    guardar_historial(buffer);
}
