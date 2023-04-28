#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Printing Array
void printArray(int *A, int n){
    for(int i=0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Finding max number in given array
int max_number(int A[], int n){
    int maxNum = INT_MIN;

    for(int i=0; i < n; i++){
        if(maxNum < A[i])
            maxNum = A[i];
    }
    return maxNum;
}

void countSort(int *A, int n){
    int max = max_number(A, n);
    int i, j;

    int * count = (int *)malloc((max+1) * sizeof(int)); // Dynamic allocation of memory for count array

    // initialize all element in count memory to 0
    /*for(i=0; i <= max+1; i++){
        count[i] =0;
    }*/
     memset(count, 0, (max+1) * sizeof(int));

    //Increment the corresponding index in the count array
    for(i=0; i < n; i++){
        count[A[i]] += 1;
    }

    i = 0; // using index for count array
    j = 0; // using index for given A array
    // Copy index numbers of count array as Value in given array A
    while(i <= max){
        if(count[i] > 0){
            A[j] = i;
            count[i] -= 1;
            j++;
        }
        else
            i++;
    }
}

int main(){
    int arr[] = {6, 3, 1, 4, 9, 2, 5};
    int n = sizeof(arr)/sizeof(int);

    printf("\nArray before sorting : ");
    printArray(arr, n);
    countSort(arr, n);
    printf("\nArray after sorting : ");
    printArray(arr, n);

    return 0;
}
