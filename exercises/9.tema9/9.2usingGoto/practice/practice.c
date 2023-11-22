#include <stdio.h>

int main() {
    // Declaración de variables
    char operador;
    float num1, num2, resultado;

    // Etiqueta para el inicio del programa
    inicio:

    // Mostramos el menú de operaciones
    printf("=== Calculadora Básica ===\n");
    printf("Ingrese la operación (+, -, *, /) o 'q' para salir: ");
    scanf(" %c", &operador);

    // Verificamos si el usuario quiere salir
    if (operador == 'q' || operador == 'Q') {
        printf("Saliendo de la calculadora. ¡Hasta luego!\n");
        return 0;
    }

    // Solicitamos dos números al usuario
    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);

    // Uso de switch para realizar la operación seleccionada
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2f\n", resultado);
            } else {
                printf("Error: División por cero.\n");
            }
            break;
        default:
            printf("Operador no válido. Inténtelo de nuevo.\n");
            // Volvemos al inicio del programa si la operación no es válida
            goto inicio;
    }

    // Volvemos al inicio del programa después de realizar una operación
    goto inicio;
}
