// product.h (Interfaz)
#ifndef PRODUCT_H
#define PRODUCT_H

struct Product {
    char name[100];
    double price;
    int quantity;
};

void addProduct(struct Product *products, int *numProducts, const char *name, double price, int quantity);
void listProducts(const struct Product *products, int numProducts);
double calculateTotalSales(const struct Product *products, int numProducts);

#endif
