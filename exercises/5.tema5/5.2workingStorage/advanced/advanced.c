// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int maxUsuarios; // Declaración de la variable externa
void agregarUsuario(const char *nombre);

int main() {
    maxUsuarios = 3; // Configuración global
    agregarUsuario("Alice");
    agregarUsuario("Bob");
    agregarUsuario("Charlie");

    return 0;
}

void agregarUsuario(const char *nombre) {
    static int contadorUsuarios = 0; // Variable estática para contar usuarios
    if (contadorUsuarios < maxUsuarios) {
        printf("Agregando usuario: %s\n", nombre);
        contadorUsuarios++;
    } else {
        printf("No se pueden agregar más usuarios.\n");
    }
}
