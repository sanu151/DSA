#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int stackSize;
    int top;
    char *arr;
}stack;

int isEmpty(stack * ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

int isFull(stack * ptr){
    if(ptr->top == ptr->stackSize-1)
        return 1;
    return 0;
}

void push(stack * ptr, char data){
    if(isFull(ptr))
        printf("Stack Full !\n");
    ptr->top++;
    ptr->arr[ptr->top] = data;
}

char pop(stack * ptr){
    if(isEmpty(ptr))
        return -1;
    char item = ptr->arr[ptr->top];
    ptr->top--;

    return item;
}

char stackTop(stack * ptr){
    return ptr->arr[ptr->top];
}

int presedence(char ch){
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

char * infixToPostfix(char * infix){
    int infixlen = strlen(infix);
    stack * sp = (stack *)malloc(sizeof(stack));
    sp->stackSize = infixlen;
    sp->top = -1;
    sp->arr = (char *)malloc(infixlen * sizeof(char));

    char * postfix = (char *)malloc(infixlen+1 * sizeof(char));

    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(presedence(infix[i]) > presedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main(){
    char * infix = "x-y/z-k*d";
    printf("\nPostfix : %s\n", infixToPostfix(infix));

    return 0;
}
