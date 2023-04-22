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
    if(isFull(ptr)){
        printf("Stack Overflow !\n");
    }
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

int match(char a, char b){
    if(a == '(' && b == ')')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '[' && b == ']')
        return 1;

    return 0;
}

int parenthesisMatch(char *exp){
    stack * sp = (stack *)malloc(sizeof(stack));
    sp->stackSize = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->stackSize * sizeof(char));

    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
                push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp))
                return 0;
            char popch = pop(sp);
            if(!match(popch, exp[i]))
                return 0;
        }
    }
    if(isEmpty(sp))
        return 1;
    return 0;
}

int main(){
    char * exp = "[{()()}{()[]}]";

    if(parenthesisMatch(exp))
        printf("Parenthesis are Balanced\n");
    else
        printf("Parenthesis are Not Balanced\n");

    return 0;
}
