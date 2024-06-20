#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "../datastructures/stack.c"
#include "../datastructures/queue.c"
#include "../datastructures/hashmap.c"

#define HASHMAP_MAX_SIZE 16

Queue infixToPostfix(char input[]);
HashMap fillPrecedenceMap();
int operatorPrecedence(char* key, HashMap operatorMap);
bool isStringOperator(char* tempChar);
bool isCharOperator(char tempChar);