#include <stdio.h>      // Para funciones de entrada y salida estándar.
#include <stdlib.h>     // Para la función exit y otras.
#include <string.h>     // Para funciones de manejo de strings.
#include <unistd.h>     // Para funciones POSIX, como read y write.
#include <sys/socket.h> // Para funciones de sockets.
#include <netinet/in.h> // Para estructuras de direcciones de dominio de Internet.
#include <time.h>       // Para funciones de manejo de tiempo.

#define PORT 8080       // Puerto donde el servidor estará escuchando.

int main() {
    int server_fd, new_socket;                     // Descriptores de archivo para el servidor y la nueva conexión de socket.
    struct sockaddr_in address;                    // Estructura para la dirección del servidor.
    int addrlen = sizeof(address);                 // Tamaño de la estructura de dirección.
    char buffer[1024] = {0};                       // Buffer para almacenar la hora.
    time_t current_time;                           // Variable para almacenar la hora actual.
    
    // Creación del socket del servidor.
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Definición de la dirección del servidor.
    address.sin_family = AF_INET;                  // Tipo de dirección para sockets de red.
    address.sin_addr.s_addr = INADDR_ANY;          // Acepta conexiones en cualquier IP del servidor.
    address.sin_port = htons(PORT);                // Convierte el número de puerto al orden de bytes de red.
    
    // Vinculación del socket a la dirección del servidor.
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Poner al servidor a escuchar conexiones entrantes.
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    // Aceptar una conexión entrante.
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    // Obtención de la hora actual.
    time(&current_time);
    struct tm *time_info = localtime(&current_time); // Convertir la hora a la hora local.
    
    // Formatear la hora en un string y enviarla al cliente.
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info); // Formatear la hora y la fecha.
    send(new_socket, buffer, strlen(buffer), 0); // Enviar la hora al cliente.
    printf("Hora enviada al cliente: %s\n", buffer); // Imprimir en consola la hora enviada.
    
    // Cerrar la conexión.
    close(new_socket);
    
    // Cerrar el servidor.
    close(server_fd);
    
    return 0; // Termina el programa con éxito.
}
