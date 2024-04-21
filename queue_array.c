	#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct queue{
    int arr[MAX];
    int front;
    int rear;
};
typedef struct queue queue;

void init(queue*q)
{
    q->front=-1;
    q->rear = -1;
}

int isEmpty(queue*q)
{
    return(q->front==-1 && q->rear==-1);
}

int isFull(queue*q)
{
    return(q->rear == MAX-1 && q->front == 0);
}

void enqueue(queue*q,int data)

{
    if(isFull(q))
    {
        printf("queue is already full");
    }
    else if(isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear += 1;
    }    
    q->arr[q->rear] = data;
}

void peek(queue*q)
{
    if(q->front==-1)
    {
        printf("the queue is empty");
    }
    else
    {
        int x = q->arr[q->front];
        printf("The element at the top is : %d",x);
    }
}

void dequeue(queue*q)
{
    if(q->front==-1)
    {
        printf("The queue is empty");
    }
    else if(q->front==q->rear && q->front==0)
    {
        int x = q->arr[q->front];
        q->front = q->rear = -1;
        printf("The dequeued element is : %d",x);
    }
    else
    {
        int x = q->front;
        q->front++;
        printf("the dequeued element is : %d",x);
    }
}

void display(queue*q)
{
    if(q->front==-1)
    {
        printf("The queue is empty");
    }
    else
    {
        int temp = q->front;
        while(temp<=q->rear)
        {
            printf("%d ",q->arr[temp]);
            temp++;
        }
        printf("\n");
    }
}

void main()
{
    int x,choice,data;
    queue q1;
    init(&q1);
    do
    {
        printf("\n Enter 1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n Enter element to be enqueued: ");
                    scanf("%d",&data);
                    enqueue(&q1,data);
                    break;
            case 2: dequeue(&q1);
                    break;
            case 3: peek(&q1);
                    break;
            case 4: display(&q1);
                    break;
            case 5: printf("\n THANK YOU. EXITING.. \n");
                    break;
            default:printf("\n Invalid choice. Please try again! \n");
                    break;
        }
    } while(choice!=5);
}
