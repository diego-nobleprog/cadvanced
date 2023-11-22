#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Biblioteca específica de UNIX para funciones como sleep

// Definición de constantes
const int MAX_EVENTS = 10; // Número máximo de eventos permitidos

// Declaración de una variable 'volatile' para simular la llegada de eventos
volatile int eventCount = 0;

int main() {
    while (1) {
        // Simulación de la llegada de un evento
        eventCount++;

        // Verificar si se ha alcanzado el número máximo de eventos
        if (eventCount >= MAX_EVENTS) {
            printf("Alerta: Se ha alcanzado el máximo número de eventos (%d)\n", eventCount);
            exit(0); // Finalizar el programa
        }

        // Mensaje indicando el número actual de eventos
        printf("Evento %d registrado\n", eventCount);

        sleep(1); // Esperar 1 segundo antes del próximo evento (función específica de UNIX)
    }
    return 0;
}
