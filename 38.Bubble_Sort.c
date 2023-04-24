#include<stdio.h>

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n){
    int temp;
    for(int i=0; i < n-1; i++){
        int isSorted = 1;
        for(int j=0; j < n-1-i; j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted)
            return;
    }
}

int main(){
    int A[] = {456, 75, 12, 7, 23, 8, 102, 2, 0, 567, 1122, 69, 6, 44};
    int n = sizeof(A)/sizeof(int);

    printf("Print Array Before Sorting : ");
    printArray(A, n);
    bubbleSort(A, n);
    printf("Print Array After Sorting : ");
    printArray(A, n);
}
