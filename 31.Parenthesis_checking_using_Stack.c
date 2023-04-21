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

void push(stack * ptr, char value){
    if(isFull(ptr))
        printf("Stack Full!");
    ptr->top++;
    ptr->arr[ptr->top] = value;
}

char pop(stack * ptr){
    if(isEmpty(ptr))
        return -1;
    char val = ptr->arr[ptr->top];
    ptr->top--;

    return val;
}

int paranthesisCheck(char *exp){
    stack * sp = (stack *)malloc(sp->stackSize * sizeof(stack));
    sp->stackSize = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char));
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push(sp, '(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp))
                return 0;
            pop(sp);
        }
    }
    if(isEmpty(sp))
        return 1;
    return 0;
}

int main(){
    char * exp = "8*(9)";
    if(paranthesisCheck(exp))
        printf("All Parenthesis are Matched \n");
    else
        printf("Parenthesis are Not Matched \n");

    return 0;
}
