#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
char* frontOfQueue(Queue* queue);
char* rearOfQueue(Queue* queue);
bool isQueueEmpty(Queue queue);
void clearQueue(Queue* queue);

#endif