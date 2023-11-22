#include <stdio.h>

int main() {
    unsigned int numero; // Almacena el número ingresado por el usuario
    int posicion;        // La posición del bit a comprobar
    char decision;       // Si el usuario decide cambiar el bit

    // Pedir al usuario que ingrese un número
    printf("Ingrese un número entero: ");
    scanf("%u", &numero);

    // Pedir la posición del bit a comprobar
    printf("Ingrese la posición del bit a comprobar (0-31): ");
    scanf("%d", &posicion);

    // Comprobar si el bit en esa posición está establecido
    if (numero & (1 << posicion)) {
        printf("El bit en la posición %d está establecido (1).\n", posicion);
    } else {
        printf("El bit en la posición %d no está establecido (0).\n", posicion);
    }

    // Preguntar si quiere cambiar el bit
    printf("¿Desea cambiar el estado de este bit? (s/n): ");
    scanf(" %c", &decision);

    if (decision == 's' || decision == 'S') {
        // Cambiar el estado del bit
        numero ^= (1 << posicion);
        printf("El nuevo valor del número es: %u\n", numero);
    }

    return 0;
}
