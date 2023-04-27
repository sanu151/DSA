#include<stdio.h>

void printArray(int *A, int n){
    for(int i=0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, int low, int mid, int high){
    int i, j, k;
    int B[100];
    i = low, j = mid+1, k = low;

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
    while(i<=mid){
        B[k] = A[i];
        i++;
        j++;
    }
    while(j<=high){
        B[k] = A[j];
        j++;
        k++;
    }
    for(i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int *A, int low, int high){
    int mid;
    
    if(low < high){
        mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main(){
    int arr[] = {7, 9, 3, 6, 1, 4, 2, 5, 8};
    int n = sizeof(arr)/sizeof(int);
    printf("Array before sort : ");
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printf("Array after sort  : ");
    printArray(arr, n);
    
    return 0;
}
