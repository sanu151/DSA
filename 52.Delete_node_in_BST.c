#include<stdio.h>
#include<stdlib.h>

// Node structure for BST
typedef struct
{
    int data;
    struct Node * left;
    struct Node * right;
} Node;

// Creating a New Node
Node * createNode(int data)
{
    Node * new_node = (Node * )malloc(sizeof(Node));    // Memory allocation for new node
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// In Order traversal [ left -> root -> right ]
void inOrder(Node * root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// For In order Predecessor found
Node * inOrderPredecssor(Node *root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// Insert Node in BST
Node * deleteNode(Node * root, int key)
{
    Node * ipre;
    if(root == NULL)
        return NULL;

    // Searching for the node to be deleted
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;

    }
    if(key < root->data)
    {
        root->left = deleteNode(root->left , key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    // deleting strategy when the node is found
    else
    {
        ipre = inOrderPredecssor(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left, ipre->data);
    }
    return root;
}

int main()
{
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

    inOrder(p);
    printf("\n");
    deleteNode(p, 12);
    printf("\n");
    inOrder(p);

    return 0;
}
