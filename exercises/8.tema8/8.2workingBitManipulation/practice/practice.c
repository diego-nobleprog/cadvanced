#include <stdio.h>

int main() {
    // Pregunta al usuario por un número entero
    printf("Ingresa un número entero: ");
    int numero;
    scanf("%d", &numero);

    // Pregunta al usuario por el bit a cambiar
    printf("Elige un bit para cambiar (0 al 31): ");
    int bit;
    scanf("%d", &bit);

    // Verifica que el bit seleccionado esté en el rango correcto
    if (bit < 0 || bit > 31) {
        printf("Error: Elige un bit válido (0 al 31).\n");
        return 1; // Termina el programa con código de error
    }

    // Realiza la manipulación de bits para cambiar el bit seleccionado
    numero ^= (1 << bit);

    // Muestra el resultado después del cambio de bit
    printf("Número después del cambio de bit: %d\n", numero);

    return 0;
}
