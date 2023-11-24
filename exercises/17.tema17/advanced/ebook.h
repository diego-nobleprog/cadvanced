// ebook.h (Interfaz)
#ifndef EBOOK_H
#define EBOOK_H

struct EBook {
    char title[100];
    char author[50];
    char genre[50];
    int available;  // 1 si está disponible, 0 si está prestado
};

void addEBook(struct EBook *ebooks, int *numEBooks, const char *title, const char *author, const char *genre);
void searchByAuthor(const struct EBook *ebooks, int numEBooks, const char *author);
void markAsBorrowed(struct EBook *ebooks, int numEBooks, const char *title);

#endif
