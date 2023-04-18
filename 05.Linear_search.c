#include<stdio.h>

int linearSearch(int arr[], int arrsize, int element)
{
    for(int i = 0; i<arrsize; i++)
    {
        if(arr[i]==element)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {4, 265, 745, 2, 534, 234, 63, 1, 6, 33, 64, 74, 132, 899, 13454};
    int arrsize = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter element : ");
    scanf("%d", &element);
    int result = linearSearch(arr, arrsize, element);
    if(result == -1)
        printf("\n%d element not found in this array!", element);
    else
        printf("\n%d element is found in index no %d", element, result);

    return 0;
}
