#include <stdio.h>

int main() {
    // Declaración de variables
    int opcion;

    // Etiqueta para el inicio del programa
    inicio:

    // Mostramos el menú de opciones
    printf("=== Menú de Gestión de Usuarios ===\n");
    printf("1. Crear Usuario\n");
    printf("2. Modificar Usuario\n");
    printf("3. Eliminar Usuario\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    // Uso de switch para manejar las opciones del menú
    switch (opcion) {
        case 1:
            printf("Opción 1: Crear Usuario\n");
            // Código para crear un usuario
            break;
        case 2:
            printf("Opción 2: Modificar Usuario\n");
            // Código para modificar un usuario
            break;
        case 3:
            printf("Opción 3: Eliminar Usuario\n");
            // Código para eliminar un usuario
            break;
        case 4:
            printf("Saliendo del programa. ¡Hasta luego!\n");
            // Salimos del programa al encontrar la opción 4
            return 0;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
            // Volvemos al inicio del programa si la opción no es válida
            goto inicio;
    }

    // Volvemos al inicio del programa después de manejar una opción
    goto inicio;
}
