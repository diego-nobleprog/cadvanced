// main.c
#include <stdio.h>

// Declaración de la variable externa (definida en otro archivo)
extern int contadorExterno;

// Prototipo de función
void incrementarContador();

int main() {
    // Contador con 'auto'
    for (auto int i = 0; i < 3; i++) {
        printf("Contador auto: %d\n", i);
    }

    // Llamadas a la función que utiliza 'static'
    for (int j = 0; j < 3; j++) {
        incrementarContador();
    }

    // Uso de 'register'
    for (register int k = 0; k < 3; k++) {
        printf("Contador register: %d\n", k);
    }

    // Uso de 'extern'
    printf("Contador externo: %d\n", contadorExterno);

    return 0;
}

// Función que utiliza una variable 'static'
void incrementarContador() {
    static int contadorStatic = 0;
    contadorStatic++;
    printf("Contador static: %d\n", contadorStatic);
}
