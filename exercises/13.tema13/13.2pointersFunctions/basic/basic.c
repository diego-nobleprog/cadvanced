#include <stdio.h>

// Declaraciones de funciones para operaciones matemáticas
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicacion(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    return a / b; // Nota: No se maneja la división por cero en este ejemplo
}

// Función principal
int main() {
    int x = 10, y = 5;
    int resultado;
    int operacion;

    // Puntero a función para operaciones matemáticas
    int (*punteroFuncion)(int, int);

    printf("Ingrese la operación a realizar (1=Suma, 2=Resta, 3=Multiplicación, 4=División): ");
    scanf("%d", &operacion);

    // Seleccionar la operación mediante puntero a función
    switch (operacion) {
        case 1: 
            punteroFuncion = suma;
            break;
        case 2: 
            punteroFuncion = resta;
            break;
        case 3: 
            punteroFuncion = multiplicacion;
            break;
        case 4: 
            punteroFuncion = division;
            break;
        default:
            printf("Operación no válida\n");
            return 1;
    }

    // Ejecutar la operación seleccionada
    resultado = punteroFuncion(x, y);
    printf("Resultado: %d\n", resultado);

    return 0;
}
