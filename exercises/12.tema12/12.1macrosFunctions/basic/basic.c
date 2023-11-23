#include <stdio.h>

// Definición de la macro SQUARE
// Esta macro toma un parámetro (x) y lo multiplica por sí mismo.
#define SQUARE(x) ((x) * (x))

// Definición de la función square
// Esta función toma un parámetro (num) y devuelve su cuadrado.
int square(int num) {
    return num * num;
}

int main() {
    int number = 4;

    // Uso de la macro SQUARE
    // Calcula el cuadrado de 'number' usando la macro.
    int squareMacro = SQUARE(number);

    // Uso de la función square
    // Calcula el cuadrado de 'number' usando la función.
    int squareFunction = square(number);

    // Imprime los resultados
    printf("Cuadrado usando macro: %d\n", squareMacro);
    printf("Cuadrado usando función: %d\n", squareFunction);

    return 0;
}
