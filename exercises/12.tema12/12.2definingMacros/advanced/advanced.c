#include <stdio.h>
#include <string.h>

// Estructura para representar una prueba unitaria
typedef struct TestCase {
    const char* name;
    void (*testFunction)();
    struct TestCase* next;
} TestCase;

// Cabeza de la lista enlazada de pruebas
static TestCase* tests = NULL;

// Macro para definir una prueba unitaria
#define TEST_CASE(test_name) \
void test_name(); \
static TestCase _tc_##test_name = {#test_name, test_name, NULL}; \
__attribute__((constructor)) static void _register_##test_name() { \
    _tc_##test_name.next = tests; \
    tests = &_tc_##test_name; \
} \
void test_name()

// Macro para afirmaciones (asserts)
#define ASSERT(condition) \
    if (!(condition)) { \
        printf("Assertion failed: (%s), function %s, file %s, line %d.\n", \
               #condition, __FUNCTION__, __FILE__, __LINE__); \
        return; \
    }

// Macro para ejecutar todas las pruebas
#define RUN_TESTS() \
    for (TestCase* test = tests; test != NULL; test = test->next) { \
        printf("Running test: %s\n", test->name); \
        test->testFunction(); \
    }

// Ejemplo de uso del framework
TEST_CASE(test_example) {
    ASSERT(1 == 1);
    ASSERT(strcmp("hello", "hello") == 0);
}

/*
// Nueva prueba: test_suma
TEST_CASE(test_suma) {
    int suma = 5 + 3;
    ASSERT(suma == 8);
}

// Nueva prueba: test_multiplicacion
TEST_CASE(test_multiplicacion) {
    int producto = 4 * 3;
    ASSERT(producto == 12);
}
*/

int main() {
    RUN_TESTS();
    return 0;
}
