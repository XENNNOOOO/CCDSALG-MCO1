#ifndef SHUNTING_YARD_ALGO_C
#define SHUNTING_YARD_ALGO_C

#include "shunting_yard_algo.h"

Queue infixToPostfix(char input[]) {
    char        tempString[50] = {'\0'};
    char        tempChar[2] = {'\0', '\0'};
    Stack       stack;
    Queue       postfix;
    HashMap     operatorMap = fillPrecedenceMap();

    initQueue(&postfix);
    initStack(&stack);

    strcpy(tempString, "");

    for (int i = 0; i < (int)strlen(input); i++)
    {
        tempChar[0] = input[i];

        if (isdigit(input[i]))
        {
            if (i > 0 && isCharOperator(input[i - 1]))
            {
                push(&stack, tempString);
                strcpy(tempString, "");
            }
            strcat(tempString, tempChar);
        }
        else if (isCharOperator(tempChar[0]))
        {
            if (i > 0 && isdigit(input[i - 1]))
            {
                enqueue(&postfix, tempString);
                strcpy(tempString, "");
            }
            strcat(tempString, tempChar);

            if (isStringOperator(tempString))
            {
                while (!isStackEmpty(stack) && operatorPrecedence(tempChar, operatorMap) <= operatorPrecedence(peekStack(stack), operatorMap))
                {
                    enqueue(&postfix, pop(&stack));
                }

                push(&stack, tempString);
                strcpy(tempString, "");
            }
        }
        else if (tempChar[0] == '(')
        {
            push(&stack, tempChar);
        }
        else if (tempChar[0] == ')')
        {
            if (strcmp(tempString, "") != 0) {
                enqueue(&postfix, tempString);
                strcpy(tempString, "");
            }

            while (peekStack(stack)[0] != '(') {
                enqueue(&postfix, pop(&stack));
            }
            pop(&stack);
        }

    }

    if (strcmp(tempString, "") != 0)
    {
        enqueue(&postfix, tempString);
        strcpy(tempString, "");
    }

    while(!isStackEmpty(stack))
    {
        enqueue(&postfix, pop(&stack));
    }

    return postfix;
}

HashMap fillPrecedenceMap()
{
    HashMap operatorMap;

    char* signs[HASHMAP_MAX_SIZE] = {"+", "-", "*", "!", "/", "%", "<", ">", "<=", ">=", "==", "!=", "||", "&&", "^"};
    int keyValues[HASHMAP_MAX_SIZE] = {1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 7, 8};
    initHashMap(&operatorMap);

    for (int i = 0; i < HASHMAP_MAX_SIZE; i++) 
    {
        put(&operatorMap, signs[i], keyValues[i]);
    }

    return operatorMap;
}

int operatorPrecedence(char* key, HashMap operatorMap)
{
    return get(&operatorMap, key);
}

bool isStringOperator(char* tempChar)
{
    return strcmp(tempChar, "==") == 0 || strcmp(tempChar, ">=") == 0 || strcmp(tempChar, "<=") == 0 || 
           strcmp(tempChar, "%") == 0 || strcmp(tempChar, "||") == 0 || strcmp(tempChar, "&&") == 0 || 
           strcmp(tempChar, "!=") == 0;
}

bool isCharOperator(char tempChar)
{
    return tempChar == '+' || tempChar == '-' || tempChar == '*' || tempChar == '/' || 
           tempChar == '!' || tempChar == '^' || tempChar == '>' || tempChar == '<';
}

#endif