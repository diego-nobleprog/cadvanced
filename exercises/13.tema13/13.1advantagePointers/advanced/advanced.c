#include <stdio.h>
#include <stdlib.h>

// Realiza la transposición de una matriz
void transponerMatriz(int **matriz, int filas, int columnas) {
    int **transpuesta = (int **)malloc(columnas * sizeof(int *));
    for (int i = 0; i < columnas; i++) {
        transpuesta[i] = (int *)malloc(filas * sizeof(int));
        for (int j = 0; j < filas; j++) {
            transpuesta[i][j] = matriz[j][i]; // Intercambia filas por columnas
        }
    }

    // Imprime la matriz transpuesta
    printf("Matriz Transpuesta:\n");
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            printf("%d ", transpuesta[i][j]);
        }
        printf("\n");
        free(transpuesta[i]); // Libera la memoria de la fila
    }
    free(transpuesta); // Libera la memoria de la matriz
}

int main() {
    int filas = 3, columnas = 3;
    int **matriz = (int **)malloc(filas * sizeof(int *));

    // Inicializa y llena la matriz
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i + j; // Valor de ejemplo
        }
    }

    // Llama a la función para transponer la matriz
    transponerMatriz(matriz, filas, columnas);

    // Libera la memoria de la matriz original
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
