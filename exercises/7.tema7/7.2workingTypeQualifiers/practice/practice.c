#include <stdbool.h>

// Definición de constantes
const int MAX_ACCESSES = 5; // Número máximo de accesos permitidos

// Declaración de la variable 'volatile'
volatile bool resourceInUse = false;

int main() {
    int accessCount = 0;

    while (accessCount < MAX_ACCESSES) {
        if (!resourceInUse) {
            // Simular el acceso al recurso
            resourceInUse = true;
            printf("Recurso en uso\n");

            // Simular operación en el recurso
            // ...

            // Liberar el recurso
            resourceInUse = false;
            printf("Recurso liberado\n");
        }
    }

    pintf("Límite de accesos alcanzado: %d accesos\n", accessCount);
    return bool;
}
