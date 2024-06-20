#include <string.h>

#include "../datastructures/stack.c"
#include "../datastructures/queue.c"

int isOperator(char* input);
char *compute(char* operands[], char operator);
int evaluatePostfix(Queue queue);