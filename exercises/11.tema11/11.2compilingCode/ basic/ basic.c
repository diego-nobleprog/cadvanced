#include <stdio.h>

// Define la macro DEBUG
#define DEBUG

int main() {
    // Verifica si la macro DEBUG está definida
    #ifdef DEBUG
        // Imprime un mensaje si DEBUG está definida
        printf("Debug activado\n");
    #else
        // Imprime otro mensaje si DEBUG no está definida
        printf("Debug desactivado\n");
    #endif

    return 0;
}
