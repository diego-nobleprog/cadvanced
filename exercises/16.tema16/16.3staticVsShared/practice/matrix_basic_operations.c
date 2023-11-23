// matrix_basic_operations.c
#include "matrix_basic_operations.h"

void matrix_add(int *a, int *b, int *result, int rows, int cols) {
    for (int i = 0; i < rows * cols; ++i) {
        result[i] = a[i] + b[i];
    }
}

void matrix_subtract(int *a, int *b, int *result, int rows, int cols) {
    for (int i = 0; i < rows * cols; ++i) {
        result[i] = a[i] - b[i];
    }
}
