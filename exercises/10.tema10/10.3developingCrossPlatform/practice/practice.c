#include <stdio.h>

int main() {
    // Abre el archivo en modo lectura
    FILE *file = fopen("input.txt", "r");

    // Verifica si el archivo se abrió correctamente
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int lineCount = 0;
    char ch;

    // Lee cada caracter del archivo
    while ((ch = fgetc(file)) != EOF) {
        // Si encuentra un salto de línea, incrementa el contador de líneas
        if (ch == '\n') {
            lineCount++;
        }
    }

    // Cierra el archivo
    fclose(file);

    // Imprime el resultado
    printf("La cantidad de líneas en el archivo es: %d\n", lineCount);

    return 0;
}
