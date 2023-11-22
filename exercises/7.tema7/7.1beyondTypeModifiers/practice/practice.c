#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Prototipo de la función de búsqueda
struct Estudiante *buscarEstudiante(struct Estudiante *estudiantes, int n, char *nombre);

int main() {
    struct Estudiante *estudiantes;
    int n;
    char nombreBusqueda[50];

    // Solicitar el número de estudiantes
    printf("Ingrese el número de estudiantes: ");
    scanf("%d", &n);
    getchar(); // Captura el salto de línea

    // Asignación dinámica de memoria
    estudiantes = (struct Estudiante *)malloc(n * sizeof(struct Estudiante));

    // Captura de datos de los estudiantes
    for (int i = 0; i < n; i++) {
        printf("Nombre del estudiante %d: ", i + 1);
        fgets(estudiantes[i].nombre, 50, stdin);
        estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")] = 0; // Eliminar salto de línea
        printf("Edad: ");
        scanf("%d", &estudiantes[i].edad);
        printf("Promedio: ");
        scanf("%f", &estudiantes[i].promedio);
        getchar(); // Captura el salto de línea
    }

    // Búsqueda de estudiante
    printf("Ingrese el nombre del estudiante a buscar: ");
    fgets(nombreBusqueda, 50, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = 0; // Eliminar salto de línea

    struct Estudiante *encontrado = buscarEstudiante(estudiantes, n, nombreBusqueda);

    // Mostrar resultados de la búsqueda
    if (encontrado != NULL) {
        printf("Estudiante encontrado: %s, Edad: %d, Promedio: %.2f\n",
               encontrado->nombre, encontrado->edad, encontrado->promedio);
    } else {
        printf("Estudiante no encontrado.\n");
    }

    // Liberar memoria
    free(estudiantes);

    return 0;
}

// Función para buscar un estudiante por nombre
struct Estudiante *buscarEstudiante(struct Estudiante *estudiantes, int n, char *nombre) {
    for (int i = 0; i < n; i++) {
        if (strcmp(estudiantes[i].nombre, nombre) == 0) {
            return &estudiantes[i];
        }
    }
    return NULL;
}
