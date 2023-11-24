// ebook.c (Implementación)
#include "ebook.h"
#include <stdio.h>
#include <string.h>

void addEBook(struct EBook *ebooks, int *numEBooks, const char *title, const char *author, const char *genre) {
    if (*numEBooks < 100) {
        struct EBook newEBook;
        strcpy(newEBook.title, title);
        strcpy(newEBook.author, author);
        strcpy(newEBook.genre, genre);
        newEBook.available = 1;  // Inicialmente disponible

        ebooks[*numEBooks] = newEBook;
        (*numEBooks)++;
        printf("EBook added successfully.\n");
    } else {
        printf("Maximum number of eBooks reached.\n");
    }
}

void searchByAuthor(const struct EBook *ebooks, int numEBooks, const char *author) {
    printf("Books by %s:\n", author);
    int found = 0;
    for (int i = 0; i < numEBooks; i++) {
        if (strcmp(ebooks[i].author, author) == 0) {
            printf("Title: %s, Genre: %s, Available: %s\n", ebooks[i].title, ebooks[i].genre, ebooks[i].available ? "Yes" : "No");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by %s.\n", author);
    }
}

void markAsBorrowed(struct EBook *ebooks, int numEBooks, const char *title) {
    for (int i = 0; i < numEBooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            if (ebooks[i].available) {
                ebooks[i].available = 0;  // Marcar como prestado
                printf("%s marked as borrowed.\n", title);
            } else {
                printf("%s is already borrowed.\n", title);
            }
            return;
        }
    }
    printf("Book not found: %s\n", title);
}
