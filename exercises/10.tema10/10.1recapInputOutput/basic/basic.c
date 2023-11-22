#include <stdio.h>

int main() {
    // Declaración de variables para almacenar nombre y edad
    char nombre[50];
    int edad;

    // Solicitar al usuario que ingrese su nombre
    printf("Ingresa tu nombre: ");
    
    // Leer el nombre desde la entrada estándar y almacenarlo en la variable 'nombre'
    scanf("%s", nombre);

    // Solicitar al usuario que ingrese su edad
    printf("Ingresa tu edad: ");
    
    // Leer la edad desde la entrada estándar y almacenarla en la variable 'edad'
    scanf("%d", &edad);

    // Abrir un archivo en modo escritura ('w')
    FILE *archivo;
    archivo = fopen("datos.txt", "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1; // Salir del programa con código de error
    }

    // Escribir en el archivo utilizando fprintf
    fprintf(archivo, "Nombre: %s\n", nombre);
    fprintf(archivo, "Edad: %d\n", edad);

    // Cerrar el archivo
    fclose(archivo);

    // Imprimir un mensaje de éxito en la consola
    printf("Datos guardados exitosamente en 'datos.txt'.\n");

    return 0; // Salir del programa con éxito
}
