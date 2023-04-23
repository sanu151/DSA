#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int queueSize;
    int f, r;
    int *arr;
}queue;

void displayQueue(queue * q){
    int i = q->f+1;
    if(!isEmpty(q)){
        do{
            printf("Element %d : %d\n", i+1, q->arr[i]);
            i = (i+1)%q->queueSize;
        }while(i != q->r+1);
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
    if(q->r+1 == q->f)
        return 1;
    return 0;
}

void enqueue(queue * q, int data){
    if(isFull(q))
        printf("Queue is Full!\n");
    else{
        q->r = (q->r+1)%q->queueSize;
        q->arr[q->r] = data;
    }
}

int dequeue(queue * q){
    if(isEmpty(q))
        return -1;
    q->f = (q->f+1)%q->queueSize;
    int data = q->arr[q->f];

    return data;
}

int main(){
    queue *q = (queue *)malloc(sizeof(queue));
    q->queueSize = 10;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->queueSize * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 3);
    enqueue(q, 8);
    enqueue(q, 5);
    enqueue(q, 9);
    enqueue(q, 15);
    printf("DeQueue Element : %d\n",dequeue(q));
    printf("DeQueue Element : %d\n",dequeue(q));
    printf("DeQueue Element : %d\n",dequeue(q));
    enqueue(q, 8);
    enqueue(q, 6);
    enqueue(q, 11);
    enqueue(q, 81);
    enqueue(q, 60);
    printf("DeQueue Element : %d\n",dequeue(q));
    enqueue(q, 32);
    enqueue(q, 81);
    printf("DeQueue Element : %d\n",dequeue(q));
    enqueue(q, 55);
    enqueue(q, 61);
    enqueue(q, 65);

    displayQueue(q);

    return 0;
}
