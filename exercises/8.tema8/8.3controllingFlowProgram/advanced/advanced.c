#include <stdio.h>

// Definición de los estados del semáforo
enum Estado {
    ROJO,
    VERDE,
    AMARILLO
};

int main() {
    // Inicialización del semáforo en el estado rojo
    enum Estado estadoActual = ROJO;

    // Bucle principal para simular el funcionamiento continuo del semáforo
    while (1) {
        // Imprimir el estado actual del semáforo
        printf("Estado actual del semáforo: ");
        switch (estadoActual) {
            case ROJO:
                printf("Rojo\n");
                break;
            case VERDE:
                printf("Verde\n");
                break;
            case AMARILLO:
                printf("Amarillo\n");
                break;
        }

        // Solicitar al usuario ingresar un comando
        char comando;
        printf("Ingrese 'n' para siguiente estado automático o 'm' para cambio manual: ");
        scanf(" %c", &comando);

        // Lógica de cambio de estado
        if (comando == 'n') {
            // Cambio automático de estado siguiendo la secuencia
            estadoActual = (estadoActual + 1) % 3;
        } else if (comando == 'm') {
            // Cambio manual de estado
            printf("Ingrese el nuevo estado ('r' para rojo, 'v' para verde, 'a' para amarillo): ");
            char nuevoEstado;
            scanf(" %c", &nuevoEstado);

            // Lógica para el cambio manual
            switch (nuevoEstado) {
                case 'r':
                    estadoActual = ROJO;
                    break;
                case 'v':
                    estadoActual = VERDE;
                    break;
                case 'a':
                    estadoActual = AMARILLO;
                    break;
                default:
                    printf("Comando no reconocido. El semáforo permanece en el estado actual.\n");
            }
        } else {
            // Manejo de comandos no reconocidos
            printf("Comando no reconocido. El semáforo permanece en el estado actual.\n");
        }
    }

    return 0;
}
