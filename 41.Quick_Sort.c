#include<stdio.h>

// Printing Array
void printArray(int *A, int n)
{
    for(int i=0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low]; // Element use of partitioning
    int i = low+1, j = high, temp;

    do
    {
        while(A[i] <= pivot) // to find higher number respect of pivot
            i++;
        while(A[j] > pivot) // to find lower number respect of pivot
            j--;
        if(i < j)
        {
            //Swap A[i] and A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    while(i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex;

    if(low < high)
    {
        partitionIndex = partition(A, low, high); // Index of pivot after partitioning
        // Recursive call of quickSort function for left and right sub array of partition
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}

int main()
{
    int A[] = {9, 4, 13, 27, 2, 11, 23, 8, 12, 4, 6, 5};
    int n = sizeof(A)/sizeof(int); // Size of array

    printf("\nArray before sorting : ");
    printArray(A, n);
    quickSort(A, 0, n-1);
    printf("\nArray after implementing Quick sort : ");
    printArray(A, n);
}
