#include <stdio.h>

// Definición de la estructura Estudiante
typedef struct {
    int id;
    char nombre[50];
} Estudiante;

// Función principal
int main() {
    Estudiante estudiantes[10]; // Array para almacenar hasta 10 estudiantes
    int numeroEstudiantes = 0;  // Contador para la cantidad de estudiantes
    int opcion;                 // Variable para almacenar la opción del usuario

    // Bucle principal del programa
    while (1) {
        // Mostrar menú al usuario
        printf("\n1. Agregar Estudiante\n");
        printf("2. Mostrar Estudiantes\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        // Procesar la opción elegida
        if (opcion == 1) {
            // Opción para agregar un estudiante
            if (numeroEstudiantes < 10) {
                printf("Introduce el ID del estudiante: ");
                scanf("%d", &estudiantes[numeroEstudiantes].id);
                printf("Introduce el nombre del estudiante: ");
                scanf("%s", estudiantes[numeroEstudiantes].nombre);
                numeroEstudiantes++;
            } else {
                printf("Límite de estudiantes alcanzado.\n");
            }
        } else if (opcion == 2) {
            // Opción para mostrar todos los estudiantes
            printf("Lista de estudiantes:\n");
            for (int i = 0; i < numeroEstudiantes; i++) {
                printf("ID: %d, Nombre: %s\n", estudiantes[i].id, estudiantes[i].nombre);
            }
        } else if (opcion == 3) {
            // Opción para salir del programa
            break;
        } else {
            // Opción no válida
            printf("Opción no válida. Por favor intenta de nuevo.\n");
        }
    }

    return 0; // Termina el programa con éxito
}
