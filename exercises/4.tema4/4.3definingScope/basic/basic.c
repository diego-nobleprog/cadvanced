#include <stdio.h>

#define PI 3.14159

// Función para calcular el área de un círculo
float areaCirculo(float radio) {
    return PI * radio * radio; // El alcance de 'radio' es local a esta función
}

// Función para calcular el área de un cuadrado
float areaCuadrado(float lado) {
    return lado * lado; // El alcance de 'lado' es local a esta función
}

int main() {
    int opcion;
    float medida, area;

    // Presenta opciones al usuario
    printf("Calculadora de área\n1. Círculo\n2. Cuadrado\nElige una figura: ");
    scanf("%d", &opcion);

    // Pide al usuario la medida necesaria y calcula el área
    if (opcion == 1) {
        printf("Ingresa el radio del círculo: ");
        scanf("%f", &medida);
        area = areaCirculo(medida); // Llama a areaCirculo
    } else if (opcion == 2) {
        printf("Ingresa el lado del cuadrado: ");
        scanf("%f", &medida);
        area = areaCuadrado(medida); // Llama a areaCuadrado
    } else {
        printf("Opción no válida.\n");
        return 1; // Finaliza con un código de error
    }

    printf("El área es: %.2f\n", area); // Muestra el resultado

    return 0; // Finaliza con éxito
}
