#include <stdio.h>
#include <math.h>

// Funciones que se pueden usar como callbacks
void incrementar(int *valor) {
    *valor += 1;
}

void cuadrado(int *valor) {
    *valor = *valor * *valor;
}

void raizCuadrada(int *valor) {
    *valor = (int)sqrt((double)*valor);
}

// Función que procesa el array usando el callback
void procesarArray(int *array, int size, void (*func)(int *)) {
    for (int i = 0; i < size; i++) {
        func(&array[i]); // Aplica la función callback al elemento actual
    }
}

// Función principal
int main() {
    int miArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(miArray) / sizeof(miArray[0]);
    int opcion;

    printf("Seleccione la operación (1=Incrementar, 2=Cuadrado, 3=Raíz Cuadrada): ");
    scanf("%d", &opcion);

    // Selecciona la función callback basada en la elección del usuario
    void (*funcionSeleccionada)(int *);
    switch (opcion) {
        case 1:
            funcionSeleccionada = incrementar;
            break;
        case 2:
            funcionSeleccionada = cuadrado;
            break;
        case 3:
            funcionSeleccionada = raizCuadrada;
            break;
        default:
            printf("Opción no válida\n");
            return 1;
    }

    // Procesa el array con la función seleccionada
    procesarArray(miArray, size, funcionSeleccionada);

    // Imprime el array procesado
    printf("Array procesado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", miArray[i]);
    }
    printf("\n");

    return 0;
}
