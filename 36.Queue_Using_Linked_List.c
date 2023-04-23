#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct queue * next;
}queue;

queue * f = NULL;
queue * r = NULL;

queue * createNode(int data){
    queue * new_node = (queue *)malloc(sizeof(queue));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

isEmpty(){
    if(f == NULL)
        return 1;
    return 0;
}

isFull(){
    queue * n = createNode(0);
    if(n == NULL)
        return 1;
    return 0;
}

void queueTraversal(){
    if(isEmpty())
        printf("\nQueue is Empty\n");
    else{
        int count = 1;
        queue * ptr = f;
        printf("\nQueue Elements : \n__________________________\n");
        while(ptr != NULL){
            printf("Element %d : %d\n", count, ptr->data);
            ptr = ptr->next;
            count++;
        }
        printf("\n");
    }
}

void enqueue(int data){
    queue * n = createNode(data);
    if(isFull())
        printf("\nQueue is Full! Enqueue operation failed\n");
    else{
        if(isEmpty())
            f = r = n;
        else{
            r->next = n;
            r = n;
        }
    }
}

int dequeue(){
    int data = -1;
    queue * ptr = f;
    if(isEmpty())
        printf("\nQueue is Empty ! DeQueue operation failed\n");
    else{
        f = f->next;
        data = ptr->data;
        free(ptr);
    }
    return data;
}

int main(){
    enqueue(23);
    enqueue(4);
    enqueue(12);
    printf("Dequeue Element : %d\n", dequeue());
    printf("Dequeue Element : %d\n", dequeue());
    printf("Dequeue Element : %d\n", dequeue());
    printf("Dequeue Element : %d\n", dequeue());
    enqueue(66);
    queueTraversal();
}
