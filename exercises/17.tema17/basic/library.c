// library.c (Implementación)
#include "library.h"
#include <stdio.h>
#include <string.h>

void addBook(struct Book *library, int *numBooks, const char *title, const char *author, int pages) {
    struct Book newBook;
    strcpy(newBook.title, title);
    strcpy(newBook.author, author);
    newBook.pages = pages;

    library[*numBooks] = newBook;
    (*numBooks)++;
}

void getBookInfo(const struct Book *library, int numBooks, const char *title) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Title: %s\nAuthor: %s\nPages: %d\n", library[i].title, library[i].author, library[i].pages);
            return;
        }
    }
    printf("Book not found: %s\n", title);
}

int totalPages(const struct Book *library, int numBooks) {
    int total = 0;
    for (int i = 0; i < numBooks; i++) {
        total += library[i].pages;
    }
    return total;
}
