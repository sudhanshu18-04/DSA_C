#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node NODE;

struct queue{    //separate structure is created as everytime we call NODE the front and rear pointer will go to waste
    NODE*front;
    NODE*rear; //they should be of type struct node as they are pointing to a node
};
typedef struct queue queue;

NODE*createnode(int data)
{
    NODE*temp;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

queue*createqueue(){
    queue*q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}
int isEmpty(queue*q)
{
    return(q->front==NULL); //only if the queue is empty the front will be NULL otherwise it wont be null
}

void enqueue(queue*q,int data)
{
    NODE*newnode = createnode(data);
    if(isEmpty(q))
    {
        q->front = q->rear = newnode;
    }
    else
    {
        q->rear->next = newnode; //q->rear means the last node before insertion --> q->rear->next link the previously last node to newnode
        q->rear = newnode;
    }
}

void dequeue(queue*q)
{
    if(isEmpty(q)){
        printf("queue is already empty so cant perform dequeue operation");
    }
    else if(q->front==q->rear)
    {
        NODE*temp = q->front;
        q->front = q->rear = NULL;
        printf("The dequeued element is %d",temp->data);
    }
    else
    {
        NODE*temp = q->front;
        q->front = q->front->next;
        printf("the dequeued data is %d\n",temp->data);
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
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n"); // Add a newline character after printing all elements
}

int main()
{
    struct queue*Myqueue = createqueue();
    int choice, data;
    while(1){
        printf("\nQueue Operations\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.EXIT");
        scanf(" %d", &choice);
        switch(choice)
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


        
