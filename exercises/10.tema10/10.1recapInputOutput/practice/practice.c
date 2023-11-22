#include <stdio.h>

int main() {
    // Declaración de variables
    int numero, suma = 0, contador = 0;

    // Mensaje de bienvenida
    printf("Bienvenido al programa de cálculo de suma y promedio.\n");
    printf("Ingresa tus números uno por uno. Para finalizar, ingresa -1.\n");

    // Ciclo para ingresar números
    while (1) {
        // Solicitar al usuario que ingrese un número
        printf("Ingresa un número (-1 para finalizar): ");
        
        // Leer el número desde la entrada estándar
        scanf("%d", &numero);

        // Verificar si el usuario quiere finalizar
        if (numero == -1) {
            break; // Salir del bucle si se ingresa -1
        }

        // Sumar el número a la suma total
        suma += numero;

        // Incrementar el contador de números
        contador++;
    }

    // Calcular el promedio
    float promedio = (float)suma / contador;

    // Mostrar resultados en la pantalla
    printf("\nResultados:\n");
    printf("Suma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);

    return 0; // Salir del programa con éxito
}
