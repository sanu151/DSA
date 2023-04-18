#include<stdio.h>
#include<stdlib.h>

struct stack{
    int stackSize;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top >= ptr->stackSize-1)
        return 1;
    return 0;
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->stackSize = 6;
    s->top = -1;
    s->arr = (int * )malloc(s->stackSize * sizeof(int));


    if(isEmpty(s))
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");

    if(isFull(s))
        printf("Stack is Full\n");
    else
        printf("Stack is not Full\n");

    free(s->arr);
    free(s);
    return 0;
}
