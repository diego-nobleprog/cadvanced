#include <stdio.h>
#include <stdlib.h>

// Función para codificar una cadena de caracteres
unsigned int codificarCadena(const char *cadena) {
    unsigned int resultado = 0;

    // Recorre cada carácter de la cadena
    while (*cadena != '\0') {
        // Utiliza el operador de desplazamiento a la izquierda para hacer espacio para el próximo carácter
        resultado <<= 8;

        // Agrega el valor ASCII del carácter actual a la parte menos significativa
        resultado |= *cadena;

        // Mueve el puntero al siguiente carácter
        cadena++;
    }

    return resultado;
}

// Función para decodificar una cadena de caracteres
void decodificarCadena(unsigned int codigo, char *cadenaDecodificada) {
    // Máscara para aislar el byte más significativo
    unsigned int mascara = 0xFF000000;

    // Recorre cada byte de la cadena decodificada
    for (int i = 0; i < 4; ++i) {
        // Utiliza el operador de desplazamiento a la derecha para obtener el byte más significativo
        unsigned int byte = (codigo & mascara) >> 24;

        // Convierte el valor a un char y lo agrega a la cadena decodificada
        *cadenaDecodificada = (char)byte;

        // Mueve la máscara al siguiente byte
        mascara >>= 8;

        // Mueve el puntero al siguiente char en la cadena
        cadenaDecodificada++;
    }

    // Agrega el carácter nulo al final de la cadena
    *cadenaDecodificada = '\0';
}

int main() {
    // Ejemplo de uso de la codificación y decodificación
    const char *cadenaOriginal = "Hola, mundo!";
    printf("Cadena Original: %s\n", cadenaOriginal);

    // Codificar la cadena
    unsigned int codigo = codificarCadena(cadenaOriginal);
    printf("Código: %u\n", codigo);

    // Decodificar el código
    char cadenaDecodificada[20];  // Se asume una longitud máxima de 20 para la cadena decodificada
    decodificarCadena(codigo, cadenaDecodificada);
    printf("Cadena Decodificada: %s\n", cadenaDecodificada);

    return 0;
}
