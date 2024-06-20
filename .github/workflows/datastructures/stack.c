#ifndef STACK_C
#define STACK_C

#include "stack.h"

/**
 * Initializes the stack by setting the top index to -1, indicating that the stack is empty.
 * 
 * @param stack A pointer to the stack to be initialized.
 */
void initStack(Stack* stack) {
    stack->topIndex = -1;
}

/**
 * Pushes a new string onto the stack. If the stack is full, prints an error message.
 * 
 * @param stack A pointer to the stack where the string will be pushed.
 * @param string The string to be pushed onto the stack.
 */
void push(Stack* stack, char* string) {
    if (!isStackFull(*stack)) {
        stack->topIndex++;
        stack->strings[stack->topIndex] = string;
    } else {
        printf("Stack overflow!\n");
    }
}

/**
 * Pops the top string off the stack and returns it. If the stack is empty, prints an error message and returns NULL.
 * 
 * @param stack A pointer to the stack from which the string will be popped.
 * 
 * @return The string at the top of the stack, or NULL if the stack is empty.
 */
char* pop(Stack* stack) {
    if (!isStackEmpty(*stack)) {
        return stack->strings[stack->topIndex--];
    } else {
        printf("Stack underflow!\n");
        return NULL;
    }
}

/**
 * Returns the string at the top of the stack without removing it.
 * 
 * @param stack The stack to peek at.
 * 
 * @return The string at the top of the stack.
 */
char* peekStack(Stack stack) {
    return stack.strings[stack.topIndex];
}

/**
 * Checks if the stack is empty.
 * 
 * @param stack The stack to be checked.
 * 
 * @return True if the stack is empty, false otherwise.
 */
bool isStackEmpty(Stack stack) {
    return stack.topIndex == -1;
}

/**
 * Checks if the stack is full.
 * 
 * @param stack The stack to be checked.
 * 
 * @return True if the stack is full, false otherwise.
 */
bool isStackFull(Stack stack) {
    return stack.topIndex == MAX_SIZE - 1;
}

/**
 * Clears all elements from the stack.
 * 
 * This function removes all elements from the given stack by 
 * repeatedly popping elements until the stack is empty.
 * 
 * @param stack A pointer to the stack to be cleared.
 * 
 * @return void
 */
void clearStack(Stack* stack) {
    while(!isStackEmpty(*stack)) {
        pop(stack);
    }
}

#endif