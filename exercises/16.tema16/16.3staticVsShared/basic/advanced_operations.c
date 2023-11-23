// advanced_operations.c
#include "advanced_operations.h"

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        return -1; // Indicador de error para división por cero
    }
    return a / b;
}
