#include <stdio.h>

int main() {
    // Declaración de variables para almacenar el número ingresado y los resultados de las operaciones
    int numero, cuadrado, cubo, doble;

    // Solicitar al usuario un número entero
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    // Calcula el cuadrado del número
    cuadrado = numero * numero;

    // Calcula el cubo del número
    cubo = numero * numero * numero;

    // Calcula el doble del número
    doble = numero * 2;

    // Muestra los resultados al usuario
    printf("El cuadrado del número es: %d\n", cuadrado);
    printf("El cubo del número es: %d\n", cubo);
    printf("El doble del número es: %d\n", doble);

    return 0;
}
