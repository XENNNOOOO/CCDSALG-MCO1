#include "calculator.h"

#define MAX_SIZE STRING_LEN

typedef struct StackTag {
    char*   strings[MAX_SIZE];
    int     topIndex;
} Stack;

void initStack(Stack* stack);
void push(Stack* stack, char* string);
char* pop(Stack* stack);
char* peek(Stack* stack);
bool isStackEmpty(Stack stack);
bool isStackFull(Stack stack);
