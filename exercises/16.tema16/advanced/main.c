// Programa principal que utiliza ambas bibliotecas
#include <stdio.h>
#include "mathoperations.h"

int main() {
    int x = 10, y = 5;
    printf("Suma: %d\n", add(x, y)); // Uso de la función add
    printf("Resta: %d\n", subtract(x, y)); // Uso de la función subtract
    printf("Multiplicación: %d\n", multiply(x, y)); // Uso de la función multiply
    printf("División: %d\n", divide(x, y)); // Uso de la función divide
    return 0;
}
