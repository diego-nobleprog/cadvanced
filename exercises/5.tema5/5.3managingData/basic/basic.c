#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 5
#define MAX_NOMBRE 50

// Estructura para almacenar datos de un estudiante
typedef struct {
    char nombre[MAX_NOMBRE];
    float calificacion;
} Estudiante;

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES]; // Array para almacenar estudiantes
    int numEstudiantes = 0; // Contador de estudiantes

    // Ingreso de datos de estudiantes
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        fgets(estudiantes[i].nombre, MAX_NOMBRE, stdin);
        estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")] = 0; // Remueve el salto de línea

        printf("Ingrese la calificación de %s: ", estudiantes[i].nombre);
        scanf("%f", &estudiantes[i].calificacion);
        getchar(); // Captura el carácter de nueva línea

        numEstudiantes++;
    }

    // Mostrar los datos ingresados
    printf("\nLista de Estudiantes:\n");
    for (int i = 0; i < numEstudiantes; i++) {
        printf("%s: %.2f\n", estudiantes[i].nombre, estudiantes[i].calificacion);
    }

    return 0;
}
