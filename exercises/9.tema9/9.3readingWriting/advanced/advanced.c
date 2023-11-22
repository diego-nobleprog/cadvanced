#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int n;

    // Solicitar al usuario el tamaño de la matriz
    printf("Ingrese el tamaño de la matriz cuadrada (n x n): ");
    scanf("%d", &n);

    // Declarar matrices para almacenar datos
    int matriz[MAX_SIZE][MAX_SIZE];
    int transpuesta[MAX_SIZE][MAX_SIZE];
    int multiplicacion[MAX_SIZE][MAX_SIZE];

    // Llenar la matriz con valores proporcionados por el usuario
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Calcular la transposición de la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    // Multiplicar la matriz original por su transpuesta
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            multiplicacion[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                multiplicacion[i][j] += matriz[i][k] * transpuesta[k][j];
            }
        }
    }

    // Mostrar las matrices originales, transpuesta y el resultado de la multiplicación
    printf("\nMatriz Original:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz Transpuesta:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", transpuesta[i][j]);
        }
        printf("\n");
    }

    printf("\nResultado de la Multiplicación:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", multiplicacion[i][j]);
        }
        printf("\n");
    }

    return 0;
}
