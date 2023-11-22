#include <stdio.h>

// Función para contar bits activos en un número
int contarBitsActivos(int numero) {
    int contador = 0;

    // Recorre cada bit del número
    while (numero != 0) {
        // Utiliza la operación AND para verificar si el bit menos significativo es 1
        contador += numero & 1;

        // Desplaza el número a la derecha para analizar el siguiente bit
        numero >>= 1;
    }

    return contador;
}

int main() {
    // Declaración de variables
    int numero;

    // Solicitar al usuario que ingrese un número
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    // Verificar si el número ingresado es no negativo
    if (numero < 0) {
        printf("Por favor, ingrese un número no negativo.\n");
        return 1;  // Salir del programa con código de error
    }

    // Llamar a la función para contar bits activos
    int bitsActivos = contarBitsActivos(numero);

    // Mostrar el resultado
    printf("El número de bits activos en %d es: %d\n", numero, bitsActivos);

    return 0;
}
