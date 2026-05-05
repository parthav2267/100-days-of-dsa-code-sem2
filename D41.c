#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(Queue* q, int data) {
    Node* temp = newNode(data);
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    
    Node* temp = q->front;
    int data = temp->data;
    
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}

int main() {
    Queue q;
    initQueue(&q);
    
    int N, op, val;
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &op);
        
        if(op == 1) {  
            scanf("%d", &val);
            enqueue(&q, val);
        }
        else if(op == 2) {  
            printf("%d\n", dequeue(&q));
        }
    }
    
    return 0;
}
