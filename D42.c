#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    int value = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return value;
}

int isEmptyQueue() {
    return front == -1;
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int isEmptyStack() {
    return top == -1;
}

void reverseQueue() {
    while (!isEmptyQueue()) {
        push(dequeue());
    }
    
    while (!isEmptyStack()) {
        enqueue(pop());
    }
}

void displayQueue() {
    if (isEmptyQueue()) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int N, value;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        enqueue(value);
    }
    
    reverseQueue();
    
    displayQueue();
    
    return 0;
}
