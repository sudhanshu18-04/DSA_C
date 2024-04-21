#include<stdio.h>
#include<stdlib.h>
#define max_nodes 50

typedef struct graph
{
    int n;
    int adj_mat[max_nodes][max_nodes];
}graph;

void create_graph(graph*adj_mat)
{
    int i,j;
    for(int i=0; i< adj_mat->n; i++)
    {
        for(j=0; j < adj_mat->n; j++)
        {
            adj_mat->adj_mat[i][j]=0;
        }
    }
    while(1)
    {
        printf("enter the source and the destination vertices");
        scanf("%d %d",&i,&j);
        if(i<0 && j<0 || i>=adj_mat->n || j>=adj_mat->n)
        break;
        adj_mat->adj_mat[i][j] = 1;
    }
}

int in_degree(graph*adj_mat,int v)
{
    int count =0;
    for(int i = 0; i<adj_mat->n; ++i)
    {
        if(adj_mat->adj_mat[i][v]==1)
        {
            ++count;
        }        
    }
    return count;
}

int out_degree(graph*adj_mat,int v)
{
    int count =0;
    for(int j = 0; j<adj_mat->n; ++j)
    {
        if(adj_mat->adj_mat[v][j]==1)
        {
            ++count;
        }        
    }
    return count;
}

void print_matrix(graph*adj_mat)
{
    for(int i=0;i<adj_mat->n;++i)
    {
        for(int j=0; j<adj_mat->n;++j)
        {
            printf("%d ",adj_mat->adj_mat[i][j]);
        }
        printf("\n");
    }
}
int main() {

    graph adj_mat;

    int ch, v, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &adj_mat.n);

    create_graph(&adj_mat);


    do {

        printf("\n\nMAIN MENU\n");
        printf("1. Indegree of a vertex\n");
        printf("2. Outdegree of a vertex\n");
        printf("3. Display matrix\n");
        printf("4. Exit\n");

        scanf("%d", &ch);

        
        switch (ch) {
            case 1: {
                printf("Enter the vertex: ");
                scanf("%d", &v);
                i = indegree(&adj_mat, v);
                printf("\nIndegree of %d is %d\n", v, i);
                break;
            }
            case 2: {
                printf("Enter the vertex: ");
                scanf("%d", &v);
                i = outdegree(&adj_mat, v);
                printf("\nOutdegree of %d is %d\n", v, i);
                break;
            }
            case 3: {
                print_matrix(&adj_mat);
                break;
            }
            case 4: {
                return 0;
            }
        }


    } while (1);

    return 0;
}
