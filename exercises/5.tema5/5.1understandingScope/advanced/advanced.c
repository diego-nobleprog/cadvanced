#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50

// Estructura para un contacto
typedef struct {
    char nombre[MAX_NOMBRE];
    char telefono[15];
} Contacto;

// Prototipos de funciones
Contacto *agregarContacto(Contacto *libreta, int *tam, const char *nombre, const char *telefono);
void eliminarContacto(Contacto *libreta, int *tam, const char *nombre);
void mostrarLibreta(Contacto *libreta, int tam);

int main() {
    Contacto *libreta = NULL; // Inicializa un puntero a NULL para la libreta de direcciones
    int tam = 0; // Contador de contactos

    // Agregar contactos (simulado para el ejemplo)
    libreta = agregarContacto(libreta, &tam, "Juan Perez", "123456789");
    libreta = agregarContacto(libreta, &tam, "Ana Lopez", "987654321");

    mostrarLibreta(libreta, tam); // Mostrar todos los contactos

    eliminarContacto(libreta, &tam, "Juan Perez"); // Eliminar un contacto

    mostrarLibreta(libreta, tam); // Mostrar todos los contactos nuevamente

    free(libreta); // Liberar la memoria asignada a la libreta
    return 0;
}

Contacto *agregarContacto(Contacto *libreta, int *tam, const char *nombre, const char *telefono) {
    libreta = realloc(libreta, (*tam + 1) * sizeof(Contacto)); // Aumenta el tamaño del array dinámicamente
    strcpy(libreta[*tam].nombre, nombre);
    strcpy(libreta[*tam].telefono, telefono);
    (*tam)++;
    return libreta; // Devuelve el puntero actualizado
}

void eliminarContacto(Contacto *libreta, int *tam, const char *nombre) {
    for (int i = 0; i < *tam; i++) {
        if (strcmp(libreta[i].nombre, nombre) == 0) {
            // Desplaza todos los contactos después del eliminado una posición hacia atrás
            for (int j = i; j < *tam - 1; j++) {
                libreta[j] = libreta[j + 1];
            }
            (*tam)--;
            libreta = realloc(libreta, (*tam) * sizeof(Contacto)); // Reduce el tamaño del array
            break;
        }
    }
}

void mostrarLibreta(Contacto *libreta, int tam) {
    printf("Libreta de Direcciones:\n");
    for (int i = 0; i < tam; i++) {
        printf("Nombre: %s, Teléfono: %s\n", libreta[i].nombre, libreta[i].telefono);
    }
}
