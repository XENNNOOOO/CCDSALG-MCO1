#include "hashmap.h"

/**
 * Generates a hash value for a given key.
 * 
 * @param key The key to hash.
 * 
 * @return The hash value.
 */
unsigned int hash(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = 31 * hash + key[i];
    }
    return hash % HASHMAP_SIZE;
}

/**
 * Initializes the hash map.
 * 
 * @param map A pointer to the hash map to be initialized.
 * 
 * @return void
 */
void initHashMap(HashMap* map) {
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        map->array[i] = NULL;
    }
}

/**
 * Puts a key-value pair into the hash map.
 * 
 * @param map The hash map.
 * @param key The key to insert.
 * @param value The value associated with the key.
 * 
 * @return void
 */
void put(HashMap* map, char* key, int value) {
    unsigned int index = hash(key);
    KeyValuePair* kvp = (KeyValuePair*) malloc(sizeof(KeyValuePair));

    kvp->key = strdup(key);
    kvp->value = value;

    if (map->array[index] != NULL) {
        free(map->array[index]->key);
        free(map->array[index]);
    }

    map->array[index] = kvp;
}

/**
 * Gets the value associated with a key from the hash map.
 * 
 * @param map The hash map.
 * @param key The key to lookup.
 * 
 * @return The value associated with the key, or -1 if the key is not found.
 */
int get(HashMap* map, char* key) {
    unsigned int index = hash(key);
    KeyValuePair* kvp = map->array[index];

    if (kvp != NULL && strcmp(kvp->key, key) == 0) {
        return kvp->value;
    }

    return -1;
}

/**
 * Frees the memory allocated for the hash map.
 * 
 * @param map The hash map to be freed.
 * 
 * @return void
 */
void freeHashMap(HashMap* map) {
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        if (map->array[i] != NULL) {
            free(map->array[i]->key);
            free(map->array[i]);
        }
    }
    free(map);
}
