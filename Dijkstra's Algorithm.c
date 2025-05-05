#include <stdio.h>
#include <limits.h>

#define V 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int n, int src) {
    printf("Vertex\t\tDistance from Source %d\n", src);
    for (int i = 0; i < n; i++)
        printf("%d -> %d\t\t%d\n", src, i, dist[i]);
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];
    int visited[V];


    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, visited[i] = 0;

    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;


        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, n, src);
}


int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter the adjacency matrix (use 0 for no edge):\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}
