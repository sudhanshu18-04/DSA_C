#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} NODE;

typedef struct queue
{
    NODE *front;
    NODE *rear;
} queue;

NODE *createnode(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
queue *createqueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}
int isEmpty(queue *q)
{
    return (q->front == NULL); // only if the queue is empty the front will be NULL otherwise it wont be null
}
void enqueue(queue *q, int data)
{
    NODE *newnode = createnode(data);
    if (isEmpty(q))
    {
        q->front = q->rear = newnode;
        newnode->next = newnode;
    }
    else
    {
        q->rear->next = newnode; // q->rear means the last node before insertion --> q->rear->next link the previously last node to newnode
        newnode->next = q->front;
        q->rear = newnode;
    }
}
void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("queue is already empty so cant perform dequeue operation");
    }
    else if (q->front == q->rear)
    { // if the queue only contains one element
        NODE *temp = q->front;
        q->front = q->rear = NULL;
        printf("The dequeued data is : %d ", temp->data);
        free(temp);
    }

    else
    {
        NODE *temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        printf("The dequeued data is %d\n", temp->data);
        free(temp);
    }
}
void display(queue *q)
{
    if (isEmpty(q))
        printf("the list is empty :(");
    else
    {
        NODE *temp = q->front;
        printf("%d ", q->front->data);
        temp = temp->next;
        while (temp != q->front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n"); // Add a newline character after printing all elements
}

int main()
{
    struct queue *Myqueue = createqueue();
    int choice, data;
    while (1)
    {
        printf("\nQueue Operations\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.EXIT\n");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the element to be enqueued ");
            scanf("%d", &data);
            enqueue(Myqueue, data);
            break;
        case 2:
            dequeue(Myqueue);
            break;
        case 3:
            display(Myqueue);
            break;
        case 4:
            printf("\n THANK YOU. EXITING..\n");
            break;
        default:
            printf("\n Invalid choice. Please try again! \n");
            break;
        }
    }
}
