#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int stackSize;
    int top;
    int *arr;
}stack;

void displayStack(stack * ptr){
    printf("\nStack Elements : [ ");
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
        printf("Stack Overflow ! Cann't push %d in the stack.\n", data);
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

int peek(stack * ptr, int pos){
    if((ptr->top - pos + 1) < 0){
        return -1;
    }
    return (ptr->arr[ptr->top - pos + 1]);
}

int main(){
    stack * s = (stack *)malloc(sizeof(stack));
    s->stackSize = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->stackSize * sizeof(int));

    int n = -1, a = -1, pos, element, popElement, peekElement;
    printf("*** STACK OPERATIONS MENU***\n______________________________\nPush : 1\tPull : 2\tPeek Element : 3\nDisplay Stack : 4\tExit : 0\n");
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
            printf("=== MENU OF PICK OPERATION ===\n________________________________\nPeek Element from a position : 1\nPeek all Element : 2\n");
            printf("Enter your choice : ");
            scanf("%d", &a);
            if(a == 1){
                printf("Enter a position : ");
                scanf("%d", &pos);
                peekElement = peek(s, pos);
                if(peekElement == -1)
                    printf("%d is not a valid position to peek element\n", pos);
                else
                    printf("Element in %d position is : %d\n", pos, peekElement);
            }
            else if(a == 2){
                for(int i = 1; i <= s->top+1; i++){
                    printf("Element in %d : %d\n", i, peek(s,i));
                }
                printf("\n");
            }
            else
                printf("\nWrong Selection !\n");
            break;
        case 4:
            displayStack(s);
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Wrong Selection! Try again\n");
        }
    }
    getchar();
    return 0;
}
