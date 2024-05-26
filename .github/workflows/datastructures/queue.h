#include "../calculator.h"
#include "../utils.c"

typedef struct NodeTag {
    char*           string;
    struct NodeTag* next;
    struct NodeTag* prev;
} Node;

typedef struct QueueTag {
    struct NodeTag* front;
    struct NodeTag* rear;
} Queue;

void initQueue(Queue* queue);
void enqueue(Queue* queue, char* string);
char* dequeue(Queue* queue);
char* peekQueue(Queue* queue);
bool isQueueEmpty(Queue queue);
