#include <stdio.h>

int main() {
    #ifdef __APPLE__
        // Código específico para macOS
        printf("Hola desde macOS\n");
    #else
        // Código para otras plataformas UNIX
        printf("Saludos desde UNIX\n");
    #endif

    return 0;
}
