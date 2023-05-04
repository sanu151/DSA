#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node; // Declaring Node as a Structure data

//Initialise Node
struct Node
{
    int data;
    Node * left;
    Node * right;
    int height;
};

//Create new node
Node * createNode(int data)
{
    Node * new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;

    return new_node;
}

// In Order traversal tree [ left   root    right ]
void inOrderTraversal(Node * root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function returns Max value
int max(int a, int b)
{
    return (a > b) ? a:b; // Ternary operation
}

// Function for Node hight
int getHeight(Node * n)
{
    if(n == NULL)
        return 0;
    return n->height;
}

// Balance Factor for the Sub Tree
int getBalanceFactor(Node * n)
{
    if(n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Function for Left Rotation
Node * leftRotation(Node * x){
    Node * y = x->right;
    Node * t1 = y->left;

    y->left = x;
    x->right = t1;

    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    y->height = max(getHeight(y->left), getHeight(y->right))+1;

    return y;
}

// Function for Right Rotation
Node * rightRotation(Node * y){
    Node * x = y->left;
    Node * t1 = x->right;

    x->right = y;
    y->left = t1;


    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    y->height = max(getHeight(y->left), getHeight(y->right))+1;

    return x;
}

// Function for insert a new node in correct place in AVL tree and Balance the tree
Node * insertNode(Node * n, int data)
{
    if(n == NULL)
        return createNode(data);
    if(data < n->data)
    {
        n->left = insertNode(n->left, data);
    }
    else if(data > n->data)
    {
        n->right = insertNode(n->right, data);
    }
    else
    {
        printf("%d is a Duplicate Value!\n\n", data);
    }

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));

    int bf = getBalanceFactor(n); // bf = Balance Factor for Sub Tree

    // Rotation for balancing the tree
    // left-left case
    if(bf > 1 && data < n->left->data){
        return rightRotation(n);
    }
    //right-right case
    if(bf < -1 && data > n->right->data){
        return leftRotation(n);
    }
    //left-right case
    if(bf > 1 && data > n->left->data){
        n->left = leftRotation(n->left);
        return rightRotation(n);
    }
    //right-left case
    if(bf < -1 && data < n->right->data){
        n->right = rightRotation(n->right);
        return leftRotation(n);
    }
    return n;
}

int main()
{
    Node * root = NULL;
    root = insertNode(root, 7);
    root = insertNode(root, 5);
    root = insertNode(root, 13);
    root = insertNode(root, 2);
    root = insertNode(root, 22);
    root = insertNode(root, 6);
    root = insertNode(root, 15);
    root = insertNode(root, 22);
    root = insertNode(root, 10);

    inOrderTraversal(root);
    printf("\n");



    return 0;
}
