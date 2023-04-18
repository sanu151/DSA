#include<stdio.h>

void display(int arr[], int n)
{
    // Traversal
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int indexInsertion(int arr[], int arrsize, int element, int index, int cap)
{
    if(arrsize >= cap)
        return -1;

    for(int i = arrsize; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int indexDeletion(int arr[], int arrsize, int index)
{
    if(arrsize < 0 || index > arrsize)
        return -1;

    for(int i = index; i < arrsize; i++)
    {
        arr[i] = arr[i+1];
    }
    return 1;
}

int main()
{
    int arr[100] = {2, 5, 4, 98};
    int arrsize = 4, element = 34, index = 3, cap = 100, result;
    printf("Array before insertion : ");
    display(arr, arrsize);
    result = indexInsertion(arr, arrsize, element, index, cap);
    if(result == -1)
    {
        printf("Array index Out of range");
    }
    else
    {
        arrsize += 1;
        printf("Array after insertion : ");
        display(arr, arrsize);
    }
    index = 2;
    result = indexDeletion(arr, arrsize, index);
    if(result == -1)
    {
        printf("Error! Deletion not possible");
    }
    else
    {
        arrsize -= 1;
        printf("Array after deletion : ");
        display(arr, arrsize);
    }
}
