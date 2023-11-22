#include <stdio.h>

// Prototipos de funciones
void mostrarBinario(int num);
int invertirBits(int num);

int main() {
    // Declaración de variables
    int numero;

    // Solicitar al usuario ingresar un número entero
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    // Mostrar el número ingresado en su representación binaria original
    printf("Representación binaria original: ");
    mostrarBinario(numero);

    // Invertir los bits del número
    int numeroInvertido = invertirBits(numero);

    // Mostrar el número después de invertir sus bits
    printf("Representación binaria después de invertir bits: ");
    mostrarBinario(numeroInvertido);

    return 0;
}

// Función para invertir los bits de un número
int invertirBits(int num) {
    // Tamaño de un int en bits
    int tamano = sizeof(int) * 8;

    // Invertir cada bit
    for (int i = 0; i < tamano; i++) {
        num = num ^ (1 << i);
    }

    return num;
}

// Función para mostrar la representación binaria de un número
void mostrarBinario(int num) {
    // Tamaño de un int en bits
    int tamano = sizeof(int) * 8;

    // Mostrar cada bit
    for (int i = tamano - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }

    printf("\n");
}
