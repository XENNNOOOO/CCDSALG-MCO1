#ifndef RPN_CALCULATOR_C
#define RPN_CALCULATOR_C

#include "rpn_calculator.h"

int isOperator(char* input)
{
    char* operators[15] = {"+", "-", "*", "/", "%", "^", "<", ">", "==", "&&", "||", "<=", ">=","!=", "!"};

    for (int i = 0; i < 15; i++)
    {
        if (strcmp(input, operators[i]) == 0)
        {
            return i + 1;
        }
    }

    return 0;
}

char *compute(char* operands[], char operator)
{
    int result = 1;
    int num1 = atoi(operands[1]);
    int num2 = atoi(operands[0]);
    char *returnValue = (char*) malloc (11);

    switch (operator)
    {
        case 1:
            result = (num1 + num2);
            break;
        case 2:
            result =  (num1 - num2);
            break;
        case 3:
            result = (num1 * num2);
            break;
        case 4:
            result =  (num1 / num2);
            break;
        case 5:
            result = (num1 % num2);
            break;
        case 6:
            for (int i = 0; i < num2; i++){
                result *= num1;
            }
            break;
        case 7:
            result = (num1 < num2);
            break;
        case 8:
            result = (num1 > num2);
            break;
        case 9:
            result = (num1 == num2);
            break;
        case 10:
            result = (num1 && num2);
            break;
        case 11:
            result = (num1 || num2);
            break;
        case 12:
            result = (num1 <= num2);
            break;
        case 13:
            result = (num1 >= num2);
            break;
        case 14:
            result = (num1 != num2);
            break;
        case 15:
            result = (!num2);
            break;
    }

    sprintf(returnValue, "%d", result);

    return returnValue;
}

int evaluatePostfix(Queue* queue)
{
    Stack tempStack;
    initStack(&tempStack);

    while(!isQueueEmpty(*queue))
    {
        char* operands[2] = {0, 0};
        int token = isOperator(queue->front->string);

        if (token == 4 && peekStack(tempStack) == 0)
        {
            clearQueue(queue);
            clearStack(&tempStack);
            printf("Error: Division by zero\n");
            return atoi(peekStack(tempStack));
        }

        if (token > 0)
        {
            strcpy(operands[0], peekStack(tempStack));
            pop(&tempStack);
            strcpy(operands[1], peekStack(tempStack));
            pop(&tempStack);
            push(&tempStack, compute(operands, token));
            dequeue(queue);
        }
        else
        {
            push(&tempStack, queue->front->string);
            dequeue(queue);
        }
    }

    return atoi(peekStack(tempStack));
}

#endif
