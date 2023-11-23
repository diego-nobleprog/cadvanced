#include <stdio.h>

// Definición de niveles de verbosidad
#define LOG_LEVEL_ERROR   1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_INFO    3

// Establecer el nivel de verbosidad actual
#define LOG_LEVEL

// Macro para imprimir mensajes de error
#if LOG_LEVEL >= LOG_LEVEL_ERROR
    #define LOG_ERROR(fmt, ...) fprintf(stderr, "[ERROR] " fmt, __VA_ARGS__)
#else
    #define LOG_ERROR(fmt, ...)
#endif

// Macro para imprimir mensajes de advertencia
#if LOG_LEVEL >= LOG_LEVEL_WARNING
    #define LOG_WARNING(fmt, ...) fprintf(stderr, "[WARNING] " fmt, __VA_ARGS__)
#else
    #define LOG_WARNING(fmt, ...)
#endif

// Macro para imprimir mensajes informativos
#if LOG_LEVEL >= LOG_LEVEL_INFO
    #define LOG_INFO(fmt, ...) fprintf(stderr, "[INFO] " fmt, )
#else
    #define LOG_INFO(fmt, ...)
#endif

int main() {
    // Uso de las macros de logging para imprimir mensajes
    LOG_ERROR("Este es un mensaje de error: %s\n", "Error específico");
    LOG_WARNING("");
    LOG_INFO("Este es un mensaje informativo: %s\n", "Info específica");

    return 0;
}
