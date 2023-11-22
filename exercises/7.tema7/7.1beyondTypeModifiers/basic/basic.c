#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50]; // Cadena de caracteres para el nombre
    int edad;        // Entero para la edad
    float promedio;  // Flotante para el promedio
};

int main() {
    // Declaración e inicialización del array de estudiantes
    struct Estudiante estudiantes[3] = {
        {"Alice", 20, 8.5},
        {"Bob", 22, 9.0},
        {"Charlie", 19, 7.8}
    };

    // Bucle para imprimir la información de cada estudiante
    for (int i = 0; i < 3; i++) {
        printf("Estudiante %d: %s, Edad: %d, Promedio: %.2f\n",
               i+1, estudiantes[i].nombre, estudiantes[i].edad, estudiantes[i].promedio);
    }

    return 0;
}
