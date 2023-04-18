#include<stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]==element)
            return mid;
        if(arr[mid]<element)
            low = mid+1;
        if(arr[mid]>element)
            high = mid-1;
    }
    return -1;
}

int main()
{
    int arr[] = {11, 33, 53, 213, 444, 575, 800, 890, 1234, 4563};
    int size = sizeof(arr)/sizeof(int);
    int element, result;
    printf("Enter element : ");
    scanf("%d", &element);
    result = binarySearch(arr, size, element);
    if(result == -1)
        printf("%d not found in this array", element);
    else
        printf("%d found in array index : %d", element, result);

    return 0;
}
