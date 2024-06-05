#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "shunting_yard_algo.h"


typedef char String[128];
#define HASHMAP_MAX_SIZE 16

int operatorPrecedence(char* key)
{
    HashMap* operatorMap;

    String signs[16] = {"+", "-", "*", "!" "/", "%", "<", ">", "<=", ">=", "==", "!=", "||", "&&", "^"};
    int keyValues[16] = {1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 7, 8};
    initHashMap(operatorMap);

    for(int i = 0; i < HASHMAP_MAX_SIZE; i++) 
    {
        put(operatorMap, signs[i], keyValues[i]);
    }
    
    int precedence = get(operatorMap, key);
    freeHashMap(operatorMap);

    return precedence;
}



int isStringOperator(String tempChar)
{
    int isString;

    if (strcmp(tempChar, "==") == 1 || strcmp(tempChar, ">=") == 1 || strcmp(tempChar, "<=") == 1 || strcmp(tempChar, "%") == 1 || strcmp(tempChar, "||") == 1 || strcmp(tempChar, "&&") == 1 || strcmp(tempChar, "!=") == 1)
    {
        isString = 1;
    }
    else isString = 0;

    return isString;
}


int isCharOperator(char tempChar)
{
    int isChar;

    if (tempChar == 'x' || tempChar == '-' || tempChar == '*' || tempChar == '/' || tempChar == '!' || tempChar == '^' || tempChar == '>' || tempChar == '<')
    {
        isChar = 1;
    }
    else isChar = 0;

    return isChar;
}



Queue* infixToPostfix(char input[])
{
    int i;
    char tempChar[2] = {'\0'};
    Stack* stack;
    Queue* postfix;
    initQueue(postfix);
    initStack(stack);

    for(i = 0; i < strlen(input); i++)
    {
        strcpy(tempChar, input[i]);

        if(isdigit(input[i]))
        {
            if (i > 0 && isCharOperator(i-1))
            {
                push(stack, &(input[i]));
                strcpy(tempChar, "");
            }
        strcpy(tempChar, &tempChar);
        }
        else if (isCharOperator(tempChar))
        {
            if (i > 0 && isdigit(input[i-1]))
            {
                enqueue(postfix, tempChar);
                strcpy(tempChar, "");
            }
            strcat(tempChar, tempChar);

            if (isStringOperator(tempChar))
            {
                while(operatorPrecedence(tempChar) < operatorPrecedence((peekStack(*stack))))
                {
                    enqueue(postfix, pop(stack));
                }

                push(stack, tempChar);
                strcpy(tempChar, "");
            }
        }
        else if (tempChar == '(')
        {
            push(stack, &tempChar);
        }
        else if (tempChar == ')')
        {
            enqueue(postfix, tempChar);
            strcpy(tempChar, "");

            while (peekStack(*stack) != '(')
            {
                enqueue(postfix, pop(stack));
            }
            pop(stack);
        }

    if (strcmp(tempChar, "") != 0)
    {
        enqueue(postfix, tempChar);
        strcpy(tempChar, "");
    }

    while(!isStackEmpty(*stack))
    {
        enqueue(postfix, pop(stack));
    }
    }

    return postfix;
}
}

