#include <stdio.h>

int main() {
    // Abre el archivo "datos.txt" en modo lectura
    FILE *archivo = fopen("datos.txt", "r");

    // Verifica si se pudo abrir el archivo correctamente
    if (archivo != NULL) {
        char linea[100]; // Se asume una longitud máxima de línea de 100 caracteres

        // Inicializa el contador de líneas
        int contadorLineas = 0;

        // Lee el archivo línea por línea hasta llegar al final
        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            // Imprime la línea en la consola
            printf("Línea %d: %s", contadorLineas + 1, linea);

            // Incrementa el contador de líneas
            contadorLineas++;
        }

        // Cierra el archivo
        fclose(archivo);

        // Imprime la cantidad total de líneas
        printf("\n\nTotal de líneas en el archivo: %d\n", contadorLineas);
    } else {
        // Imprime un mensaje si no se pudo abrir el archivo
        printf("No se pudo abrir el archivo.\n");
    }

    return 0;
}
