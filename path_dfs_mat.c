#include <stdio.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int path[MAX_VERTICES];
int pathIndex = 0;

void initGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
}

void printPaths(int source, int destination, int vertices) {
    visited[source] = 1;
    path[pathIndex] = source;
    pathIndex++;

    if (source == destination) {
        // Print the path when the destination is reached
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        // Recur for all the vertices adjacent to the current vertex
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[source][i] == 1 && !visited[i]) {
                printPaths(i, destination, vertices);
            }
        }
    }

    // Remove the current vertex from the path and mark it as unvisited
    pathIndex--;
    visited[source] = 0;
}

int main() {
    int vertices, edges, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initGraph(vertices);

    printf("Enter the edges (format: start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    printf("All paths from %d to %d:\n", source, destination);
    printPaths(source, destination, vertices);

    return 0;
}
