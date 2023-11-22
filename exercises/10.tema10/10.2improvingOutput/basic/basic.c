#include <stdio.h>

int main() {
    // Variables para almacenar la información del usuario
    char nombre[30];
    int edad;
    char ciudad[30];

    // Solicitar información al usuario
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Ingrese su ciudad de residencia: ");
    scanf("%s", ciudad);

    // Imprimir la información formateada
    printf("\n\033[1;32mInformación del Usuario:\033[0m\n");
    printf("%-20s %-10s\n", "Nombre", "Edad");
    printf("%-20s %-10d\n", nombre, edad);

    printf("\n\033[1;34mCiudad de Residencia:\033[0m\n");
    printf("%s\n", ciudad);

    return 0;
}
