#include<stdio.h>
#include<malloc.h>

// Node structure for BST
typedef struct{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

// Creating a New Node
Node * createNode(int data){
    Node * new_node = (Node * )malloc(sizeof(Node));    // Memory allocation for new node
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// In Order traversal [ left -> root -> right ]
void inOrder(Node * root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Insert Node in BST
void insertNode(Node * root, int key){
    Node * prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            printf("%d is already in BST", key);
            return;
        }
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    Node * n = createNode(key);
    if(key < prev->data){
        prev->left = n;
        printf("%d inserted as left child of %d\n", key, prev->data);
    }
    else{
        prev->right = n;
        printf("%d inserted as right child of %d\n", key, prev->data);
    }
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

    insertNode(p, 5);
    printf("\n");
    inOrder(p);

    return 0;
}
