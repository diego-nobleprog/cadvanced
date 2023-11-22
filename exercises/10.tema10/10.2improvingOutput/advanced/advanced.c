#include <stdio.h>

// Definición de la estructura Empleado
struct Empleado {
    char nombre[30];
    int edad;
    float salario;
};

// Función para imprimir la información de los empleados
void imprimirEmpleados(struct Empleado empleados[], int numEmpleados) {
    printf("\n\033[1;32mInformación de Empleados:\033[0m\n");
    printf("%-20s %-10s %-15s\n", "Nombre", "Edad", "Salario");
    
    for (int i = 0; i < numEmpleados; i++) {
        printf("%-20s %-10d %-15.2f\n", empleados[i].nombre, empleados[i].edad, empleados[i].salario);
    }
}

// Función para calcular y mostrar el salario promedio
void salarioPromedio(struct Empleado empleados[], int numEmpleados) {
    float sumaSalarios = 0;
    
    for (int i = 0; i < numEmpleados; i++) {
        sumaSalarios += empleados[i].salario;
    }

    float promedio = sumaSalarios / numEmpleados;
    printf("\n\033[1;34mSalario Promedio:\033[0m %.2f\n", promedio);
}

int main() {
    // Inicialización de un arreglo de estructuras Empleado
    struct Empleado empleados[] = {
        {"Juan", 28, 50000.50},
        {"Ana", 35, 60000.75},
        {"Carlos", 22, 45000.25}
    };

    // Número de empleados en el arreglo
    int numEmpleados = sizeof(empleados) / sizeof(struct Empleado);

    // Llamada a la función para imprimir la información de los empleados
    imprimirEmpleados(empleados, numEmpleados);

    // Llamada a la función para calcular y mostrar el salario promedio
    salarioPromedio(empleados, numEmpleados);

    return 0;
}
