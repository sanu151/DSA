#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct stack * next;
}stack;

stack * createNode(int data){
    stack * new_node = (stack *)malloc(sizeof(stack));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void displayStack(stack * top){
    int pos = 1;
    printf("\n***STACK ELEMENTS***\n");
    while(top != NULL){
        printf("Element %d : %d\n", pos, top->data);
        top = top->next;
        pos++;
    }
    printf("\n");
}

int isEmpty(stack * top){
    if(top == NULL)
        return 1;
    return 0;
}

stack * push(stack * top, int data){
    stack * n = createNode(data);
    if(n == NULL)
        printf("Stack Overflow !");
    else{
        n->next = top;
        top = n;
        return top;
    }
}

stack * pop(stack * top){
    if(isEmpty(top)){
        printf("Stack is Empty!");
    }
    else{
        stack * x = top;
        int item = x->data;
        printf("Popped Item : %d", item);
        top = top->next;
        free(x);
    }
    return top;
}

int main(){
    stack * top = NULL;

    top = push(top, 12);
    top = push(top, 2);
    top = push(top, 34);
    displayStack(top);
    top = pop(top);

    displayStack(top);

    return 0;
}
