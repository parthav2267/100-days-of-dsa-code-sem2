#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int v, weight;
    struct Node* next;
} Node;

// Min Heap node
typedef struct {
    int vertex, dist;
} HeapNode;

HeapNode heap[1000];
int size = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into heap
void push(int v, int d) {
    heap[++size] = (HeapNode){v, d};
    int i = size;

    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// Pop from heap
HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int smallest = i;
        int l = 2*i, r = 2*i + 1;

        if (l <= size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r <= size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return top;
}

// Add edge
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra function
void dijkstra(Node* adj[], int n, int src) {
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode curr = pop();
        int u = curr.vertex;

        for (Node* temp = adj[u]; temp != NULL; temp = temp->next) {
            int v = temp->v;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }
}

// Driver
int main() {
    int n = 5;
    Node* adj[MAX] = {NULL};

    // Example graph
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 0, 7);

    dijkstra(adj, n, 0);

    return 0;
}