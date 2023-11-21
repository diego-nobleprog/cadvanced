#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 100
#define MAX_CONTENT 200

// Estructura para representar un archivo ficticio
typedef struct {
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];
} File;

// Prototipos de funciones
void createFile(File files[], int *fileCount);
void deleteFile(File files[], int *fileCount);
void listFiles(File files[], int fileCount);

// Función principal
int main() {
    File files[MAX_FILES];  // Array para almacenar archivos ficticios
    int fileCount = 0;      // Contador de archivos actuales
    char command[10];       // Para almacenar el comando del usuario

    printf("Sistema de archivos simulado\n");

    // Bucle principal del programa
    while (1) {
        printf("Comandos disponibles: create, delete, list, exit\n");
        printf("Introduce un comando: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            createFile(files, &fileCount);
        } else if (strcmp(command, "delete") == 0) {
            deleteFile(files, &fileCount);
        } else if (strcmp(command, "list") == 0) {
            listFiles(files, fileCount);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Comando desconocido.\n");
        }
    }

    return 0;
}

// Implementación de funciones
void createFile(File files[], int *fileCount) {
    if (*fileCount >= MAX_FILES) {
        printf("No se pueden crear más archivos.\n");
        return;
    }
    printf("Introduce el nombre del archivo: ");
    scanf("%s", files[*fileCount].filename);
    printf("Introduce el contenido del archivo: ");
    scanf("%s", files[*fileCount].content);
    (*fileCount)++;
}

void deleteFile(File files[], int *fileCount) {
    char filenameToDelete[MAX_FILENAME];
    printf("Introduce el nombre del archivo a eliminar: ");
    scanf("%s", filenameToDelete);

    for (int i = 0; i < *fileCount; i++) {
        if (strcmp(files[i].filename, filenameToDelete) == 0) {
            for (int j = i; j < *fileCount - 1; j++) {
                files[j] = files[j + 1]; // Shift files down in the array
            }
            (*fileCount)--;
            printf("Archivo eliminado.\n");
            return;
        }
    }
    printf("Archivo no encontrado.\n");
}

void listFiles(File files[], int fileCount) {
    printf("Archivos:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("Nombre: %s, Contenido: %s\n", files[i].filename, files[i].content);
    }
}
