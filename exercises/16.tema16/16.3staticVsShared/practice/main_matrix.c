// main_matrix.c
#include <stdio.h>
#include "matrix_basic_operations.h"
#include "matrix_advanced_operations.h"

int main() {
    const int rows = 3;
    const int cols = 3;

    int matrix_a[rows][cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix_b[rows][cols] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[rows][cols];

    // Operaciones Básicas
    matrix_add((int *)matrix_a, (int *)matrix_b, (int *)result, rows, cols);

    // Operaciones Avanzadas
    matrix_transpose((int *)matrix_a, (int *)result, rows, cols);

    // Mostrar resultados
    printf("Matriz Resultante:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
