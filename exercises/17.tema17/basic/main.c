// main.c
#include "library.h"
#include <stdio.h>

int main() {
    struct Book myLibrary[100];  // Capacidad máxima de la biblioteca
    int numBooks = 0;

    // Agregar libros
    addBook(myLibrary, &numBooks, "The Catcher in the Rye", "J.D. Salinger", 224);
    addBook(myLibrary, &numBooks, "To Kill a Mockingbird", "Harper Lee", 281);
    addBook(myLibrary, &numBooks, "1984", "George Orwell", 328);

    // Obtener información de un libro
    getBookInfo(myLibrary, numBooks, "1984");

    // Calcular la cantidad total de páginas
    int total = totalPages(myLibrary, numBooks);
    printf("Total pages in library: %d\n", total);

    // Prueba de regresión
    if (total == 833) {
        printf("Regression test passed.\n");
    } else {
        printf("Regression test failed.\n");
    }

    printf("Program executed successfully.\n");

    return 0;
}
