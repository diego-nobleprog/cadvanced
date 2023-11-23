#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define la estructura de un estudiante
typedef struct Estudiante {
    char nombre[50];
    int calificacion;
    struct Estudiante *siguiente;
} Estudiante;

// Agrega un nuevo estudiante a la lista
void agregarEstudiante(Estudiante **cabeza, char *nombre, int calificacion) {
    Estudiante *nuevo = (Estudiante *)malloc(sizeof(Estudiante)); // Asigna memoria para el nuevo estudiante
    strcpy(nuevo.nombre, nombre); // Copia el nombre al estudiante
    nuevo.calificacion = calificacion; // Establece la calificación del estudiante
    nuevo.siguiente = *cabeza; // El siguiente del nuevo estudiante es la cabeza actual
    *cabeza = nuevo; // La cabeza ahora es el nuevo estudiante
}

// Muestra todos los estudiantes en la lista
void mostrarEstudiantes(Estudiante *cabeza) {
    Estudiante *actual = cabeza; // Comienza desde la cabeza de la lista
    while (actual != NULL) { // Recorre mientras haya estudiantes
        printf("Nombre: %s, Calificación: %d\n", actual->nombre, actual->calificacion); // Muestra los datos del estudiante
        actual = actual->siguiente; // Avanza al siguiente estudiante
    }
}

int main() {
    Estudiante *cabeza = NULL; // Inicia la lista como vacía

    // Agrega estudiantes a la lista

    // Muestra los estudiantes

    // Libera la memoria asignada

    return 0;
}
