#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include "../data_structures/stack.h"
#include "../data_structures/queue.h"

int isOperator(char* input);
char *compute(char* operands[], char operator);
int evaluatePostfix(Queue queue);

#endif