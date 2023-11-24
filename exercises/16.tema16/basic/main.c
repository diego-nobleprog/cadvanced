// main.c
// Programa principal que utiliza libmathstatic.a y libmathdynamic.so

#include <stdio.h>
#include "mathoperations.h" // Incluye las declaraciones de add y subtract

int main() {
    int x = 10, y = 5;
    printf("Suma: %d\n", add(x, y));        // Uso de la función add de libmathstatic.a
    printf("Resta: %d\n", subtract(x, y));  // Uso de la función subtract de libmathdynamic.so
    return 0;
}
