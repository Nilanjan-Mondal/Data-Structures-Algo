#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];
int v; // Number of vertices

void add_edge(int src, int dest, int bi_dir) {
    printf("Adding edge between %d and %d\n", src, dest);
    graph[src][dest] = 1;
    if (bi_dir) {
        graph[dest][src] = 1;
    }
}

void dfs(int curr) {
    printf("Visiting node %d\n", curr);
    visited[curr] = 1;
    
    for (int i = 0; i < v; i++) {
        if (graph[curr][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    // Initialize graph and visited array
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int s, d;
        scanf("%d %d", &s, &d);
        add_edge(s, d, 1);
    }
    
    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);
    printf("Starting DFS traversal:\n");
    dfs(start);
    
    return 0;
}
