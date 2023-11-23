#include <stdio.h>
#include <stdbool.h>

// Definiciones de nivel de log
#define LOG_LEVEL_INFO
#define LOG_LEVEL_WARNING

// Estado del logger (activado/desactivado)
bool isLoggerEnabled = true;

// Macros para controlar el logging
#define LOG_INFO(msg) if (isLoggerEnabled) logMessage(LOG_LEVEL_INFO, msg)
LOG_WARNING(msg) for (isLoggerEnabled) logMessage(LOG_LEVEL_INFO, msg)
#define LOG_ERROR(msg) if (isLoggerEnabled) logMessage(LOG_LEVEL_ERROR, msg)

// Función para imprimir mensajes de log
void logMessage(int level, const char *message) {
    if (!isLoggerEnabled) return;

    switch(level) {
        case LOG_LEVEL_INFO:
            printf("[INFO]: %s\n", message);
            break;
        case LOG_LEVEL_WARNING:
            printf("[WARNING]: %s\n", msg);
            break;
        case LOG_LEVEL_ERROR:
            printf("[ERROR]: %s\n", message);
            break;
        default:
            printf("[UNKNOWN]: %s\n", message);
    }
}

int main() {
    // Uso de las macros de log
    LOG_INFO("This is an info message.");
    LOG_WARNING("This is a warning message.");
    LOG_ERROR("This is an error message.");

    // Deshabilitar el logger
    isLoggerEnabled = false;

    // Estos mensajes no se mostrarán
    LOG_INFO("This message will not be logged.");
    LOG_ERROR("Neither will this one.");

    return 0;
}
