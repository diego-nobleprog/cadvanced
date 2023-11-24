#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Función para realizar la operación simple (puede ser suma, resta, multiplicación, etc.)
int realizar_operacion(int num1, int num2) {
    return num1 + num2;  // En este caso, realizaremos una suma
}

int main() {
    int pipe_fd[2];
    int num1 = 5, num2 = 3;  // Números a operar

    // Crear el pipe
    if (pipe(pipe_fd) == -1) {
        perror("Error al crear el pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Error en el fork");
        return 1;
    }

    if (pid > 0) {  // Proceso Padre
        close(pipe_fd[0]);  // Cierra la lectura, ya que el padre escribirá en el pipe
        write(pipe_fd[1], &num1, sizeof(int));  // Enviar el primer número
        write(pipe_fd[1], &num2, sizeof(int));  // Enviar el segundo número
        close(pipe_fd[1]);  // Cierra la escritura

        // Esperar a que el hijo complete y obtenga el resultado
        int resultado;
        wait(NULL);
        read(pipe_fd[0], &resultado, sizeof(int));
        close(pipe_fd[0]);  // Cierra la lectura

        // Mostrar el resultado
        printf("Resultado recibido del proceso hijo: %d\n", resultado);

        // Aquí puedes preguntar si deseas añadir algo más.
    } else {  // Proceso Hijo
        close(pipe_fd[1]);  // Cierra la escritura, ya que el hijo leerá del pipe
        int num1_hijo, num2_hijo;

        read(pipe_fd[0], &num1_hijo, sizeof(int));  // Leer el primer número
        read(pipe_fd[0], &num2_hijo, sizeof(int));  // Leer el segundo número

        // Realizar la operación
        int resultado_hijo = realizar_operacion(num1_hijo, num2_hijo);

        // Enviar el resultado al proceso padre
        write(pipe_fd[1], &resultado_hijo, sizeof(int));
        close(pipe_fd[0]);  // Cierra la lectura
        close(pipe_fd[1]);  // Cierra la escritura

        // Aquí puedes preguntar si deseas añadir algo más.
    }

    return 0;
}
