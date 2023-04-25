#include<stdio.h>

// Printing the Array
void printArray(int *A, int n){
    for(int i=0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Insertion Sort function
void insertionSort(int *A, int n){
    for(int i=1; i < n; i++){ // Loop for passes
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){ // Loop for each pass
            A[j+1] = A[j]; // Shift large element in next index
            j--;
        }
        A[j+1] = key; // Insert pass element in correct position
    }
}

int main(){
    int A[] = {12, 54, 65, 7, 23, 9, 1, 123, 26, 4, 77, 345, 39};
    int n = sizeof(A)/sizeof(int); // Length of Array
    printf("\nArray before sort :  ");
    printArray(A, n);
    insertionSort(A, n);
    printf("\nArray after Sort  :  ");
    printArray(A, n);

    return 0;
}
