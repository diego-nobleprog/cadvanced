#include <stdio.h> // Incluye la biblioteca estándar de entrada/salida para usar printf y scanf

// Función principal del programa
int main() {
    // Declaración de variables para el peso, la altura y el IMC
    float peso, altura, imc;

    // Solicita al usuario su peso
    printf("Introduce tu peso en kilogramos: ");
    scanf("%f", &peso);

    // Solicita al usuario su altura
    printf("Introduce tu altura en metros: ");
    scanf("%f", &altura);

    // Calcula el IMC
    imc = peso / (altura * altura);

    // Muestra el resultado
    printf("Tu IMC es: %.2f\n", imc);

    // Determina el rango de peso
    if (imc < 18.5) {
        printf("Estás bajo de peso.\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Tu peso es normal.\n");
    } else if (imc >= 25.0 && imc <= 29.9) {
        printf("Tienes sobrepeso.\n");
    } else {
        printf("Tienes obesidad.\n");
    }

    // Termina el programa
    return 0; // Indica que el programa terminó exitosamente
}
