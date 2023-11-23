#include <stdio.h>

/* 
 * Función para encontrar el valor máximo en un array.
 * Recibe un puntero al primer elemento del array y su tamaño.
 */
int encontrarMaximo(int *arr, int size) {
    int max = *arr; // Inicializa max al primer elemento del array

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) { // Compara max con el elemento actual del array
            max = *(arr + i); // Actualiza max si se encuentra un valor mayor
        }
    }

    return max; // Retorna el valor máximo encontrado
}

int main() {
    int numeros[] = {3, 5, 7, 2, 8, 9, 1}; // Array de enteros
    int size = sizeof(numeros) / sizeof(numeros[0]); // Calcula el tamaño del array

    // Llama a encontrarMaximo y pasa el array y su tamaño
    int max = encontrarMaximo(numeros, size);

    printf("El valor máximo en el array es: %d\n", max); // Imprime el valor máximo

    return 0;
}
