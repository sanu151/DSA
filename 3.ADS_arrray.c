#include<stdio.h>
#include<stdlib.h>

typedef struct myArray
{
    int total_storage;
    int used_storage;
    int *ptr;
};

int createArray(struct myArray *a, int tSpace, int uSpace)
{
    a->total_storage = tSpace;
    a->used_storage = uSpace;
    a->ptr = (int *)malloc(tSpace * sizeof(int));
}

int setVal(struct myArray *a)
{
    for(int i = 0; i < a->used_storage; i++)
    {
        int n;
        printf("Enter element %d :", i);
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

void show(struct myArray *a)
{
    for(int i = 0; i<a->used_storage; i++)
        printf("%d ", (a->ptr)[i]);
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 4);
    setVal(&marks);
    show(&marks);

    return 0;
}
