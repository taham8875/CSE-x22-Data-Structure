#include <stdio.h>
#define MAXQUEUE 10

typedef struct queue {
    int front;
    int rear;
    int size;
    int items[MAXQUEUE];
} Queue;

void createQueue(Queue *pMyQueue) {
    pMyQueue->front = 0;
    pMyQueue->rear = -1;
    pMyQueue->size = 0;
}

void append(int *data, Queue *pMyQueue) {
    pMyQueue->rear = (pMyQueue->rear + 1) % MAXQUEUE;
    pMyQueue->items[pMyQueue->rear] = *data;
    pMyQueue->size++;
}

int serve(Queue *pMyQueue) {
    int data = pMyQueue->items[pMyQueue->front];
    pMyQueue->front = (pMyQueue->front + 1) % MAXQUEUE;
    pMyQueue->size--;
    return data;
}

int queueEmpty(Queue *pMyQueue) {
    return !pMyQueue->size;
}

int queueFull(Queue *pMyQueue) {
    return (pMyQueue->size == MAXQUEUE);
}

int queueSize(Queue *pMyQueue) {
    return pMyQueue->size;
}

void clearQueue(Queue *pMyQueue) {
    pMyQueue->front = 0;
    pMyQueue->rear = -1;
    pMyQueue->size = 0;
}

int main() {
    Queue myQueue;
    createQueue(&myQueue);
    printf("Queue is created and inisialized\n");
    if (queueEmpty(&myQueue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
    // push some elements to the queue
    for (int i = 10; i <= 120; i += 10) {
        if (!queueFull(&myQueue)) {
            append(&i, &myQueue);
            printf("%d appended into the queue\n", i);
        } else {
            printf("Queue is full!\n");
        }
    }

    printf("queue size is %d\n", queueSize(&myQueue));

    for (int i = 0; i < 10; i++) {
        printf("%d ", myQueue.items[i]);
    }
    printf("\n");

    // serve some elements
    for (int i = 0; i < queueSize(&myQueue) / 2; i++) {
        if (!queueEmpty(&myQueue)) {
            printf("%d served from the queue\n", serve(&myQueue));

        } else {
            printf("queue is empty!\n");
        }
    }

    // clear the queue
    printf("queue will be cleared\n");
    clearQueue(&myQueue);
    // now queue is empty
    if (queueEmpty(&myQueue)) {
        printf("queue is empty\n");
    } else {
        printf("queue is not empty\n");
    }
}