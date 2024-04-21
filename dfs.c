#include <stdio.h>
#define MAX_NODES 10
typedef struct graph
{
    int vertex;
    int visited[MAX_NODES];
    int adj_mat[MAX_NODES][MAX_NODES];
} GRAPH;
void create_graph(GRAPH *g)
{
    int from, to;
    printf("\nEnter the no. of vertex");
    scanf("%d", &g->vertex);
    for (int i = 1; i <= g->vertex; i++)
    {
        for (int j = 1; j <= g->vertex; j++)
            g->adj_mat[i][j] = 0;
    }
    while (1)
    {
        printf("\nEnter the edge (v1 v2):");
        scanf("%d %d", &from, &to);
        if (from > 0 && from <= g->vertex && to > 0 && to <= g->vertex)
            g->adj_mat[from][to] = 1;
        else
            break;
    }
}
void display(GRAPH *g)
{
    for (int i = 1; i <= g->vertex; i++)
    {
        printf("\n");
        for (int j = 1; j <= g->vertex; j++)
            printf("%d ", g->adj_mat[i][j]);
    }
}
void indegree(GRAPH *g, int v)
{
    int count = 0;
    for (int i = 1; i <= g->vertex; i++)
    {
        if (g->adj_mat[i][v] == 1)
            count++;
    }
    printf("\nIndegree of the node %d is %d", v, count);
}
void outdegree(GRAPH *g, int v)
{
    int count = 0;
    for (int i = 1; i <= g->vertex; i++)
    {
        if (g->adj_mat[v][i] == 1)
            count++;
    }
    printf("\nOutdegree of the node %d is %d", v, count);
}
void init_visited(GRAPH *g)
{
    for (int i = 0; i <= g->vertex; i++)
        g->visited[i] = 0;
}
void dfs(GRAPH *g, int start)
{
    printf("%d", start);
    g->visited[start] = 1;
    for (int i = 1; i <= g->vertex; i++)
    {
        if (g->adj_mat[start][i] == 1 && g->visited[i] == 0)
            dfs(g, i);
    }
}
int main()
{
    GRAPH g1;
    int ch, v, start;
    create_graph(&g1);
    while (1)
    {
        printf("\nEnter your choice");
        printf("\n1.Display");
        printf("\n2.Indegree of a node");
        printf("\n3.Outdegree of a node");
        printf("\n4.DFS");
        printf("\n5.Quit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // Display
            display(&g1);
            break;
        case 2: // Indegree of a node
            printf("\nEnter the vertex:");
            scanf("%d", &v);
            indegree(&g1, v);
            break;
        case 3: // Outdegree of a node
            printf("\nEnter the vertex:");
            scanf("%d", &v);
            outdegree(&g1, v);
            break;
        case 4:
            init_visited(&g1);
            printf("\nEnter the source vertex:");
            scanf("%d", &start);
            dfs(&g1, start);
            break;
        case 5: // Quit
            return;
        }
    }
}
