#include<stdio.h>

void printArray(int *A, int n){
    for(int i=0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, low, mid, high){
    int i, j, k;
    int B[high-low+1];
    int i = low, j = mid+1, high = low,

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
    while(i<mid){
        B[k] = A[i];
        i++;
        j++;
    }
    while(j<high){
        B[k] = A[j];
        j++;
        K++;
    }
    for(i=0; i<=high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int *A)
