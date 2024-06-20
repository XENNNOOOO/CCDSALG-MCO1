#ifndef SHUNTING_YARD_ALGO_H
#define SHUNTING_YARD_ALGO_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "../datastructures/stack.c"
#include "../datastructures/queue.c"
#include "../datastructures/hashmap.c"

#define HASHMAP_MAX_SIZE 15

Queue infixToPostfix(char input[]);
HashMap fillPrecedenceMap();
int operatorPrecedence(char* key, HashMap operatorMap);
bool isStringOperator(char* tempChar);
bool isCharOperator(char tempChar);

#endif