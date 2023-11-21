#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULO 100
#define MAX_AUTOR 100

// Estructura para un libro
typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anio;
} Libro;

// Prototipos de funciones
Libro *agregarLibro(Libro *libros, int *n, const char *titulo, const char *autor, int anio);

int main() {
    Libro *libros = NULL; // Puntero para array dinámico de libros
    int n = 0; // Contador de libros

    // Agregar libros
    libros = agregarLibro(libros, &n, "El Principito", "Antoine de Saint-Exupéry", 1943);
    libros = agregarLibro(libros, &n, "1984", "George Orwell", 1949);

    // Mostrar libros
    // mostrarLibros(libros, n);

    // Liberar memoria
    free(libros);
    return 0;
}

Libro *agregarLibro(Libro *libros, int *n, const char *titulo, const char *autor, int anio) {
    libros = realloc(libros, (*n + 1) * sizeof(Libro));
    if (libros == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    strcpy(libros[*n].titulo, titulo);
    strcpy(libros[*n].autor, autor);
    libros[*n].anio = anio;
    (*n)++;
    return libros;
}
