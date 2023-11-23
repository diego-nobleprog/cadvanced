// estudiantes.c

#include <stdio.h>

// Estructura para representar a un estudiante
typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

// Función para agregar un estudiante
void agregarEstudiante(Estudiante *estudiantes, int *contador, const char *nombre, int edad, float promedio) {
    if (*contador < 50) {
        Estudiante nuevoEstudiante;
        snprintf(nuevoEstudiante.nombre, sizeof(nuevoEstudiante.nombre), "%s", nombre);
        nuevoEstudiante.edad = edad;
        nuevoEstudiante.promedio = promedio;

        estudiantes[*contador] = nuevoEstudiante;
        (*contador)++;
    } else {
        printf("¡Error! Se ha alcanzado el límite de estudiantes.\n");
    }
}

// Función para mostrar la información de un estudiante
void mostrarInformacion(Estudiante estudiante) {
    // Mostrar información del estudiante
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %.2f\n", estudiante.promedio);
}

// Función para modificar la información de un estudiante
void modificarInformacion(Estudiante *estudiante, const char *nuevoNombre, int nuevaEdad, float nuevoPromedio) {
    // Modificar información del estudiante
    snprintf(estudiante->nombre, sizeof(estudiante->nombre), "%s", nuevoNombre);
    estudiante->edad = nuevaEdad;
    estudiante->promedio = nuevoPromedio;
}
