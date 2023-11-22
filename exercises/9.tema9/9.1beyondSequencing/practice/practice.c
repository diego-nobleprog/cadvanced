#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    float calificacion;
};

int main() {
    FILE *archivoEntrada, *archivoSalida;
    struct Estudiante estudiante;
    float sumaCalificaciones = 0;
    int contadorEstudiantes = 0;

    // Abre el archivo de entrada "estudiantes.txt" en modo lectura
    archivoEntrada = fopen("estudiantes.txt", "r");
    if (archivoEntrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    // Lee la información de cada estudiante desde el archivo de entrada
    while (fscanf(archivoEntrada, "%s %f", estudiante.nombre, &estudiante.calificacion) == 2) {
        // Suma las calificaciones para calcular el promedio posteriormente
        sumaCalificaciones += estudiante.calificacion;
        contadorEstudiantes++;
    }

    // Cierra el archivo de entrada
    fclose(archivoEntrada);

    // Abre el archivo de salida "promedio.txt" en modo escritura
    archivoSalida = fopen("promedio.txt", "w");
    if (archivoSalida == NULL) {
        perror("Error al abrir el archivo de salida");
        return 1;
    }

    // Calcula el promedio de las calificaciones
    float promedio = sumaCalificaciones / contadorEstudiantes;

    // Escribe en el archivo de salida el estudiante con la calificación promedio
    fprintf(archivoSalida, "Estudiante con calificación promedio:\n");
    fprintf(archivoSalida, "Nombre: %s\n", estudiante.nombre);
    fprintf(archivoSalida, "Calificación: %.2f\n", promedio);

    // Cierra el archivo de salida
    fclose(archivoSalida);

    return 0;
}
