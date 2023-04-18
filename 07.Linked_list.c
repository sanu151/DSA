#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node * next;
};

void linkListTraversal(struct Node *ptr)
{
    int count = 1;
    while(ptr != NULL)
    {
        printf("Element %d : %d\n", count, ptr->data);
        ptr = ptr->next;
        count += 1;
    }
}

int main()
{
    struct Node *head, *second, *third, *fourth;

    // Allocate memory for nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link head node with second node
    head->data = 7;
    head->next = second;

    // Link second node with third node
    second->data = 13;
    second->next = third;

    // Link third node with fourth node
    third->data = 22;
    third->next = fourth;

    // Terminate list with fourth node
    fourth->data = 66;
    fourth->next = NULL;

    linkListTraversal(head);

    return 0;
}
