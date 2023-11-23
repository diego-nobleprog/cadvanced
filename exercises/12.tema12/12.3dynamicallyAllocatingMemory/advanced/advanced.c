#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Prototipos de funciones
Nodo* crearNodo(int dato);
void agregarNodo(Nodo **cabeza, int dato);
void eliminarNodo(Nodo **cabeza, int dato);
void invertirLista(Nodo **cabeza);
void mostrarLista(Nodo *cabeza);
void liberarLista(Nodo *cabeza);

int main() {
    Nodo *cabeza = NULL; // Puntero a la cabeza de la lista
    int opcion; // Opción elegida por el usuario
    int valor; // Valor para agregar o eliminar de la lista

    while (1) {
        printf("Menú de Opciones:\n");
        printf("1. Agregar Nodo\n");
        printf("2. Eliminar Nodo\n");
        printf("3. Invertir Lista\n");
        printf("4. Mostrar Lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: // Agregar Nodo
                printf("Ingrese el valor del nuevo nodo: ");
                scanf("%d", &valor);
                agregarNodo(&cabeza, valor);
                break;
            case 2: // Eliminar Nodo
                printf("Ingrese el valor del nodo a eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(&cabeza, valor);
                break;
            case 3: // Invertir Lista
                invertirLista(&cabeza);
                break;
            case 4: // Mostrar Lista
                mostrarLista(cabeza);
                break;
            case 5: // Salir
                liberarLista(cabeza);
                return 0;
            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    }
}

/**
 * Crea un nuevo nodo con el dato proporcionado.
 * @param dato El dato del nuevo nodo.
 * @return Un puntero al nuevo nodo.
 */
Nodo* crearNodo(int dato) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo)); // Asigna memoria para el nuevo nodo.
    if (nuevo == NULL) {
        perror("Error en la asignación de memoria");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = dato; // Establece el dato.
    nuevo->siguiente = NULL; // El siguiente nodo es NULL por defecto.
    return nuevo;
}

/**
 * Agrega un nodo al final de la lista.
 * @param cabeza Doble puntero a la cabeza de la lista.
 * @param dato El dato para el nuevo nodo.
 */
void agregarNodo(Nodo **cabeza, int dato) {
    Nodo *nuevo = crearNodo(dato); // Crea un nuevo nodo.
    if (*cabeza == NULL) { // Si la lista está vacía.
        *cabeza = nuevo; // El nuevo nodo es ahora la cabeza.
    } else {
        Nodo *actual = *cabeza;
        while (actual->siguiente != NULL) { // Recorre hasta el final de la lista.
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo; // Enlaza el nuevo nodo al final de la lista.
    }
}

/**
 * Elimina un nodo con el dato especificado.
 * @param cabeza Doble puntero a la cabeza de la lista.
 * @param dato El dato del nodo a eliminar.
 */
void eliminarNodo(Nodo **cabeza, int dato) {
    if (*cabeza == NULL) {
        return; // Lista vacía, no hay nada que eliminar.
    }

    Nodo *temporal;
    if ((*cabeza)->dato == dato) { // Si el nodo a eliminar es la cabeza.
        temporal = *cabeza; // Guarda el nodo a eliminar.
        *cabeza = (*cabeza)->siguiente; // Avanza la cabeza al siguiente nodo.
        free(temporal); // Libera el nodo eliminado.
    } else {
        Nodo *actual = *cabeza;
        while (actual->siguiente != NULL && actual->siguiente->dato != dato) { // Busca el nodo a eliminar.
            actual = actual->siguiente;
        }
        if (actual->siguiente != NULL) { // Si encontró el nodo a eliminar.
            temporal = actual->siguiente; // Guarda el nodo a eliminar.
            actual->siguiente = actual->siguiente->siguiente; // Elimina el nodo de la lista.
            free(temporal); // Libera el nodo eliminado.
        }
    }
}

/**
 * Invierte la lista enlazada.
 * @param cabeza Doble puntero a la cabeza de la lista.
 */
void invertirLista(Nodo **cabeza) {
    Nodo *previo = NULL;
    Nodo *actual = *cabeza;
    Nodo *siguiente = NULL;

    while (actual != NULL) {
        siguiente = actual->siguiente; // Guarda el siguiente nodo.
        actual->siguiente = previo; // Cambia el siguiente del nodo actual al previo.
        previo = actual; // Avanza el nodo previo.
        actual = siguiente; // Avanza al siguiente nodo.
    }
    *cabeza = previo; // Actualiza la cabeza de la lista.
}

/**
 * Muestra todos los elementos de la lista.
 * @param cabeza Puntero a la cabeza de la lista.
 */
void mostrarLista(Nodo *cabeza) {
    Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

/**
 * Libera toda la memoria utilizada por la lista.
 * @param cabeza Puntero a la cabeza de la lista.
 */
void liberarLista(Nodo *cabeza) {
    Nodo *actual = cabeza;
    while (actual != NULL) {
        Nodo *aEliminar = actual;
        actual = actual->siguiente;
        free(aEliminar); // Libera cada nodo individualmente.
    }
}
