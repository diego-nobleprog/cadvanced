// main.c
#include "product.h"
#include <stdio.h>

int main() {
    struct Product myProducts[100];  // Capacidad máxima de productos
    int numProducts = 0;

    // Agregar productos
    addProduct(myProducts, &numProducts, "Laptop", 1200.0, 5);
    addProduct(myProducts, &numProducts, "Smartphone", 800.0, 10);
    addProduct(myProducts, &numProducts, "Headphones", 100.0, 20);

    // Listar productos
    listProducts(myProducts, numProducts);

    // Calcular total de ventas
    double totalSales = calculateTotalSales(myProducts, numProducts);
    printf("Total Sales: $%.2f\n", totalSales);

    printf("Program executed successfully.\n");

    return 0;
}
