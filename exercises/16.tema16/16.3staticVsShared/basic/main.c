// main.c
#include <stdio.h>
#include "basic_operations.h"
#include "advanced_operations.h"

int main() {
    // Operaciones Básicas
    int result_add = add(5, 3);
    int result_subtract = subtract(10, 4);

    // Operaciones Avanzadas
    int result_multiply = multiply(6, 7);
    int result_divide = divide(15, 3);

    // Mostrar resultados
    printf("Suma: %d\n", result_add);
    printf("Resta: %d\n", result_subtract);
    printf("Multiplicación: %d\n", result_multiply);
    printf("División: %d\n", result_divide);

    return 0;
}
