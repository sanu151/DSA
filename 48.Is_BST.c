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

// In Order Traversal [ Left -> Right -> Root ]
void inOrder(Node * root){
    if(root != NULL){
        inOrder(root->left);      // recursive call for travers left sub tree of root
        printf("%d ", root->data);  // Printing root node
        inOrder(root->right);     // recursive call for travers right sub tree of root
    }
}

// Check the tree is BST or not
int isBST(Node * root){
    static Node * prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)) // Checking the left sub tree is a BST or not
            return 0;
        if(prev != NULL && root->data <= prev->data) // Checking Root of left sub tree is smaller than it's parent node
            return 0;
        prev = root;
        return (isBST(root->right)); // checking the right sub tree is BST or not and return result
    }
    else
        return 1; // if root is null then we consider it as a BST
}

int main(){                     //  Binary Tree :
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

    //Node * p = createNode(NULL);

    inOrder(p);
    printf("\n");
    if(isBST(p))
        printf("\nThis tree is a Binary Search Tree \n");
    else
        printf("\nThis tree is not a Binary Search Tree \n");

    return 0;
}


