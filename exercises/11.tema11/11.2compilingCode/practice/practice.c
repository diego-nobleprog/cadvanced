#include <stdio.h>

// Define las macros MACOS y LINUX
#define MACOS
// #define LINUX  // Comenta o descomenta esta línea para cambiar la plataforma

int main() {
    // Comprueba si la macro MACOS está definida
    #ifdef MACOS
        printf("Compilado en macOS\n");
    // Comprueba si la macro LINUX está definida
    #elif defined(LINUX)
        printf("Compilado en Linux\n");
    // Si ninguna macro está definida
    #else
        printf("Plataforma desconocida\n");
    #endif

    return 0;
}
