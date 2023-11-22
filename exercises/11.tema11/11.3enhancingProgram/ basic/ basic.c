#include <stdio.h>

int sum_array(int *array, int n) {
    int result = 0;

    // Bucle de suma a optimizar
    for (int i = 0; i < n; i++) {
        result += array[i];
    }

    return result;
}

int main() {
    // Definir un array de ejemplo
    int myArray[] = {1, 2, 3, 4, 5};

    // Obtener la longitud del array
    int arrayLength = sizeof(myArray) / sizeof(myArray[0]);

    // Llamar a la función de suma y mostrar el resultado
    int sumResult = sum_array(myArray, arrayLength);
    printf("La suma de los elementos del array es: %d\n", sumResult);

    return 0;
}
