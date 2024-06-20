#ifndef SHUNTING_YARD_ALGO_H
#define SHUNTING_YARD_ALGO_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "../data_structures/stack.h"
#include "../data_structures/queue.h"
#include "../data_structures/hashmap.h"

#define HASHMAP_MAX_SIZE 16

Queue* infixToPostfix(char input[]);
HashMap fillPrecedenceMap();
int operatorPrecedence(char* key, HashMap operatorMap);
bool isStringOperator(char* tempChar);
bool isCharOperator(char tempChar);

#endif