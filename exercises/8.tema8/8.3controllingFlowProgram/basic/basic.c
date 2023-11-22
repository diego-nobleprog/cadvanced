#include <stdio.h>

int main() {
    // Paso 1: Solicitar al usuario ingresar un número
    int numero;
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    // Inicializar la variable de suma
    int suma = 0;

    // Paso 2: Utilizar un bucle for para iterar desde 1 hasta el número ingresado
    for (int i = 1; i <= numero; ++i) {
        // Paso 3: Verificar si el número es par y no divisible por 4
        if (i % 2 == 0 && i % 4 != 0) {
            // Paso 4: Imprimir el número y acumular en la variable de suma
            printf("%d ", i);
            suma += i;
        }
    }

    // Paso 5: Mostrar la suma total
    printf("\nLa suma total de los números pares excluyendo los divisibles por 4 es: %d\n", suma);

    return 0;
}
