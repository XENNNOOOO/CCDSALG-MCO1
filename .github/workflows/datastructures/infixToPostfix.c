#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "queue.c"
#include "stack.c"
#include "hashmap.c"


typedef char String[128];

/*

typedef struct QueueTag {
    struct NodeTag* front;
    struct NodeTag* rear;
} Queue;

typedef struct StackTag {
    char*   strings[MAX_SIZE];
    int     topIndex;
} Stack;


void initQueue(Queue* queue);
void enqueue(Queue* queue, char* string);
char* dequeue(Queue* queue);
char* frontOfQueue(Queue* queue);
char* rearOfQueue(Queue* queue);
bool isQueueEmpty(Queue queue);
void clearQueue(Queue* queue);

void initStack(Stack* stack);
void push(Stack* stack, char* string);
char* pop(Stack* stack);
char* peekStack(Stack stack);
bool isStackEmpty(Stack stack);
bool isStackFull(Stack stack);
void clearStack(Stack* stack);

unsigned int hash(char* key);
void initHashMap(HashMap* map);
void put(HashMap* map, char* key, int value);
int get(HashMap* map, char* key);
void freeHashMap(HashMap* map);
*/

/*
string input
stack string operators
string tempString
char tempChar
return: queue string output
*/

int operatorPrecedence(char* key, HashMap* operatorMap)
{
    String signs[16] = {"+", "-", "*", "!" "/", "%", "<", ">", "<=", ">=", "==", "!=", "||", "&&", "^"};

    initHashMap(operatorMap);
    put(operatorMap, signs[3], 1);
    put(operatorMap, signs[2], 2);
    put(operatorMap, signs[4], 2);
    put(operatorMap, signs[5], 2);
    put(operatorMap, signs[0], 3);
    put(operatorMap, signs[1], 3);
    put(operatorMap, signs[6], 4);
    put(operatorMap, signs[7], 4);
    put(operatorMap, signs[8], 4);
    put(operatorMap, signs[9], 4);
    put(operatorMap, signs[10], 5);
    put(operatorMap, signs[11], 5);
    put(operatorMap, signs[14], 6);
    put(operatorMap, signs[13], 7);
    put(operatorMap, signs[12], 8);


    int numPrecedence = get(operatorMap, key);

    return numPrecedence;
}



int isStringOperator(String tempString)
{
    int x;


    if (strcmp(tempString, "==") == 1 || strcmp(tempString, ">=") == 1 || strcmp(tempString, "<=") == 1 || strcmp(tempString, "%") == 1 || strcmp(tempString, "||") == 1 || strcmp(tempString, "&&") == 1 || strcmp(tempString, "!=") == 1)
    {
        x = 1;
    }
    else x = 0;

    return x;
}


int isCharOperator(char tempChar)
{
    int x;

    if (tempChar == 'x' || tempChar == '-' || tempChar == '*' || tempChar == '/' || tempChar == '!' || tempChar == '^' || tempChar == '>' || tempChar == '<')
    {
        x = 1;
    }
    else x = 0;

    return x;
}



Queue infixToPostfix(char input[], Stack* stack)
{
    int i;

    Queue postfix;
    String tempString;
    char tempChar;
    HashMap operatorMap;
    initHashMap(&operatorMap);
    char ops[3];

    for(i = 0; i < strlen(input); i++)
    {
        tempChar = input[i];

        if(isdigit(input[i]))
        {
            if (i>0 && isCharOperator(i-1))
            {
                push(stack, &(input[i]));
                strcpy(tempString, "");
            }
        strcpy(tempString, &tempChar);
        }
        else if (isCharOperator(tempChar) == 1)
        {
            if (isdigit(input[i-1]))
            {
                enqueue(&postfix, tempString);
                strcpy(tempString, "");
            }
            strcat(tempString, &tempChar);

            if (isStringOperator(tempString) == 1)
            {
                while(operatorPrecedence(&tempChar, &operatorMap), operatorPrecedence((peekStack(*stack)), &operatorMap))
                {
                    strcpy(ops, pop(stack));
                    enqueue(&postfix, ops);
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
            enqueue(&postfix, tempString);
            strcpy(tempString, "");

            while (atoi(peekStack(*stack))!= '(')
            {
                enqueue(&postfix, pop(stack));
            }
            pop(stack);
        }

    if (strcmp(tempString, "") != 0)
    {
        enqueue(&postfix, tempString);
        strcpy(tempString, "");
    }

    while(!isStackEmpty(*stack))
    {
        enqueue(&postfix, pop(stack));
    }
    }

    return postfix;
}


int main()
{
    String infix; 
    Stack operators;
    String queueOutput;
    Queue postfix;

    initQueue(&postfix);
    initStack(&operators);

    printf("Infix Notation: ");
    fgets(infix, 129, stdin);

    postfix = infixToPostfix(infix, &operators);

    while(!isQueueEmpty(postfix))
    {
        //char* dequeue(Queue* queue)
        strcpy(queueOutput, dequeue(&postfix));

        printf("%s", queueOutput);
    }


}
