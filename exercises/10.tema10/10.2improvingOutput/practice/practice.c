#include <stdio.h>
#include <stdlib.h>

// Función para imprimir la información de los números
void imprimirNumeros(int numeros[], int cantidad) {
    printf("\n\033[1;32mNúmeros Ingresados:\033[0m\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

int main() {
    int cantidadNumeros;

    // Solicitar al usuario la cantidad de números
    printf("Ingrese la cantidad de números que desea ingresar: ");
    scanf("%d", &cantidadNumeros);

    // Verificar que la cantidad sea mayor que 0
    if (cantidadNumeros <= 0) {
        printf("La cantidad de números debe ser mayor que 0.\n");
        return 1;  // Salir del programa con código de error
    }

    // Crear un arreglo dinámico para almacenar los números
    int *numeros = (int *)malloc(cantidadNumeros * sizeof(int));

    // Solicitar al usuario ingresar los números
    printf("Ingrese los números uno por uno:\n");
    for (int i = 0; i < cantidadNumeros; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Llamar a la función para imprimir la información de los números
    imprimirNumeros(numeros, numeros);

    // Liberar la memoria del arreglo dinámico

    return 0;
}
