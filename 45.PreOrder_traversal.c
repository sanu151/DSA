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
    Node * new_node = (Node * )malloc(sizeof(Node)); // Dynamic memory allocation for new node
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Pre Order Traversal [ root -> left  -> right ]
void preOrder(Node * root){
    if(root != NULL){
        printf("%d ", root->data);  // Print root node data
        preOrder(root->left);       // recursive call for travers left sub tree of root
        preOrder(root->right);      // recursive call for travers right sub tree of root
    }
}

int main(){                     //  Binary Tree :
    Node * p = createNode(7);  //                  7
    Node * p1 = createNode(3); //                 / \                      .
    Node * p2 = createNode(6); //                3   6
    Node * p3 = createNode(2); //               / \  /
    Node * p4 = createNode(1); //              2  1  8
    Node * p5 = createNode(8); //             / \                            .
    Node * p6 = createNode(11); //           11  9
    Node * p7 = createNode(9);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p3->left = p6;
    p3->right = p7;


    preOrder(p);

    return 0;
}
