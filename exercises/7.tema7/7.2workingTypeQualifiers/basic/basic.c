#include <stdio.h>

int main() {
    // Definición de una constante para la temperatura máxima permitida
    const int MAX_TEMP = 30; // Temperatura máxima en grados Celsius

    // Variable 'volatile' para simular la lectura del sensor de temperatura
    volatile int sensorTemp = 28; // Valor inicial del sensor

    printf("Temperatura actual: %d°C\n", sensorTemp);

    // Simulación de cambio de temperatura (como si fuera leída del sensor)
    sensorTemp = 32; // Cambio de temperatura

    // Verificación si la temperatura excede el máximo
    if (sensorTemp > MAX_TEMP) {
        printf("Alerta: Temperatura excedida! (%d°C)\n", sensorTemp);
    } else {
        printf("Temperatura dentro del rango normal.\n");
    }

    return 0;
}
