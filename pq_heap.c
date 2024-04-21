// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 50
// typedef struct priority_queue
// {
//     int heap[MAX];
//     int size;
// }PQ;

// void swap(int*a,int*b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void heapify_up(PQ*pq,int i)
// {
//     int parent = (i-1)/2;
//     while(i>0 && pq->heap[i]>pq->heap[parent])
//     {
//         swap(&pq->heap[i],&pq->heap[parent]);
//         i = parent;
//         parent = (i-1)/2;
//     }
// }

// void heapify_down(PQ*pq,int i)
// {
//     int left = 2*i+1;
//     int right = 2*i+2;
//     int largest = i;

//     if(left<pq->size && pq->heap[left]>pq->heap[largest])
//     largest = left;

//     if(right<pq->size && pq->heap[right]>pq->heap[largest])
//     largest = right;

//     if(largest!=i)
//     {
//         swap(&pq->heap[i],&pq->heap[largest]);
//         heapify_down(pq,largest);
//     }
// }

// void insert(PQ*pq,int data)
// {
//     if(pq->size>MAX)
//     {
//         printf("Queue is full");
//         return;
//     }
//     pq->heap[pq->size] = data;
//     pq->size++;
//     heapify_up(pq,pq->size-1);
// }

// void delete(PQ*pq)
// {
//     if(pq->size<=0)
//     {
//         printf("pq is empty");
//         return;
//     }

//     int max = pq->heap[0];
//     pq->heap[0] = pq->heap[pq->size-1];
//     pq->size--;
//     heapify_down(pq,0);
//     return max;
// }

// int main() {
//     PQ pq;
//     pq.size = 0;

//     int choice, item;
//     while (1) {
//         printf("1. Insert\n");
//         printf("2. Delete Max\n");
//         printf("3. Quit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter element to insert: ");
//                 scanf("%d", &item);
//                 insert(&pq, item);
//                 break;
//             case 2:
//                 item = delete_max(&pq);
//                 if (item != -1)
//                     printf("Max element: %d\n", item);
//                 break;
//             case 3:
//                 exit(0);
//             default:
//                 printf("Invalid choice.\n");
//         }
//     }

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct priority_queue
{
    int heap[MAX];
    int size;
}PQ;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(PQ*pq,int i)
{
    int parent = (i-1)/2;
    for(i = 0; i > 0 && pq->heap[i] > pq->heap[parent]; i++)
    {
        swap(&pq->heap[i],&pq->heap[parent]);
        i = parent;
        parent = (i-1)/2;
    }
}

void heapify_down(PQ*pq,int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left<pq->size && pq->heap[left]>pq->heap[largest])
    {
        largest = left;
    }

    if(right<pq->size && pq->heap[right]>pq->heap[largest])
    {
        largest = right;
    }

    if(largest!=i)
    {
        swap(&pq->heap[i],&pq->heap[largest]);
        heapify_down(pq,largest);
    }

}