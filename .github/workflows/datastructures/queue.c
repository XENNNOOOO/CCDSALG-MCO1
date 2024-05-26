#include "queue.h"

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue* queue, char* string) {
    Node* newNode = (Node*) malloc (sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed...\n");
        return;
    }

    newNode->string = string;
    newNode->next = NULL;

    if (isQueueEmpty(*queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
} 

char* dequeue(Queue* queue) {
    if (isQueueEmpty(*queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    char* data = queue->front->string;
    
    Node* temp = queue->front;
    queue->front = queue->front->next;

    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

char* peek(Queue* queue) {
    if (isQueueEmpty(*queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    return queue->front->string;
}

bool isQueueEmpty(Queue queue) {
    return queue.front == NULL && queue.rear == NULL;
}
