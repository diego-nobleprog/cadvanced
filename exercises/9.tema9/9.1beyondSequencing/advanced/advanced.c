#include <stdio.h>
#include <pthread.h>

#define N 1000000 // Número total de elementos a sumar
#define NUM_HILOS 4 // Número de hilos a utilizar

int sumaTotal = 0; // Variable global para almacenar la suma total
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex para sincronizar el acceso a la variable global

// Función que realiza la suma parcial en cada hilo
void *calcularSumaParcial(void *arg) {
    int hiloID = *((int *)arg);
    int inicio = hiloID * (N / NUM_HILOS) + 1;
    int fin = (hiloID + 1) * (N / NUM_HILOS);

    // Calcula la suma parcial
    int sumaParcial = 0;
    for (int i = inicio; i <= fin; ++i) {
        sumaParcial += i;
    }

    // Bloquea el mutex antes de actualizar la variable global
    pthread_mutex_lock(&mutex);
    sumaTotal += sumaParcial;
    // Desbloquea el mutex después de la actualización
    pthread_mutex_unlock(&mutex);

    // Salida del hilo
    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[NUM_HILOS]; // Arreglo para almacenar los identificadores de los hilos
    int idHilos[NUM_HILOS]; // Arreglo para almacenar los IDs de los hilos

    // Creación de los hilos
    for (int i = 0; i < NUM_HILOS; ++i) {
        idHilos[i] = i;
        pthread_create(&hilos[i], NULL, calcularSumaParcial, (void *)&idHilos[i]);
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < NUM_HILOS; ++i) {
        pthread_join(hilos[i], NULL);
    }

    // Imprime la suma total
    printf("Suma total de los primeros %d números naturales: %d\n", N, sumaTotal);

    return 0;
}
