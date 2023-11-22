#include <stdio.h>

int main() {
    // Declaración de variables
    FILE *archivoEntrada, *archivoSalida;
    int numero, suma = 0, contador = 0;
    float promedio;

    // Abrir el archivo de entrada en modo lectura ('r')
    archivoEntrada = fopen("entrada.txt", "r");

    // Verificar si el archivo de entrada se abrió correctamente
    if (archivoEntrada == NULL) {
        printf("Error al abrir el archivo de entrada.\n");
        return 1; // Salir del programa con código de error
    }

    // Leer números desde el archivo de entrada
    while (fscanf(archivoEntrada, "%d", &numero) == 1) {
        // Sumar los números
        suma += numero;
        // Incrementar el contador de números
        contador++;
    }

    // Calcular el promedio
    promedio = (float)suma / contador;

    // Cerrar el archivo de entrada
    fclose(archivoEntrada);

    // Abrir el archivo de salida en modo escritura ('w')
    archivoSalida = fopen("salida.txt", "w");

    // Verificar si el archivo de salida se abrió correctamente
    if (archivoSalida == NULL) {
        printf("Error al abrir el archivo de salida.\n");
        return 1; // Salir del programa con código de error
    }

    // Escribir resultados en el archivo de salida
    fprintf(archivoSalida, "Suma: %d\n", suma);
    fprintf(archivoSalida, "Promedio: %.2f\n", promedio);

    // Cerrar el archivo de salida
    fclose(archivoSalida);

    // Imprimir un mensaje de éxito en la consola
    printf("Resultados guardados exitosamente en 'salida.txt'.\n");

    return 0; // Salir del programa con éxito
}
