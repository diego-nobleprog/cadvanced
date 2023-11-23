#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Estudiante
typedef struct {
    char nombre[50];
    float calificacion;
} Estudiante;

// Prototipos de funciones
void agregarEstudiante(Estudiante **lista, int *tam);
void mostrarEstudiantes(Estudiante *lista, int tam);
int buscarEstudiante(Estudiante *lista, int tam, char *nombre);
void liberarMemoria(Estudiante *lista);

int main() {
    Estudiante *listaEstudiantes = NULL; // Lista dinámica de estudiantes
    int tam = 0; // Tamaño actual de la lista
    char opcion; // Opción del menú

    do {
        printf("Menú:\nA - Agregar Estudiante\nM - Mostrar Estudiantes\nB - Buscar Estudiante\nQ - Salir\nOpción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'A':
                agregarEstudiante(&listaEstudiantes, &tam);
                break;
            case 'M':
                mostrarEstudiantes(listaEstudiantes, tam);
                break;
            case 'B':
                {
                    char nombreBusqueda[50];
                    printf("Ingrese el nombre a buscar: ");
                    scanf("%s", nombreBusqueda);
                    int indice = buscarEstudiante(listaEstudiantes, tam, nombreBusqueda);
                    if (indice != -1) {
                        printf("Estudiante encontrado: %s con calificación %.2f\n", listaEstudiantes[indice].nombre, listaEstudiantes[indice].calificacion);
                    } else {
                        printf("Estudiante no encontrado.\n");
                    }
                }
                break;
            case 'Q':
                liberarMemoria(listaEstudiantes);
                break;
        }
    } while (opcion != 'Q');

    return 0;
}

/**
 * Función para agregar un estudiante a la lista
 * @param lista Puntero al arreglo de estudiantes
 * @param tam Puntero al tamaño de la lista
 */
void agregarEstudiante(Estudiante **lista, int *tam) {
    // Incrementa el tamaño y realoca la memoria
    *tam += 1;
    *lista = (Estudiante *)realloc(*lista, (*tam) * sizeof(Estudiante));

    // Verifica si la realocación fue exitosa
    if (*lista == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    // Ingresa los datos del nuevo estudiante
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", (*lista)[*tam - 1].nombre);
    printf("Ingrese la calificación: ");
    scanf("%f", &(*lista)[*tam - 1].calificacion);
}

/**
 * Función para mostrar todos los estudiantes y sus calificaciones
 * @param lista Arreglo de estudiantes
 * @param tam Tamaño de la lista
 */
void mostrarEstudiantes(Estudiante *lista, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Estudiante: %s, Calificación: %.2f\n", lista[i].nombre, lista[i].calificacion);
    }
}

/**
 * Función para buscar un estudiante por nombre
 * @param lista Arreglo de estudiantes
 * @param tam Tamaño de la lista
 * @param nombre Nombre del estudiante a buscar
 * @return Índice del estudiante o -1 si no se encuentra
 */
int buscarEstudiante(Estudiante *lista, int tam, char *nombre) {
    for (int i = 0; i < tam; i++) {
        if (strcmp(lista[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * Función para liberar la memoria asignada a la lista de estudiantes
 * @param lista Arreglo de estudiantes
 */
void liberarMemoria(Estudiante *lista) {
    free(lista);
}
