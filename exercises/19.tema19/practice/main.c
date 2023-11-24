#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 100  // Tamaño de la memoria compartida para el inventario

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void wait_semaphore(int sem_id) {
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(sem_id, &sem_op, 1);
}

void signal_semaphore(int sem_id) {
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    semop(sem_id, &sem_op, 1);
}

int main() {
    key_t key = ftok("inventory", 65);

    // Crear la memoria compartida
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    int* inventory = (int*)shmat(shmid, NULL, 0);

    // Crear el semáforo
    int sem_id = semget(key, 1, IPC_CREAT | 0666);
    union semun su;
    su.val = 1;
    semctl(sem_id, 0, SETVAL, su);

    pid_t pid = fork();

    if (pid == -1) {
        perror("Error en el fork");
        return 1;
    }

    if (pid > 0) {  // Proceso Padre (Simula la llegada de productos)
        while (1) {
            wait_semaphore(sem_id);
            // Simular la llegada de productos (incrementar el inventario)
            *inventory += rand() % 10 + 1;
            printf("Inventario actualizado: %d\n", *inventory);
            signal_semaphore(sem_id);
            sleep(2);
        }
    } else {  // Proceso Hijo (Simula la venta de productos)
        while (1) {
            wait_semaphore(sem_id);
            // Simular la venta de productos (decrementar el inventario)
            *inventory -= rand() % 5 + 1;
            printf("Inventario actualizado: %d\n", *inventory);
            signal_semaphore(sem_id);
            sleep(3);
        }
    }

    // Liberar la memoria compartida y el semáforo al finalizar
    shmdt(inventory);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID);

    return 0;
}
