#include <stdio.h>

// Directiva condicional: verificar si DEBUG está definido
#ifdef DEBUG
    #define DEBUG_MSG(msg) printf("DEBUG: %s\n", msg)
#else
    #define DEBUG_MSG(msg)
#endif

// Función de impresión adicional para mensajes detallados
#ifdef DEBUG
    void imprimirDetalles() {
        printf("Detalles de la versión de depuración.\n");
    }
#else
    // Si DEBUG no está definido, la función no se incluye
    #define imprimirDetalles()
#endif

int main() {
    // Mensaje para indicar el inicio del programa
    printf("Inicio del programa.\n");

    // Llamada a la función de impresión de mensajes de depuración
    DEBUG_MSG("Este es un mensaje de depuración.");

    // Llamada a la función de impresión adicional (solo en versión de depuración)
    imprimirDetalles();

    // Resto del código del programa

    // Mensaje para indicar el final del programa
    printf("Fin del programa.\n");

    return 0;
}
