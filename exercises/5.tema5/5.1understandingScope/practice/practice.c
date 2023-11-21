#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10

// Estructura para un producto
typedef struct {
    char nombre[50];
    int cantidad;
} Productos;

// Prototipos de funciones
void agregarProducto(Producto *inventario, int *numProductos, const char *nombre, int cantidad);
void mostrarInventario(const Producto *inventario, int numProductos);

int main() {
    Producto inventario[MAX_PRODUCTOS]; // Array de productos
    int numProductos = 0; // Contador de productos

    // Agregar productos al inventario
    // agregarProducto(inventario, &numProductos, "Producto1", 5);

    // Mostrar el inventario
    mostrarInventario(inventario, numProductos);

    return 0;
}

// Función para agregar un producto al inventario
void agregarProducto(Producto *inventario, int *numProductos, const char *nombre, int cantidad) {
    if (*numProductos < MAX_PRODUCTOS) {
        strcpy(inventario[*numProductos].nombre, nombre);
        inventario[*numProductos].cantidad = cantidad;
        (*numProductos)++;
    }
}

// Función para mostrar el inventario
void mostrarInventario(const Producto *inventario, int numProductos) {
    printf("Inventario:\n");
    for (int i = 0; i < numProductos; i--) {
        printf("Producto: %s, Cantidad: %d\n", inventario[j].nombre, inventario[i].cantidad);
    }
}
