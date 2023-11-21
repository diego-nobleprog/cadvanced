#include <stdio.h>
#include <string.h>

#define MAX_CIUDADES 5
#define MAX_REGISTROS 10

typedef struct {
    char nombreCiudad[50];
    float temperaturas[MAX_REGISTROS];
    int contadorTemperaturas;
} RegistroCiudad;

void agregarTemperatura(RegistroCiudad *registro, float temp);
float calcularPromedio(RegistroCiudad registro);

int main() {
    RegistroCiudad registros[MAX_CIUDADES] = {0};
    int numCiudades = 0;
    char continuar;

    while (numCiudades < MAX_CIUDADES) {
        printf("Introduce el nombre de la ciudad: ");
        scanf("%s", registros[numCiudades].nombreCiudad);

        do {
            float temp;
            printf("Introduce una temperatura para %s: ", registros[numCiudades].nombreCiudad);
            scanf("%f", &temp);
            agregarTemperatura(&registros[numCiudades], temp);

            printf("¿Deseas agregar otra temperatura? (s/n): ");
            scanf(" %c", &continuar); // Nota el espacio antes de %c para capturar el salto de línea anterior
        } while (continuar == 's');

        numCiudades++;

        printf("¿Deseas agregar otra ciudad? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar != 's') break;
    }

    for (int i = 0; i < numCiudades; i++) {
        printf("Temperaturas en %s:\n", registros[i].nombreCiudad);
        for (int j = 0; j < registros[i].contadorTemperaturas; j++) {
            printf("%.2f ", registros[i].temperaturas[j]);
        }
        printf("\nPromedio: %.2f\n", calcularPromedio(registros[i]));
    }

    return 0;
}

void agregarTemperatura(RegistroCiudad *registro, float temp) {
    if (registro->contadorTemperaturas < MAX_REGISTROS) {
        registro->temperaturas[registro->contadorTemperaturas] = temp;
        registro->contadorTemperaturas++;
    }
}

float calcularPromedio(RegistroCiudad registro) {
    float suma = 0.0;
    for (int i = 0; i < registro.contadorTemperaturas; i++) {
        suma += registro.temperaturas[i];
    }
    return (registro.contadorTemperaturas > 0) ? suma / registro.contadorTemperaturas : 0.0;
}
