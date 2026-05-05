#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node** arr;
    int front;
    int rear;
    int capacity;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->arr = (struct Node**)malloc(sizeof(struct Node*) * capacity);
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(struct Queue* queue, struct Node* node) {
    queue->arr[queue->rear++] = node;
}

struct Node* dequeue(struct Queue* queue) {
    return queue->arr[queue->front++];
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) {
        return NULL;
    }
    
    struct Node* root = createNode(arr[0]);
    
    struct Queue* queue = createQueue(n);
    enqueue(queue, root);
    
    int i = 1;
    while (!isEmpty(queue) && i < n) {
        struct Node* current = dequeue(queue);
        
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(queue, current->left);
        }
        i++;
        
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(queue, current->right);
        }
        i++;
    }
    
    free(queue->arr);
    free(queue);
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = buildTree(arr, n);
    
    inorderTraversal(root);
    printf("\n");
    
    freeTree(root);
    
    return 0;
}
