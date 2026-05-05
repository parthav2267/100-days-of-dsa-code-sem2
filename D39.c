#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Min Heap structure
struct MinHeap {
    int arr[MAX_SIZE];
    int size;
};

// Function to initialize min heap
void initHeap(struct MinHeap* heap) {
    heap->size = 0;
}

// Function to check if heap is empty
int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

// Function to check if heap is full
int isFull(struct MinHeap* heap) {
    return heap->size == MAX_SIZE;
}

// Function to get parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get left child index
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get right child index
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify up (used during insertion)
void heapifyUp(struct MinHeap* heap, int index) {
    while (index > 0 && heap->arr[parent(index)] > heap->arr[index]) {
        swap(&heap->arr[parent(index)], &heap->arr[index]);
        index = parent(index);
    }
}

// Function to heapify down (used during extraction)
void heapifyDown(struct MinHeap* heap, int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
        smallest = left;
    }
    
    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Function to insert a value into min heap
void insert(struct MinHeap* heap, int value) {
    if (isFull(heap)) {
        printf("Heap Overflow!\n");
        return;
    }
    
    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
    
    printf("Inserted: %d\n", value);
}

// Function to extract minimum element (root)
int extractMin(struct MinHeap* heap) {
    if (isEmpty(heap)) {
        return -1;
    }
    
    int minValue = heap->arr[0];
    
    // Replace root with last element
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    
    // Heapify down from root
    heapifyDown(heap, 0);
    
    return minValue;
}

// Function to peek at minimum element (root)
int peek(struct MinHeap* heap) {
    if (isEmpty(heap)) {
        return -1;
    }
    return heap->arr[0];
}

// Function to display heap
void display(struct MinHeap* heap) {
    if (isEmpty(heap)) {
        printf("Heap is empty\n");
        return;
    }
    
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MinHeap heap;
    initHeap(&heap);
    
    int N;
    char operation[20];
    int value;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(&heap, value);
        }
        else if (strcmp(operation, "extractMin") == 0) {
            value = extractMin(&heap);
            printf("%d\n", value);
        }
        else if (strcmp(operation, "peek") == 0) {
            value = peek(&heap);
            printf("%d\n", value);
        }
    }
    
    return 0;
}
