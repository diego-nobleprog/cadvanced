// main.c
#include "ebook.h"
#include <stdio.h>

int main() {
    struct EBook myEBooks[100];  // Capacidad máxima de eBooks
    int numEBooks = 0;

    // Agregar eBooks
    addEBook(myEBooks, &numEBooks, "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Science Fiction");
    addEBook(myEBooks, &numEBooks, "1984", "George Orwell", "Dystopian Fiction");
    addEBook(myEBooks, &numEBooks, "To Kill a Mockingbird", "Harper Lee", "Classic");

    // Buscar eBooks por autor
    searchByAuthor(myEBooks, numEBooks, "George Orwell");

    // Marcar un eBook como prestado
    markAsBorrowed(myEBooks, numEBooks, "1984");

    printf("Program executed successfully.\n");

    return 0;
}
