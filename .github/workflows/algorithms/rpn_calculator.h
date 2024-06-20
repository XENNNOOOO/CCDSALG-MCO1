#include <string.h>

#include "../data_structures/stack.c"
#include "../data_structures/queue.c"

int isOperator(char* input);
char *compute(char* operands[], char operator);
int evaluatePostfix(Queue queue);