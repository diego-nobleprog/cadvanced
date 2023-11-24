// library.h (Interfaz)
#ifndef LIBRARY_H
#define LIBRARY_H

struct Book {
    char title[100];
    char author[50];
    int pages;
};

void addBook(struct Book *library, int *numBooks, const char *title, const char *author, int pages);
void getBookInfo(const struct Book *library, int numBooks, const char *title);
int totalPages(const struct Book *library, int numBooks);

#endif
