#include <stdio.h>
#include <string.h>

#define MAX_CIUDADES 5
#define MAX_REGISTROS 10

// Estructura para almacenar los registros de temperatura
typedef struct {
    char nombreCiudad[50];
    float temperaturas[MAX_REGISTROS];
    int contadorTemperaturas; // Contador de las temperaturas registradas
} RegistroCiudad;

// Prototipos de funciones
void agregarTemperatura(RegistroCiudad registros[], int indice, float temp);
float calcularPromedio(RegistroCiudad registro);

// Función principal
int main() {
    RegistroCiudad registros[MAX_CIUDADES] = {0}; // Inicializar el arreglo de registros
    int numCiudades = 0; // Contador de ciudades

    // Agregar temperaturas (por simplicidad, datos ficticios)
    strcpy(registros[0].nombreCiudad, "Ciudad1");
    agregarTemperatura(registros, 0, 23.5);
    agregarTemperatura(registros, 0, 26.1);
    numCiudades++;

    strcpy(registros[1].nombreCiudad, "Ciudad2");
    agregarTemperatura(registros, 1, 18.3);
    numCiudades++;

    // Mostrar las temperaturas y calcular promedios
    for (int i = 0; i < numCiudades; i++) {
        printf("Temperaturas en %s:\n", registros[i].nombreCiudad);
        for (int j = 0; j < registros[i].contadorTemperaturas; j++) {
            printf("%.2f ", registros[i].temperaturas[j]);
        }
        printf("\nPromedio: %.2f\n", calcularPromedio(registros[i]));
    }

    return 0;
}

// Implementación de funciones
void agregarTemperatura(RegistroCiudad registros[], int indice, float temp) {
    int contador = registros[indice].contadorTemperaturas;
    if (contador < MAX_REGISTROS) {
        registros[indice].temperaturas[contador] = temp;
        registros[indice].contadorTemperaturas++;
    }
}

float calcularPromedio(RegistroCiudad registro) {
    float suma = 0.0;
    for (int i = 0; i < registro.contadorTemperaturas; i++) {
        suma += registro.temperaturas[i];
    }
    return (registro.contadorTemperaturas > 0) ? suma / registro.contadorTemperaturas : 0.0;
}
