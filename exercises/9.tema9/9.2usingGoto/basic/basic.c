#include <stdio.h>

int main() {
    int contador = 10;  // Inicializamos el contador en 10

    inicio:  // Etiqueta para el inicio
    printf("Contador: %d\n", contador);  // Mostramos el valor del contador

    if (contador == 0) {
        goto fin;  // Saltamos a la etiqueta "fin" si el contador llega a 0
    }

    contador--;  // Decrementamos el contador

    goto inicio;  // Volvemos al inicio del bucle

    fin:  // Etiqueta para el final
    printf("Cuenta regresiva terminada.\n");

    return 0;
}
