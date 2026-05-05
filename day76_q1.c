#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void dfs(int adj[MAX][MAX], int n, int node, int* visited) {
    visited[node] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(adj, n, i, visited);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int adj[MAX][MAX] = {0};
    
    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    int visited[MAX] = {0};
    int components = 0;
    
    // Count connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(adj, n, i, visited);
        }
    }
    
    printf("%d\n", components);
    
    return 0;
}
