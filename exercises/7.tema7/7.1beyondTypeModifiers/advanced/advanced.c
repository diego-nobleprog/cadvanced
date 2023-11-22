#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante *estudiantes;
    int n;

    // Solicitar al usuario el número de estudiantes
    printf("Ingrese el número de estudiantes: ");
    scanf("%d", &n);
    getchar(); // Captura el salto de línea después de ingresar el número

    // Asignación dinámica de memoria para n estudiantes
    estudiantes = (struct Estudiante *)malloc(n * sizeof(struct Estudiante));

    // Verificación de la asignación de memoria
    if (estudiantes == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        return 1;
    }

    // Capturar datos de los estudiantes
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        fgets(estudiantes[i].nombre, 50, stdin);
        estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")] = 0; // Elimina el salto de línea

        printf("Ingrese la edad del estudiante %d: ", i + 1);
        scanf("%d", &estudiantes[i].edad);
        getchar(); // Captura el salto de línea después de ingresar la edad

        printf("Ingrese el promedio del estudiante %d: ", i + 1);
        scanf("%f", &estudiantes[i].promedio);
        getchar(); // Captura el salto de línea después de ingresar el promedio
    }

    // Imprimir la información de todos los estudiantes
    printf("Información de los Estudiantes:\n");
    for (int i = 0; i < n; i++) {
        printf("Estudiante %d: %s, Edad: %d, Promedio: %.2f\n",
               i + 1, estudiantes[i].nombre, estudiantes[i].edad, estudiantes[i].promedio);
    }

    // Liberar la memoria asignada
    free(estudiantes);

    return 0;
}
