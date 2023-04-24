#include<stdio.h>

void printArray(int *A, int n){
    for(int i=0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    for(int i=1; i < n; i++){
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int A[] = {12, 54, 65, 7, 23, 9, 1, 123, 26, 4, 77, 345, 39};
    int n = sizeof(A)/sizeof(int);
    printf("\nArray before sort :  ");
    printArray(A, n);
    insertionSort(A, n);
    printf("\nArray after Sort  :  ");
    printArray(A, n);

    return 0;
}
