#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int visited[], int adj[MAX][MAX], int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    // push after visiting all neighbors
    push(node);
}

// Topological Sort function
void topologicalSort(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    // print in reverse order
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // directed edge
    }

    topologicalSort(adj, n);

    return 0;
}