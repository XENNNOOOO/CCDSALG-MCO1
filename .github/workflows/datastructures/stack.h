#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 128

typedef struct StackTag {
    char*   strings[MAX_SIZE];
    int     topIndex;
} Stack;

void initStack(Stack* stack);
void push(Stack* stack, char* string);
char* pop(Stack* stack);
char* peekStack(Stack stack);
bool isStackEmpty(Stack stack);
bool isStackFull(Stack stack);
void clearStack(Stack* stack);

#endif