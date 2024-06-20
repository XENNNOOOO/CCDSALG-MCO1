#include "../calculator.h"

#define HASHMAP_SIZE 10

typedef struct KeyValuePairTag {
    char* key;
    int value;
} KeyValuePair;

typedef struct HashMapTag {
    KeyValuePair* array[HASHMAP_SIZE];
} HashMap;

unsigned int hash(const char* key);
void initHashMap(HashMap* map);
void put(HashMap* map, char* key, int value);
int get(HashMap* map, char* key);
void freeHashMap(HashMap* map);
