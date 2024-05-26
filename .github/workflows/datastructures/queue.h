#include "calculator.h"

#define MAX_SIZE STRING_LEN

typedef struct NodeTag {
    char* string;
    Node* next;
} Node;

typedef struct QueueTag {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* queue);
void enqueue(Queue* queue, char* string);
char* dequeue(Queue* queue);
char* peek(Queue* queue);
bool isQueueEmpty(Queue queue);
