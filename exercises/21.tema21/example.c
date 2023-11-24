#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h> // Incluye la biblioteca para el manejo de errores.

#define PORT1 8080  // Primer puerto para escuchar
#define PORT2 8081  // Segundo puerto para escuchar

int main() {
    int server_fd1, server_fd2; // Descriptores de archivo para los sockets de los servidores
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    fd_set readfds;  // Conjunto de descriptores de archivo para select()

    // Crear socket file descriptor para el primer puerto
    if ((server_fd1 = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Crear socket file descriptor para el segundo puerto
    if ((server_fd2 = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configurar los sockets para permitir múltiples conexiones
    if (setsockopt(server_fd1, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd2, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Asignar dirección y puerto al primer socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT1);
    if (bind(server_fd1, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Asignar dirección y puerto al segundo socket
    address.sin_port = htons(PORT2); // Cambiar solo el puerto
    if (bind(server_fd2, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Configurar los sockets para escuchar conexiones entrantes
    if (listen(server_fd1, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd2, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server_fd1, &readfds);
        FD_SET(server_fd2, &readfds);

        // Usar select() para esperar actividad en cualquiera de los dos sockets
        int activity = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR)) {
            printf("select error");
        }

        // Verificar actividad en el primer socket
        if (FD_ISSET(server_fd1, &readfds)) {
            int new_socket;
            if ((new_socket = accept(server_fd1, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            // Manejar la nueva conexión en el puerto 8080
            printf("Nueva conexión en el puerto 8080\n");
            close(new_socket);
        }

        // Verificar actividad en el segundo socket
        if (FD_ISSET(server_fd2, &readfds)) {
            int new_socket;
            if ((new_socket = accept(server_fd2, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            // Manejar la nueva conexión en el puerto 8081
            printf("Nueva conexión en el puerto 8081\n");
            close(new_socket);
        }
    }

    return 0;
}
