#include <stdio.h>

// Prototipo de la función que incrementa el contador
void incrementarContador();

int main() {
    // Llamada a la función varias veces
    for (int i = 0; i < 5; i++) {
        incrementarContador();
    }
    return 0;
}

// Función que incrementa un contador estático
void incrementarContador() {
    static int contador = 0; // Variable estática: mantiene su valor entre llamadas
    contador++; // Incrementa el contador
    printf("La función ha sido llamada %d veces.\n", contador);
}
