// main.c

#include <stdio.h>

// Declaración de las funciones de la biblioteca estática
int sumar(int a, int b);
int multiplicar(int a, int b);

int main() {
    // Uso de las funciones de la biblioteca estática
    int resultado_suma = sumar(5, 3);
    int resultado_multiplicacion = multiplicar(4, 2);

    // Mostrar resultados
    printf("Suma: %d\n", resultado_suma);
    printf("Multiplicación: %d\n", resultado_multiplicacion);

    return 0;
}
