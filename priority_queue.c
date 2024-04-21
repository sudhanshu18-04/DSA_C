#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the priority queue
typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} NODE;

// Structure for the priority queue
typedef struct PriorityQueue
{
    NODE *front;
} Pqueue;

// Function to create an empty priority queue
Pqueue *createQueue()
{
    Pqueue *queue = (Pqueue *)malloc(sizeof(Pqueue));
    queue->front = NULL;
    return queue;
}

// Function to check if the priority queue is empty
int isEmpty(Pqueue *queue)
{
    return (queue->front == NULL);
}
NODE *createnode(int data, int priority)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}
// Function to insert an element with priority into the priority queue
void enqueue(Pqueue *queue, int data, int priority)
{

    NODE *newnode = createnode(data, priority);
    if (queue->front == NULL)
    {
        queue->front = newnode;
    }
    else if((queue->front!=NULL) && ((priority)>(queue->front->priority)))
    {
        newnode->next=queue->front;
        queue->front=newnode;
    }
    else
    {
        NODE *current = queue->front;
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

// Function to dequeue the element with the highest priority from the priority queue
int dequeue(Pqueue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        NODE *temp = queue->front;
        int ele = temp->data;
        queue->front = queue->front->next;
        free(temp);
        printf("%d", ele);
    }
}

// Function to display the priority queue
void display(Pqueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    NODE *current = queue->front;
    while (current != NULL)
    {
        printf("Data: %d, Priority: %d\n", current->data, current->priority);
        current = current->next;
    }
}
void freeQueue(Pqueue *queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

int main()
{
    Pqueue *queue = createQueue();
    int choice, data, priority;

    while (1)
    {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Free\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(queue, data, priority);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            printf("Priority Queue elements:\n");
            display(queue);
            break;
        case 4:
            freeQueue(queue);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
