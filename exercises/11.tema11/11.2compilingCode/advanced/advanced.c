#include <stdio.h>

// Define la macro ENABLE_FILE_READ
#define ENABLE_FILE_READ

int main() {
    // Comprueba si la macro ENABLE_FILE_READ está definida
    #ifdef ENABLE_FILE_READ
        FILE *file = fopen("datos.txt", "r");  // Abre el archivo en modo lectura
        if (file != NULL) {
            char buffer[100];  // Buffer para almacenar el contenido del archivo

            // Lee el contenido del archivo y lo imprime
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("Contenido del archivo: %s", buffer);
            }

            fclose(file);  // Cierra el archivo después de la lectura
        } else {
            printf("No se pudo abrir el archivo.\n");
        }
    #else
        printf("La funcionalidad de lectura de archivos está desactivada.\n");
    #endif

    return 0;
}
