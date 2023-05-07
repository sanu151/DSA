#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node{
    int size;
    int f, r;
    int * arr;
};

int isEmpty(Node * A){
    if(A->f == A->r)
        return 1;
    return 0;
}

int isFull(Node * A){
    if(A->r == A->size - 1)
        return 1;
    return 0;
}

void enqueue(Node * A, int data){
    if(isFull(A)){
        printf("Queue is Full ! cannot enqueue %d", data);
        return;
    }
    A->r++;
    A->arr[A->r] = data;
}

int dequeue(Node * A){
    int a = -1;
    if(isEmpty(A)){
        return 0;
    }
    A->f++;
    a = A->arr[A->f];

    return a;
}

int main(){
    // Initializing Queue (Array Implementation)
    Node q;
    q.size = 20;
    q.f = q.r = -1;
    q.arr = (Node * )malloc(q.size * sizeof(int));

     // BFS Implementation
    int visited[7] = {0,0,0,0,0,0,0};
    int node, i = 0;

    int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
    };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while(!isEmpty(&q)){
        node = dequeue(&q);
        for(int j = 0; j < 7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
