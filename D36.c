#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // Small size to demonstrate circular behavior

struct CircularQueue {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
};

struct CircularQueue* createQueue(int capacity) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(struct CircularQueue* queue) {
    return queue->size == 0;
}

int isFull(struct CircularQueue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    
    queue->arr[queue->rear] = value;
    queue->size++;
    printf("Enqueued: %d (front=%d, rear=%d, size=%d)\n", value, queue->front, queue->rear, queue->size);
}

int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    
    int value = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    
    queue->size--;
    printf("Dequeued: %d (front=%d, rear=%d, size=%d)\n", value, queue->front, queue->rear, queue->size);
    return value;
}

void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements (front to rear): ");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->arr[index]);
    }
    printf("\n");
}

void freeQueue(struct CircularQueue* queue) {
    free(queue->arr);
    free(queue);
}

int main() {
    int n, m, value;
    
    struct CircularQueue* queue = createQueue(MAX_SIZE);
    
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(queue, value);
    }
    
    printf("\nAfter enqueue operations:\n");
    display(queue);
    
    printf("\nEnter number of elements to dequeue: ");
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        dequeue(queue);
    }
    
    printf("\nAfter dequeue operations:\n");
    display(queue);
    
    freeQueue(queue);
    
    return 0;
}
