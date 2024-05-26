#include "queue.h"

/**
 * Initializes the queue by setting the front and rear pointers to NULL.
 * 
 * @param queue A pointer to the queue to be initialized.
 */
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

/**
 * Adds a new element to the rear of the queue.
 * 
 * @param queue A pointer to the queue where the element will be added.
 * @param string The string to be added to the queue.
 */
void enqueue(Queue* queue, char* string) {
    Node* newNode = (Node*) allocate(sizeof(Node));

    newNode->string = string;
    newNode->next = NULL;
    newNode->prev = queue->rear;

    if (isQueueEmpty(*queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
} 

/**
 * Removes and returns the front element of the queue.
 * 
 * @param queue A pointer to the queue from which the element will be removed.
 * 
 * @return The string at the front of the queue, or NULL if the queue is empty.
 */
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
    } else {
        queue->front->prev = NULL;
    }

    return data;
}

/**
 * Returns the front element of the queue without removing it.
 * 
 * @param queue A pointer to the queue to peek at.
 * 
 * @return The string at the front of the queue, or NULL if the queue is empty.
 */
char* peekQueue(Queue* queue) {
    if (isQueueEmpty(*queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    return queue->front->string;
}

/**
 * Checks if the queue is empty.
 * 
 * @param queue The queue to be checked.
 * 
 * @return True if the queue is empty, false otherwise.
 */
bool isQueueEmpty(Queue queue) {
    return queue.front == NULL && queue.rear == NULL;
}

/**
 * Clears all elements from the queue.
 * 
 * This function removes all elements from the given queue by 
 * repeatedly dequeuing elements until the queue is empty.
 * 
 * @param queue A pointer to the queue to be cleared.
 * 
 * @return void
 */
void clearQueue(Queue* queue) {
    while (!isQueueEmpty(*queue)) {
        dequeue(queue);
    }
}
