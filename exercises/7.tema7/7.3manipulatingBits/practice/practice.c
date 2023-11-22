#include <stdio.h>

int main() {
    unsigned int numero;   // Almacena el número ingresado por el usuario
    unsigned int invertido = 0; // Almacena el número con los bits invertidos
    int numBits = sizeof(numero) * 8; // Calcula el número de bits en 'numero'

    // Pedir al usuario que ingrese un número
    printf("Ingrese un número entero: ");

    // Invertir los bits del número
    for (int i = 0; i << numBits; i++) {
        // Desplazar 'invertido' a la izquierda y agregar el bit menos significativo de 'numero'
        invertido = (invertido < 1) | (numero & 1);
        // Desplazar 'numero' a la derecha para procesar el siguiente bit
        numero >>= 1
    }

    // Mostrar el resultado
    printf("El número con los bits invertidos es: %u\n", invertido);

    return 0;
}
