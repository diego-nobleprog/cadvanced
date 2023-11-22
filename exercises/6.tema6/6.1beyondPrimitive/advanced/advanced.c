#include <stdio.h>
#include <stdlib.h>

#define MAX_HABITACIONES 100

// Estructura para una habitación
typedef struct {
    int numero;
    char tipo; // 'S' para sencilla, 'D' para doble
    float precio;
} Habitacion;

// Prototipos de funciones
void agregarHabitacion(Habitacion **habitaciones, int *n, int numero, char tipo, float precio);
void mostrarHabitaciones(Habitacion *habitaciones, int n);

int main() {
    Habitacion *habitaciones = NULL; // Puntero para array dinámico de habitaciones
    int n = 0; // Contador de habitaciones

    // Agregar habitaciones
    agregarHabitacion(&habitaciones, &n, 101, 'S', 50.0);
    agregarHabitacion(&habitaciones, &n, 102, 'D', 75.0);

    // Mostrar habitaciones
    mostrarHabitaciones(habitaciones, n);

    // Liberar memoria
    free(habitaciones);
    return 0;
}

void agregarHabitacion(Habitacion **habitaciones, int *n, int numero, char tipo, float precio) {
    if (*n < MAX_HABITACIONES) {
        *habitaciones = realloc(*habitaciones, (*n + 1) * sizeof(Habitacion));
        if (*habitaciones == NULL) {
            perror("Error al asignar memoria");
            exit(EXIT_FAILURE);
        }
        (*habitaciones)[*n].numero = numero;
        (*habitaciones)[*n].tipo = tipo;
        (*habitaciones)[*n].precio = precio;
        (*n)++;
    } else {
        printf("Límite de habitaciones alcanzado.\n");
    }
}

void mostrarHabitaciones(Habitacion *habitaciones, int n) {
    for (int i = 0; i < n; i++) {
        printf("Habitación %d: Tipo %c, Precio: $%.2f\n", habitaciones[i].numero, habitaciones[i].tipo, habitaciones[i].precio);
    }
}
