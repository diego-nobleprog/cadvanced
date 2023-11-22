#include <stdio.h>

int main() {
    // Declaración de variables para almacenar los números ingresados por el usuario
    int num1, num2;

    // Solicitar al usuario que ingrese el primer número
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    // Solicitar al usuario que ingrese el segundo número
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    // Realizar la suma de los dos números
    int suma = num1 + num2;

    // Mostrar el resultado en la pantalla
    printf("La suma de %d y %d es: %d\n", num1, num2, suma);

    return 0;
}
