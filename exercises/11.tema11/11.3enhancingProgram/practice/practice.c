#include <stdio.h>

// Función para sumar dos arreglos de enteros con optimización de caché
void sum_arrays_cache_optimized(int *array1, int *array2, int *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = array1[i] + array2[i];
    }
}

int main() {
    // Definir arreglos de ejemplo
    int array1[1000];
    int array2[1000];
    int result[1000];

    // Inicializar arreglos con datos de ejemplo
    for (int i = 0; i < 1000; i++) {
        array1[i] = i;
        array2[i] = i * 2;
    }

    // Llamar a la función optimizada para sumar los arreglos
    sum_arrays_cache_optimized(array1, array2, result, 1000);

    // Imprimir algunos resultados para verificar
    printf("Resultados de la suma de arreglos:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d + %d = %d\n", array1[i], array2[i], result[i]);
    }

    return 0;
}
