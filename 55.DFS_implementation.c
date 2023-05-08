#include<stdio.h>
#include<stdlib.h>

// Graph Implementation using Adjacent Matrix
int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // All unvisited node marked as 0
// Node Edge implementation
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

// Graph Traversal using Depth First Search (DFS) method
void DFS(int i){
    int j;
    printf("%d ", i);
    visited[i] = 1;
    // Push unvisited node to the Stack by using recursive function
    for(j = 0; j < 7; j++){
        if(A[i][j] == 1 && !visited[j]){ // if the node is connected by a edge and not visited
            DFS(j);
        }
    }
}

int main(){
    DFS(6);

    return 0;
}
