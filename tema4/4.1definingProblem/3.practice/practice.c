#include <stdio.h>

int main() {
    int numero1, numero2, suma;

    printf("Introduce el primer número: "); // Pide al usuario el primer número
    scanf("%d", &numero1); // Lee el primer número

    printf("Introduce el segundo número: "); // Pide al usuario el segundo número
    scanf("%d", &numero2); // Lee el segundo número

    suma = numero1 + numero2; // Suma los dos números

    printf("La suma de %d y %d es %d.\n", numero1, numero2, suma); // Imprime el resultado

    return 0; // Termina el programa con éxito
}
