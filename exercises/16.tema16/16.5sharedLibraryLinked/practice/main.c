// main.c

#include <stdio.h>

// Estructura para representar a un estudiante
typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

// Declaración de las funciones de la biblioteca estática
void agregarEstudiante(Estudiante *estudiantes, int *contador, const char *nombre, int edad, float promedio);
void mostrarInformacion(Estudiante estudiante);
void modificarInformacion(Estudiante *estudiante, const char *nuevoNombre, int nuevaEdad, float nuevoPromedio);

int main() {
    // Uso de las funciones de la biblioteca estática
    int contador = 0;
    Estudiante estudiantes[50];

    agregarEstudiante(estudiantes, &contador, "Juan", 20, 85.5);
    agregarEstudiante(estudiantes, &contador, "María", 22, 78.9);

    printf("Información del primer estudiante:\n");
    mostrarInformacion(estudiantes[0]);

    printf("\nModificando la información del segundo estudiante:\n");
    modificarInformacion(&estudiantes[1], "Carlos", 21, 92.3);
    mostrarInformacion(estudiantes[1]);

    return 0;
}
