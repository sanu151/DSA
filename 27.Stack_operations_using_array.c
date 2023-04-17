#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int stackSize;
    int top;
    int *arr;
}stack;

void displayStack(stack * ptr){
    printf("\nStack Elements : [");
    for(int i=0; i<=ptr->top; i++){
        printf("%d ", ptr->arr[i]);
    }
    printf("]\n\n");
}

int isEmpty(stack *ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

int isFull(stack *ptr){
    if(ptr->top == ptr->stackSize-1)
        return 1;
    return 0;
}

void push(stack * ptr, int data){
    if(isFull(ptr))
        printf("Stack Overflow !\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}


int pop(stack * ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    else{
        int item = ptr->arr[ptr->top];
        ptr->top--;
        return item;
    }
}

int main(){
    stack * s = (stack *)malloc(sizeof(stack));
    s->stackSize = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->stackSize * sizeof(int));

    int n, element, popElement;
    printf("*** STACK OPERATIONS MENU***\n______________________________\nPush : 1\tPull : 2\nDisplay Stack : 3\tExit : 0\n");
    while(n != 0){
        printf("Enter your choice : ");
        scanf("%d", &n);
        switch(n){
        case 1:
            printf("Enter Element to push : ");
            scanf("%d", &element);
            push(s, element);
            break;
        case 2:
            popElement = pop(s);
            if(popElement == -1)
                printf("Stack is Empty !\n");
            else
                printf("POP element : %d\n", popElement);
            break;
        case 3:
            displayStack(s);
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Wrong Selection! Try again\n");
        }
    }
    return 0;
}
