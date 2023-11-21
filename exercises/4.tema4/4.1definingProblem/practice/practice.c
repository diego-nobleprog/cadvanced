#include <stdio.h>

// Prototipos de funciones para las conversiones
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);

// Función principal
int main() {
    int opcion;
    float temperatura, convertida;

    // Mostrar menú de opciones al usuario
    printf("Conversor de Temperaturas\n");
    printf("1. Celsius a Fahrenheit\n");
    printf("2. Fahrenheit a Celsius\n");
    printf("Elige una opción: ");
    scanf("%d", &opcion);

    // Leer la temperatura a convertir
    printf("Ingresa la temperatura: ");
    scanf("%f", &temperatura);

    // Realizar la conversión basada en la opción
    if (opcion == 1) {
        convertida = celsiusToFahrenheit(temperatura);
        printf("%.2f grados Celsius son %.2f grados Fahrenheit.\n", temperatura, convertida);
    } else if (opcion == 2) {
        convertida = fahrenheitToCelsius(temperatura);
        printf("%.2f grados Fahrenheit son %.2f grados Celsius.\n", temperatura, convertida);
    } else {
        printf("Opción no válida.\n");
        return 1; // Termina el programa con un código de error
    }

    return 0; // Termina el programa con éxito
}

// Definición de la función celsiusToFahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32; // Fórmula de conversión de Celsius a Fahrenheit
}

// Definición de la función fahrenheitToCelsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9; // Fórmula de conversión de Fahrenheit a Celsius
}
