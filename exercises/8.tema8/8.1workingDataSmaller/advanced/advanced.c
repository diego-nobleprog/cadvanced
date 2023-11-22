#include <stdio.h>

// Prototipos de funciones
void mostrarBinario(unsigned char num);
unsigned char cifrar(unsigned char mensaje, unsigned char clave);
unsigned char descifrar(unsigned char mensajeCifrado, unsigned char clave);

int main() {
    // Mensaje original y clave
    unsigned char mensajeOriginal = 0b10101010;  // Ejemplo de un byte de mensaje
    unsigned char clave = 0b11001100;           // Ejemplo de una clave

    // Cifrar el mensaje
    unsigned char mensajeCifrado = cifrar(mensajeOriginal, clave);

    // Descifrar el mensaje cifrado
    unsigned char mensajeDescifrado = descifrar(mensajeCifrado, clave);

    // Mostrar resultados
    printf("Mensaje original: ");
    mostrarBinario(mensajeOriginal);

    printf("Clave: ");
    mostrarBinario(clave);

    printf("Mensaje cifrado: ");
    mostrarBinario(mensajeCifrado);

    printf("Mensaje descifrado: ");
    mostrarBinario(mensajeDescifrado);

    return 0;
}

// Función para cifrar un byte de mensaje
unsigned char cifrar(unsigned char mensaje, unsigned char clave) {
    return mensaje ^ clave;  // Operación XOR para cifrar
}

// Función para descifrar un byte cifrado
unsigned char descifrar(unsigned char mensajeCifrado, unsigned char clave) {
    return mensajeCifrado ^ clave;  // Operación XOR para descifrar
}

// Función para mostrar la representación binaria de un byte
void mostrarBinario(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}
