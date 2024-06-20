#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "../data_structures/stack.c"
#include "../data_structures/queue.c"
#include "../data_structures/hashmap.c"

#define HASHMAP_MAX_SIZE 16

Queue infixToPostfix(char input[]);
HashMap fillPrecedenceMap();
int operatorPrecedence(char* key, HashMap operatorMap);
bool isStringOperator(char* tempChar);
bool isCharOperator(char tempChar);