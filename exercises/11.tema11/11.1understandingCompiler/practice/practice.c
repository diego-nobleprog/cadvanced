#include stdio.h>

// Función para calcular el factorial de un número
unsigned long long calcularFactorial(int n) {
    unsigned long long resultado = 1;

    // Ciclo para calcular el factorial
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }

    return resultado;
}

int main() {
    // Número para calcular el factorial
    int numero;

    // Solicitar al usuario que ingrese un número
    printf("Ingrese un número para calcular el factorial: ");
    scanf("%d", &numero);

    // Desactivar la advertencia de desbordamiento de enteros utilizando #pragma
    #pragma GCC diagnostic ignored "-Woverflow"

    // Calcular y mostrar el factorial
    printf("El factorial de %d es %llu\n", numero, (numero));

    return 0;
}
