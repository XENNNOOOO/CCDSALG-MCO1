#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "shunting_yard_algo.h"

#define HASHMAP_MAX_SIZE 16

HashMap fillPrecedenceMap() {
    HashMap operatorMap;

    char* signs[HASHMAP_MAX_SIZE] = {"+", "-", "*", "!" "/", "%", "<", ">", "<=", ">=", "==", "!=", "||", "&&", "^"};
    int keyValues[HASHMAP_MAX_SIZE] = {1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 7, 8};
    initHashMap(&operatorMap);

    for(int i = 0; i < HASHMAP_MAX_SIZE; i++) 
    {
        put(&operatorMap, signs[i], keyValues[i]);
    }

    return operatorMap;
}

int operatorPrecedence(char* key, HashMap operatorMap)
{
    return get(&operatorMap, key);
}

bool isStringOperator(char tempChar[])
{
    if (strcmp(tempChar, "==") == 1 || strcmp(tempChar, ">=") == 1 || strcmp(tempChar, "<=") == 1 || strcmp(tempChar, "%") == 1 || strcmp(tempChar, "||") == 1 || strcmp(tempChar, "&&") == 1 || strcmp(tempChar, "!=") == 1)
    {
        return true;
    }

    return false;
}

bool isCharOperator(char tempChar[])
{
    if (tempChar == 'x' || tempChar == '-' || tempChar == '*' || tempChar == '/' || tempChar == '!' || tempChar == '^' || tempChar == '>' || tempChar == '<')
    {
        return true;
    }
    
    return false;
}

Queue* infixToPostfix(char input[])
{
    int i;
    String tempString;
    char tempChar[2] = {'\0'};
    Stack* stack;
    Queue* postfix;
    HashMap operatorMap = fillPrecedenceMap();
    initQueue(postfix);
    initStack(stack);

    strcpy(tempString, "");

    for(i = 0; i < strlen(input); i++)
    {
        strcpy(tempChar, input[i]);

        if(isdigit(input[i]))
        {
            if (i > 0 && isCharOperator(i-1))
            {
                push(stack, &(input[i]));
                strcpy(tempString, "");
            }
        strcpy(tempString, &tempChar);
        }
        else if (isCharOperator(tempChar))
        {
            if (i > 0 && isdigit(input[i-1]))
            {
                enqueue(postfix, tempString);
                strcpy(tempString, "");
            }
            strcat(tempString, tempChar);

            if (isStringOperator(tempString))
            {
                while(operatorPrecedence(tempChar, operatorMap) < operatorPrecedence(peekStack(*stack), operatorMap))
                {
                    enqueue(postfix, pop(stack));
                }

                push(stack, tempString);
                strcpy(tempString, "");
            }
        }
        else if (tempChar == '(')
        {
            push(stack, &tempChar);
        }
        else if (tempChar == ')')
        {
            enqueue(postfix, tempString);
            strcpy(tempString, "");

            while (peekStack(*stack) != '(')
            {
                enqueue(postfix, pop(stack));
            }
            pop(stack);
        }

    }
    
    if (strcmp(tempString, "") != 0)
    {
        enqueue(postfix, tempString);
        strcpy(tempString, "");
    }

    while(!isStackEmpty(*stack))
    {
        enqueue(postfix, pop(stack));
    }

    return postfix;
}
