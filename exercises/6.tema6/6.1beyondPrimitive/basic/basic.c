#include <stdio.h>

#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 50

// Definición de la estructura Producto
typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
    int cantidad;
} Producto;

int main() {
    Producto productos[MAX_PRODUCTOS]; // Array para almacenar productos
    int numProductos = 0; // Contador de productos

    // Ingreso de datos de productos
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(productos[i].nombre, MAX_NOMBRE, stdin);
        productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0'; // Remueve el salto de línea

        printf("Ingrese el precio de %s: ", productos[i].nombre);
        scanf("%f", &productos[i].precio);
        printf("Ingrese la cantidad de %s: ", productos[i].nombre);
        scanf("%d", &productos[i].cantidad);
        getchar(); // Captura el carácter de nueva línea

        numProductos++;
    }

    // Mostrar los productos ingresados
    printf("\nLista de Productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%s - Precio: $%.2f, Cantidad: %d\n", productos[i].nombre, productos[i].precio, productos[i].cantidad);
    }

    return 0;
}
