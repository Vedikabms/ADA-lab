#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Edge {
    int u, v, weight;
};

int parent[MAX];
int Find(int i) {
    while (parent[i] != -1) {
        i = parent[i];
    }
    return i;
}

void Union(int i, int j) {
    int rootI = Find(i);
    int rootJ = Find(j);
    if (rootI != rootJ) {
        parent[rootJ] = rootI;
    }
}
void kruskals(int n, struct Edge edges[], int m) {
    int count = 0;
    int sum = 0;
    struct Edge mst[MAX];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i].weight > edges[j].weight) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int rootU = Find(u);
        int rootV = Find(v);
        if (rootU != rootV) {
            mst[count] = edges[i];
            count++;
            sum += edges[i].weight;
            Union(rootU, rootV);
            if (count == n - 1) {
                break;
            }
        }
    }
    printf("\nEdges in the Minimum Spanning Tree (MST):\n");
    for (int i = 0; i < count; i++) {
        printf("%d - %d (Weight: %d)\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    printf("Total weight of the MST: %d\n", sum);
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    struct Edge edges[m];

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    kruskals(n, edges, m);

    return 0;
}
