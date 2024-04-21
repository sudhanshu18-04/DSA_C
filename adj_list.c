#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct node
{
    int data;
    struct node* link;
}NODE;

int i,n,choice,v;
NODE*a[MAX]; //initializes a list of type structure node and size max

void insert(NODE*a[],int i,int j)
{
    NODE*temp = (NODE*)malloc(sizeof(NODE));
    temp->data = j;
    temp->link = NULL;
    NODE*curr = a[i];
    if(curr==NULL)
    {
        a[i] = temp;
        return;
    }
    while(curr->link!=NULL)
    {
        curr=curr->link;
    }
    curr->link = temp;
}

void create_graph(NODE *a[],int n)
{
    int i,j;
    for(int i =0;i<n;i++)
    a[i]=NULL; //pehle sab kuch null krdo 
    while(1)
    {
        printf("Enter your source and destination : ");
        scanf("%d %d",&i,&j);
        if(i<0||j<0||i>=n||j>=n) //check kro kuch bacwas nahi daala hai nah woh
        break;
        insert(a,i,j);
    }
}

void display(NODE*a[],int n)
{
    for(int i=0;i<n;i++)
    {
        NODE*curr = a[i];
        while(curr!=NULL)
        {
            printf(" %d",curr->data);
            curr = curr->link;
        }
        printf("\n");
    }
}
int indegree(NODE *a[],int n,int v)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		NODE *cur=a[i];
		while(cur!=NULL)
		{
			if(cur->data==v)
			{
				++c;
			}
			cur=cur->link;
		}
	}
	return(c);
}
int outdegree(NODE *a[],int v)
{
	int c=0;
	NODE *cur=a[v];
	while(cur!=NULL)
	{
		
		++c;
		cur=cur->link;
	}
	return(c);
}

int main()
{
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	create_graph(a,n);
	display(a,n);
	printf("Enter the vertex\n");
	scanf("%d",&v);
	int ic=indegree(a,n,v);
	printf("indegree count=%d \n",ic);
	printf("Enter the vertex\n");
	scanf("%d",&v);
	int oc=outdegree(a,v);
	printf("outdegree count=%d \n",oc);

}
