#include<stdio.h>

// Printing the Array
void printArray(int *A, int n){
    for(int i=0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

//Selection Sort Function
void selectionSort(int *A, int n){
    int minIndex, temp;
    for(int i=0; i < n-1; i++){ // Loop for Passes
        minIndex = i;
        for(int j=i+1; j < n; j++){ // Loop for each pass
            if(A[j] < A[minIndex])
                minIndex = j;
        }
        //Swap smallest element with pass element
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main(){
    int A[] = {5, 3, 7, 12, 4};
    int n = sizeof(A)/sizeof(int); // Length of Array
    printf("\nPrint Array before sort : ");
    printArray(A, n);
    selectionSort(A, n);
    printf("\nPrint Array after sort  : ");
    printArray(A, n);

    return 0;
}
