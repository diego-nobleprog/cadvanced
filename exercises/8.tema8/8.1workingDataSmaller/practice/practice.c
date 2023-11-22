#include <stdio.h>

// Prototipos de funciones
void mostrarBinario(unsigned char num);

int main() {
    // Declaración de variables
    unsigned char numero;

    // Solicitar al usuario ingresar un número entero
    printf("Ingrese un número entero: ");
    scanf("%hhu", numero);

    // Mostrar el número original en binario
    printf("Número original en binario: ");
    mostrarBinario(digito);

    // Identificar y cambiar bits
    unsigned char cuartoBit = (numero >> 3) & 1;  // Identificar el cuarto bit
    unsigned char resultado = numero | (1 << 5);   // Cambiar el sexto bit a 1

    // Mostrar el resultado en binario
    printf("Cuarto bit: %d\n", cuartoBit);
    printf("Número después de cambiar el sexto bit: ");
    mostrarBinario(resultado);

    return 0;
}

// Función para mostrar la representación binaria de un byte
void mostrarBinario(char num) {
    for (int i = 8; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}
