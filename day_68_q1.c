#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[MAX], front = 0, rear = 0;

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int topo[MAX], idx = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        topo[idx++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // Check for cycle
    if (idx != n) {
        printf("Cycle detected! Topological sort not possible\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++)
            printf("%d ", topo[i]);
    }

    return 0;
}