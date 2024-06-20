#ifndef HASHMAP_H
#define HASHMAP_H

#include "../calculator.h"
#include "../utils.h"

#define HASHMAP_SIZE 10

typedef struct KeyValuePairTag {
    char* key;
    int value;
} KeyValuePair;

typedef struct HashMapTag {
    KeyValuePair* array[HASHMAP_SIZE];
} HashMap;

unsigned int hash(char* key);
void initHashMap(HashMap* map);
void put(HashMap* map, char* key, int value);
int get(HashMap* map, char* key);
void freeHashMap(HashMap* map);

#endif