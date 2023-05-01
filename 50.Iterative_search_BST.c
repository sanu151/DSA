#include<stdio.h>
#include<malloc.h>

// Node structure of Binary tree
typedef struct{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

// Creating new node
Node * createNode(int data){
    Node * new_node = (Node * )malloc(sizeof(Node));    // Dynamic memory allocate for Node
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Search key by Iterative Search
Node * searchIter(Node * root, int key){
    while(root != NULL){
        if(root->data == key)
            return root;
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main(){
    Node * p = createNode(7);  //                  7
    Node * p1 = createNode(4); //                 / \                      .
    Node * p2 = createNode(15); //               4   15
    Node * p3 = createNode(2); //               / \  /
    Node * p4 = createNode(6); //              2   6 12
    Node * p5 = createNode(12); //            / \                            .
    Node * p6 = createNode(1); //            1  3
    Node * p7 = createNode(3);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p3->left = p6;
    p3->right = p7;

    Node * n = searchIter(p, 15);
    if(n != NULL)
        printf("\nElement Found : %d \n", n->data);
    else
        printf("\nElement not found !\n");

    return 0;
}
