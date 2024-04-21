// #include<stdio.h>
// #include<stdlib.h>

// void heapify(int arr[],int i)
// {
//     int parent = (i-1)/2;
//     while(i>0 && arr[i]>arr[parent])
//     {
//         int temp = arr[i];
//         arr[i] = arr[parent];
//         arr[parent] = temp;

//         i = parent;
//         parent = (i-1)/2;
//     }
// }
// void insert(int arr[],int *n,int key)
// {
//     if(*n>100)
//     {
//         printf("The heap is full");
//         return;
//     }

//     arr[*n] = key;
//     (*n)++;
//     heapify(arr,*n-1);
// }

// void printHeap(int arr[], int n) {
//     printf("Max-Heap: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int arr[100];
//     int n = 0;

//     // User input: number of elements to insert
//     printf("Enter the number of elements to insert: ");
//     int num;
//     scanf("%d", &num);

//     // User input: elements to insert
//     printf("Enter %d elements: ", num);
//     for (int i = 0; i < num; i++) {
//         int element;
//         scanf("%d", &element);

//         // Insert the element into the max-heap
//         insert(arr, &n, element);
//     }

//     // Print the max-heap after insertions
//     printf("Heap after insertions:\n");
//     printHeap(arr, n);

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int i)
{
    int parent = (i-1)/2;
    while(i>0 && arr[i]>arr[parent])
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
        parent = (i-1)/2;
    }
}

void insert(int arr[],int *n,int key)
{
    if(*n>100)
    {
        printf("The heap is already full");
    }
    arr[*n] = key;
    (*n)++;
    heapify(arr,*n-1);
}

void printheap(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}