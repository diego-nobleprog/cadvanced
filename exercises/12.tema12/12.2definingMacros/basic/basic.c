#include <stdio.h>

// Definición de la macro PI
#define PI 3.14159

// Macro para calcular el área de un círculo
#define AREA_CIRCULO(radio) (PI * (radio) * (radio))

// Macro para calcular el área de un cuadrado
#define AREA_CUADRADO(lado) ((lado) * (lado))

int main() {
    int opcion;
    double radio, lado;

    // Mostrar opciones al usuario
    printf("Seleccione una figura para calcular su área:\n");
    printf("1. Círculo\n2. Cuadrado\n");
    scanf("%d", &opcion);

    // Procesar la opción seleccionada
    switch (opcion) {
        case 1:
            printf("Ingrese el radio del círculo: ");
            scanf("%lf", &radio);
            printf("Área del círculo: %.2f\n", AREA_CIRCULO(radio));
            break;
        case 2:
            printf("Ingrese el lado del cuadrado: ");
            scanf("%lf", &lado);
            printf("Área del cuadrado: %.2f\n", AREA_CUADRADO(lado));
            break;
        default:
            printf("Opción no válida.\n");
    }

    return 0;
}
