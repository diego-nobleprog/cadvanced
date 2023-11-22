#include <stdio.h>
#include <pthread.h>

#define N 10000
#define NUM_THREADS 4

int sum = 0;

// Estructura para pasar datos al hilo
struct ThreadData {
    int start;
    int end;
};

// Función que realiza la suma en un rango específico
void *calculateSum(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;

    // Calcula la suma en el rango proporcionado
    for (int i = data->start; i <= data->end; ++i) {
        sum += i;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData[NUM_THREADS];

    // Inicializa y crea hilos
    for (int i = 0; i < NUM_THREADS; ++i) {
        int rangeSize = N / NUM_THREADS;
        threadData[i].start = i * rangeSize + 1;
        threadData[i].end = (i + 1) * rangeSize;

        pthread_create(&threads[i], NULL, calculateSum, (void *)&threadData[i]);
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Imprime el resultado final
    printf("La suma de los primeros %d números naturales es: %d\n", N, sum);

    return 0;
}
