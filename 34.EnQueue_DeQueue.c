#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int queueSize;
    int f, r;
    int *arr;
}queue;

void displayQueue(queue * q){
    int i;
    if(!isEmpty(q)){
        for(i= q->f+1; i <= q->r; i++){
            printf("Element %d : %d\n", i+1, q->arr[i]);
        }
        printf("\n");
    }
    else
        printf("Queue is Empty\n");

    if(isFull(q))
        printf("\nQueue is Full!\n");

}

int isEmpty(queue * q){
    if(q->f == q->r)
        return 1;
    return 0;
}

int isFull(queue * q){
    if(q->r == q->queueSize -1)
        return 1;
    return 0;
}

void enqueue(queue * q, int data){
    if(isFull(q))
        printf("Queue is Full\n");
    else{
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(queue * q){
    int data;
    if(isEmpty(q))
        return -1;
    q->f++;
    data = q->arr[q->f];

    return data;
}

int main(){
    queue *q = (queue *)malloc(sizeof(queue));
    q->queueSize = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->queueSize * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 3);
    enqueue(q, 8);
    enqueue(q, 5);
    enqueue(q, 9);

    displayQueue(q);

    printf("DeQueue Element : %d\n",dequeue(q));

    displayQueue(q);
}
