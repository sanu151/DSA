#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int stackSize;
    int top;
    int *arr;
}stack;

int isEmpty(stack *ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

int isFull(stack *ptr){
    if(ptr->top == ptr->stackSize - 1)
        return 1;
    return 0;
}

void push(stack *ptr, int data){
    if(isFull(ptr))
        printf("Stack Overflow! Can't push %d in stack\n", data);
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(stack *ptr){
    if(isEmpty(ptr))
        return -1;
    int popelement = ptr->arr[ptr->top];
    ptr->top--;
    return popelement;
}

int stackTop(stack *ptr){
    if(isEmpty(ptr))
        return -1;
    return (ptr->arr[ptr->top]);
}

int stackBottom(stack *ptr){
    if(isEmpty(ptr))
        return -1;
    return (ptr->arr[0]);
}

int main(){
    stack * s = (stack *)malloc(sizeof(stack));
    s->stackSize = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->stackSize * sizeof(int));

    push(s, 12);
    push(s, 2);
    push(s, 53);
    push(s, 34);
    push(s, 98);
    pop(s);


    printf("Stack Top element is : %d\n", stackTop(s));
    printf("Stack Bottom element is : %d\n", stackBottom(s));

    return 0;
}
