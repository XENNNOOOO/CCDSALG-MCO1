#include "utils.h"

/**
 * Allocates a specified number of bytes of memory and returns a pointer to the allocated memory.
 * If the allocation fails, it prints an error message and returns NULL.
 * 
 * @param bytes The number of bytes to allocate.
 * 
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void* allocate(int bytes) {
    void* ptr = malloc(bytes);

    if (ptr == NULL) {
        printf("Memory allocation failed...\n");
        return NULL;
    }

    return ptr;
}
