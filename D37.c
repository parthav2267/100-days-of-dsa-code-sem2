#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int arr[MAX_SIZE];
    int size;
};

void initPQ(struct PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(struct PriorityQueue* pq) {
    return pq->size == MAX_SIZE;
}

void insert(struct PriorityQueue* pq, int value) {
    if (isFull(pq)) {
        printf("Priority Queue Overflow!\n");
        return;
    }
    
    int i = pq->size - 1;
    
    while (i >= 0 && pq->arr[i] > value) {
        pq->arr[i + 1] = pq->arr[i];
        i--;
    }
    
    pq->arr[i + 1] = value;
    pq->size++;
    
    printf("Inserted: %d\n", value);
}

int delete(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        return -1;
    }
    
    int value = pq->arr[0];
    
    for (int i = 0; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    
    pq->size--;
    return value;
}

int peek(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        return -1;
    }
    return pq->arr[0];
}

void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initPQ(&pq);
    
    int N;
    char operation[10];
    int value;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(&pq, value);
        }
        else if (strcmp(operation, "delete") == 0) {
            value = delete(&pq);
            printf("%d\n", value);
        }
        else if (strcmp(operation, "peek") == 0) {
            value = peek(&pq);
            printf("%d\n", value);
        }
    }
    
    return 0;
}
