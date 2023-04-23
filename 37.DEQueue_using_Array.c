#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int queueSize;
    int f, r;
    int * arr;
}de_queue;

int isEmpty(de_queue * dq){
    if(dq->f == -1)
        return 1;
    return 0;
}

int isFull(de_queue * dq){
    if(dq->f == 0 && dq->r == dq->queueSize-1 || dq->f == dq->r + 1)
        return 1;
    return 0;
}

void displayQueue(de_queue * dq){
    if(isEmpty(dq)){
        printf("\nQueue is Empty ! Nothing to Print\n");
    }
    else{
        printf("\n*** Elements in Queue ***\n_____________________________\n");
        if(dq->f <= dq->r){
            for(int i = dq->f; i <= dq->r; i++)
                printf("Element %d : %d\n", i, dq->arr[i]);
        }
        else{
            for(int i = dq->f; i <= dq->queueSize-1; i++)
                printf("Element %d : %d\n", i, dq->arr[i]);
            for(int i = 0; i <= dq->r; i++)
                printf("Element %d : %d\n", i, dq->arr[i]);
        }
    }
    printf("\n");
}

void enqueueFront(de_queue * dq, int data){
    if(isFull(dq)){
        printf("Queue is Full ! No element can add\n");
    }
    else{
        if(isEmpty(dq))
            dq->f = dq->r = 0;
        else if(dq->f == 0)
            dq->f = dq->queueSize-1;
        else
            dq->f--;
        dq->arr[dq->f] = data;
        printf("Element %d added from Front.\n", data);
    }
}

void enqueueRear(de_queue * dq, int data){
    if(isFull(dq)){
        printf("Queue is Full ! No element can add\n");
    }
    else{
        if(isEmpty(dq))
            dq->f = dq->r = 0;
        else if(dq->r == dq->queueSize-1)
            dq->r = 0;
        else
            dq->r++;
        dq->arr[dq->r] = data;
        printf("Element %d added from Rear.\n", data);
    }
}


void dequeueFront(de_queue * dq){
    if(isEmpty(dq))
        printf("Queue is Empty ! No element can remove\n");
    else{
        printf("Element %d removed from Front.\n", dq->arr[dq->f]);
        if(dq->f == dq->r)
            dq->f = dq->r-1;
        else if(dq->f == dq->queueSize-1)
            dq->f = 0;
        else
            dq->f++;
    }
}

void dequeueRear(de_queue * dq){
    if(isEmpty(dq))
        printf("Queue is Empty ! No element can remove\n");
    else{
        printf("Element %d removed from Rear.\n", dq->arr[dq->r]);
        if(dq->f == dq->r)
            dq->r = dq->f+1;
        else if(dq->r == 0)
            dq->r = dq->queueSize-1;
        else
            dq->r--;
    }
}

int getFront(de_queue * dq){
    if(isEmpty(dq)){
        printf("Queue is Empty !");
        return -1;
    }
    return dq->arr[dq->f];
}

int getRear(de_queue * dq){
    if(isEmpty(dq)){
        printf("Queue is Empty !");
        return -1;
    }
    return dq->arr[dq->r];
}

int main(){
    de_queue * dq = (de_queue *)malloc(sizeof(de_queue));
    dq->queueSize = 10;
    dq->f = dq->r = -1;
    dq->arr = (int *)malloc(dq->queueSize * sizeof(int));

    enqueueFront(dq, 31);
    enqueueRear(dq, 22);
    enqueueFront(dq, 56);
    dequeueFront(dq);
    enqueueFront(dq, 77);
    dequeueRear(dq);
    enqueueRear(dq, 38);
    enqueueFront(dq, 68);

    displayQueue(dq);

    printf("Front Element : %d\n", getFront(dq));
    printf("Rear Element : %d\n", getRear(dq));
}
