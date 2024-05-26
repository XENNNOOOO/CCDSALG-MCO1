#include "stack.h"

void initStack(Stack* stack) {
    stack->topIndex = -1;
}

void push(Stack* stack, char* string) {
    if (!isStackFull(*stack)) {
        stack->strings[++stack->topIndex] = string;
    } else {
        printf("Stack overflow!\n");
    }
}

char* pop(Stack* stack) {
    if (!isStackEmpty(*stack)) {
        return stack->strings[stack->topIndex--];
    } else {
        printf("Stack underflow!\n");
        return NULL;
    }
}

char* peek(Stack* stack) {
    return stack->strings[stack->topIndex];
}

bool isStackEmpty(Stack stack) {
    return stack.topIndex == -1;
}

bool isStackFull(Stack stack) {
    return stack.topIndex == MAX_SIZE - 1;
}
