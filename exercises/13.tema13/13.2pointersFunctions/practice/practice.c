#include <stdio.h>

// Funciones de comparación
int ascendente(int a, int b) {
    return a > b;
}

int descendente(int a, int b) {
    return a < b;
}

// Algoritmo de ordenamiento por burbuja utilizando un puntero a función
void ordenar(int *array, int size, int (*comparar)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comparar(array[j], array[j + 1])) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Función principal
int main() {
    int miArray[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(miArray) / sizeof(miArray[0]);

    // Ordena el array en orden ascendente
    ordenar(miArray, size, ascendente);

    // Imprime el array ordenado
    printf("Array Ordenado (Ascendente): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", miArray[i]);
    }
    printf("\n");

    // Ordena el array en orden descendente
    ordenar(miArray, size, descendente);

    // Imprime el array ordenado
    printf("Array Ordenado (Descendente): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", miArray[i]);
    }
    printf("\n");

    return 0;
}
