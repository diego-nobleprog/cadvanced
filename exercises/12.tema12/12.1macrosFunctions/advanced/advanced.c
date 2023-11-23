#include <stdio.h>
#include <stdlib.h>

// Macros para registrar operaciones de memoria
#define MALLOC(size) mallocLogger(size, __FILE__, __LINE__)
#define FREE(ptr) freeLogger(ptr, __FILE__, __LINE__)

// Función para registrar y realizar malloc
void* mallocLogger(size_t size, const char *file, int line) {
    void *ptr = malloc(size);
    printf("[MEMORY ALLOCATED] %zu bytes at %p from %s:%d\n", size, ptr, file, line);
    return ptr;
}

// Función para registrar y realizar free
void freeLogger(void *ptr, const char *file, int line) {
    free(ptr);
    printf("[MEMORY FREED] at %p from %s:%d\n", ptr, file, line);
}

int main() {
    // Uso de la macro MALLOC para asignar memoria
    int *array = (int*) MALLOC(10 * sizeof(int));

    // Uso de la memoria asignada (por simplicidad, no se muestra)

    // Uso de la macro FREE para liberar memoria
    FREE(array);

    return 0;
}
