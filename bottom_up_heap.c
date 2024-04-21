// #include<stdio.h>
// #include<stdlib.h>

// void heapify(int arr[],int n,int i)
// {
//     int largest = i;
//     int left = 2*i+1;
//     int right = 2*i+2;

//     if(left<n&& arr[left]>largest)
//     {
//         largest = left;
//     }

//     else if(right<n && arr[right]>largest)
//     {
//         largest = right;
//     }

//     if(largest!=i)
//     {
//         int temp = arr[i];
//         arr[i] = arr[largest];
//         arr[largest] = temp;
//         heapify(arr,n,largest);
//     }
// }
// void buildHeap(int arr[], int n) {
//     for (int i = (n / 2) - 1; i >= 0; i--) {
//         heapify(arr, n, i);
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
//     int n;

//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int arr[n];

//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     printf("Original array: \n");
//     printArray(arr, n);

//     buildHeap(arr, n);

//     printf("Max heap: \n");
//     printArray(arr, n);

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest])
    {
        largest = left;
    }

    else if(right<n && arr[right]>arr[largest])
    {
        largest = right;
    }

    if(largest!=i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,n,largest);
    }
}

void buildheap(int arr[],int n)
{
    for(int i = (n/2)-1; i>=0 ; i--)
    {
        heapify(arr,n,i);
    }
}