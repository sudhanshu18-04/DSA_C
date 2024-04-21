#include <stdio.h>
#define MAX_NODES 20
typedef struct graph
{
    int vertex;
    int matrix[MAX_NODES][MAX_NODES];
} GRAPH;
int f = -1, r = -1;
void create_graph(GRAPH *g)
{
    int from, to;
    printf("\nEnter the no. of vertex:");
    scanf("%d", &g->vertex);
    for (int i = 1; i <= g->vertex; i++) // initialize matrix to zero
    {
        for (int j = 1; j <= g->vertex; j++)
            g->matrix[i][j] = 0;
    }
    while (1)
    {
        printf("\n Enter the edge (v1 v2):");
        scanf("%d %d", &from, &to);
        if (from > 0 && from <= g->vertex && to > 0 && to <= g->vertex && from != to)
            g->matrix[from][to] = 1; // directed graph
        // g->matrix[to][from]=1;//undirected graph
        else
            return;
    }
}
void display(GRAPH *g)
{
    for (int i = 1; i <= g->vertex; i++)
    {
        printf("\n");
        for (int j = 1; j <= g->vertex; j++)
            printf("%d ", g->matrix[i][j]);
    }
}
void indegree(GRAPH *g, int v)
{
    int count = 0;
    for (int i = 1; i <= g->vertex; i++)
    {
        if (g->matrix[i][v] == 1)
            count++;
    }
    printf("\n The Indegree of the vertex %d is %d", v, count);
}
void outdegree(GRAPH *g, int v)
{
    int count = 0;
    for (int i = 1; i <= g->vertex; i++)
    {
        if (g->matrix[v][i] == 1)
            count++;
    }
    printf("\n The Outdegree of the vertex %d is %d", v, count);
}
void init_visited(int *visited, int v)
{
    for (int i = 0; i <= v; i++)
        visited[i] = 0;
}
void dfs(GRAPH *g, int v, int *visited)
{
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 1; i <= g->vertex; i++)
    {
        if (g->matrix[v][i] == 1 && visited[i] == 0)
            dfs(g, i, visited);
    }
}
int isempty(int *q)
{
    return (f == r && f == -1);
}
void enqueue(int *q, int data)
{
    if (f == r && f == -1) // empty
        f++;
    q[++r] = data;
}
int dequeue(int *q)
{
    int d;
    if (f == r && f != -1)
    {
        d = q[f];
        r = f = -1;
        return d;
    }
    return q[f++];
}
void bfs(GRAPH *g)
{
    int start, *Queue, *Visited, v, i, j;
    printf("\nEnter the source vertex:");
    scanf("%d", &start);
    v = g->vertex;
    Queue = (int *)calloc(v, sizeof(int));
    Visited = (int *)calloc(v + 1, sizeof(int));
    // Traverse
    enqueue(Queue, start);
    Visited[start] = 1;
    printf("%d ", start);
    while (!isempty(Queue))
    {
        i = dequeue(Queue);
        for (j = 1; j <= v; j++)
        {
            if (g->matrix[i][j] == 1 && Visited[j] == 0) // if there exist a edge and is it visited
            {
                enqueue(Queue, j);
                Visited[j] = 1;
                printf("%d ", j);
            }
        }
    }
}
int main()
{
    int ch, v;
    GRAPH g1;
    create_graph(&g1);
    while (1)
    {
        printf("\nEnter your choice:");
        printf("\n1.Display");
        printf("\n2.Indegree of the node");
        printf("\n3.Outdegree of the node");
        printf("\n4.BFS");
        printf("\n5v.Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(&g1);
            break;
        case 2:
            printf("\nEnter the vertex");
            scanf("%d", &v);
            indegree(&g1, v);
            break;
        case 3:
            printf("\nEnter the vertex");
            scanf("%d", &v);
            outdegree(&g1, v);
            break;
        case 4:
            bfs(&g1);
            break;
        case 5:
            return;
        }
    }
}
