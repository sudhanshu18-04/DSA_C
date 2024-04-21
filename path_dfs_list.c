#include <stdio.h>
#include <stdlib.h>

// Node structure for the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Structure to represent a path
struct Path {
    int* vertices;
    int size;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int start, int end) {
    // Add edge to the adjacency list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = end;
    newNode->next = graph->adjList[start];
    graph->adjList[start] = newNode;
}

void printPathsUtil(struct Graph* graph, int source, int destination, struct Path* currentPath, struct Path* lisPath) {
    // Add the current vertex to the path
    currentPath->vertices[currentPath->size++] = source;

    // If the source is the destination, check if the current path is longer than the LIS path
    if (source == destination) {
        if (currentPath->size > lisPath->size) {
            // Update the LIS path
            lisPath->size = currentPath->size;
            for (int i = 0; i < currentPath->size; i++) {
                lisPath->vertices[i] = currentPath->vertices[i];
            }
        }
    } else {
        // Recur for all vertices adjacent to the current vertex
        struct Node* temp = graph->adjList[source];
        while (temp != NULL) {
            printPathsUtil(graph, temp->vertex, destination, currentPath, lisPath);
            temp = temp->next;
        }
    }

    // Remove the current vertex from the path
    currentPath->size--;
}

void printPaths(struct Graph* graph, int source, int destination) {
    // Allocate memory for paths
    struct Path currentPath;
    currentPath.vertices = (int*)malloc(graph->vertices * sizeof(int));
    currentPath.size = 0;

    struct Path lisPath;
    lisPath.vertices = (int*)malloc(graph->vertices * sizeof(int));
    lisPath.size = 0;

    // Call the recursive function to print paths
    printPathsUtil(graph, source, destination, &currentPath, &lisPath);

    // Print the LIS path
    printf("Longest Increasing Path: ");
    for (int i = 0; i < lisPath.size; i++) {
        printf("%d ", lisPath.vertices[i]);
    }
    printf("\n");

    // Deallocate memory
    free(currentPath.vertices);
    free(lisPath.vertices);
}

int main() {
    int vertices, edges, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the edges (format: start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    printf("All paths from %d to %d:\n", source, destination);
    printPaths(graph, source, destination);

    // Deallocate memory for the graph
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
