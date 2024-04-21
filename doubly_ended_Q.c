#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Deque
{
    int *arr;
    int front;
    int rear;
    int capacity;
} Deque;

Deque *createDeque(int size)
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->arr = (int *)malloc(sizeof(int) * size);
    deque->front = -1;
    deque->rear = -1;
    deque->capacity = size;
    return deque;
}

int isFull(Deque *deque)
{
    return ((deque->rear + 1) % deque->capacity == deque->front);
}

int isEmpty(Deque *deque)
{
    return (deque->front == -1);
}

void enqueueFront(Deque *deque, int data)
{
    if (isFull(deque))
    {
        printf("Deque is full, cannot enqueue.\n");
        return;
    }

    if (isEmpty(deque))
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else
    {
        deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    }

    deque->arr[deque->front] = data;
}

void enqueueRear(Deque *deque, int data)
{
    if (isFull(deque))
    {
        printf("Deque is full, cannot enqueue.\n");
        return;
    }

    if (isEmpty(deque))
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else
    {
        deque->rear = (deque->rear + 1) % deque->capacity;
    }

    deque->arr[deque->rear] = data;
}

int dequeueFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty, cannot dequeue.\n");
        return -1;
    }

    int data = deque->arr[deque->front];

    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else
    {
        deque->front = (deque->front + 1) % deque->capacity;
    }

    return data;
}

int dequeueRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty, cannot dequeue.\n");
        return -1;
    }

    int data = deque->arr[deque->rear];

    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else
    {
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    }

    return data;
}

void display(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = deque->front;
    while (i != deque->rear)
    {
        printf("%d ", deque->arr[i]);
        i = (i + 1) % deque->capacity;
    }
    printf("%d\n", deque->arr[deque->rear]);
}

int main()
{
    Deque *deque = createDeque(MAX_SIZE);

    enqueueRear(deque, 10);
    enqueueFront(deque, 5);
    enqueueRear(deque, 20);

    display(deque);

    printf("Dequeue front: %d\n", dequeueFront(deque));
    printf("Dequeue rear: %d\n", dequeueRear(deque));

    display(deque);

    free(deque->arr);
    free(deque);

    return 0;
}
