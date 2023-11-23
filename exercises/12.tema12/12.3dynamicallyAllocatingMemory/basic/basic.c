#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros; // Puntero para almacenar los números
    int cantidad; // Almacena la cantidad de números a ingresar

    // Solicita al usuario la cantidad de números
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &cantidad);

    // Asigna memoria para la cantidad de números
    numeros = (int *)malloc(cantidad * sizeof(int)); 
    if (numeros == NULL) { // Verifica si la asignación fue exitosa
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Loop para ingresar los números
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Muestra los números ingresados
    printf("Los números ingresados son:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Libera la memoria asignada
    free(numeros);

    return 0;
}
