#include <stdio.h>

// Definición de la macro para calcular el área del círculo
#define CALCULAR_AREA_CIRCULO(radio) (3.14159 * (radio) * (radio))

int main() {
    // Declaración de variables
    double radio, area;

    // Solicitar al usuario que ingrese el radio del círculo
    printf("Ingrese el radio del círculo: ");
    scanf("%lf", &radio);

    // Calcular el área utilizando la macro
    area = CALCULAR_AREA_CIRCULO(radio);

    // Imprimir el resultado
    printf("El área del círculo con radio %.2f es %.2f\n", radio, area);

    return 0;
}
