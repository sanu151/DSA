#include<stdio.h>

// Printing Array
void printArray(int *A, int n){
    for(int i=0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n"); // New line after printing the array
}

void merge(int *A, int low, int mid, int high){ // Merge and Sort Left and Right part respect of mid in the array
    int i, j, k;
    int B[100]; // Array for storing sorted values
    i = low, j = mid+1, k = low;

    //Sort and marge passes
    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    // Remaining elements add in B array from A array
    while(i<=mid){ // For Left Side of the array A
        B[k] = A[i];
        i++;
        k++;
    }
    while(j<=high){ // For Right Side of the array A
        B[k] = A[j];
        j++;
        k++;
    }

    // Copying all elements from array B to array A
    for(i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int *A, int low, int high){
    int mid;

    if(low < high){
        mid = (low+high)/2;
        mergeSort(A, low, mid); // Recursive call mergeSort function for Left side array
        mergeSort(A, mid+1, high); // Recursive call mergeSort function for Right side array
        merge(A, low, mid, high); // Marging both the array.
    }
}

int main(){
    int arr[] = {7, 9, 3, 6, 1, 4, 2, 5, 8};
    int n = sizeof(arr)/sizeof(int); // Array size calculating
    printf("Array before sort : ");
    printArray(arr, n);
    mergeSort(arr, 0, n-1); // Low = index 0 and high = index 8 , array Length = 9
    printf("Array after sort  : ");
    printArray(arr, n);

    return 0;
}
