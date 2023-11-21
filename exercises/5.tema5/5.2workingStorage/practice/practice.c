// main.c
#include <stdio.h>

extern int configTiempo; // Declaración de variable externa

void registrarTiempo();

int main() {
    configTiempo = 5; // Configuración de tiempo compartida
    registrarTiempo();
    return 0;
}

void registrarTiempo() {
    static int tiempoTotal = 0; // Variable estática para acumular tiempo
    auto int tiempoLocal = configTiempo; // Variable auto para tiempo local

    // Uso de register para un bucle optimizado
    for (register int i = 0; i < tiempoLocal; i++) {
        tiempoTotal += 1;
        printf("Tiempo acumulado: %d segundos\n", tiempoTotal);
    }
}
