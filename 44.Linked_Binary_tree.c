#include<stdio.h>
#include<malloc.h>

// Node structure
typedef struct{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

// Creating New Node
Node * createNode(int data){
    Node * new_node = (Node *)malloc(sizeof(Node)); // Memory allocation for new node
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int main(){
    Node *p = createNode(2);    // Creating Root Node
    Node *p1 = createNode(1);   // Creating left Child
    Node *p2 = createNode(4);   // Creating right Child
    p->left = p1;               // Linking Root with Left Child
    p->right = p2;              // Linking Root with Right Child

    return 0;
}
