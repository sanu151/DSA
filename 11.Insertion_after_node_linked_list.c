#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * createNode(int data){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void linkListTravers(struct Node *head){
    int count = 0;
    while(head != NULL){
        printf("Element %d : %d\n", count, head->data);
        head = head->next;
        count++;
    }
    printf("\n");
}

struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * new_node = createNode(data);

    new_node->next = prevNode->next;
    prevNode->next = new_node;

    return head;
}

int main(){
    struct Node *head, *second, *third, *fourth;

    head = createNode(7);

    second = createNode(21);
    head->next = second;

    third = createNode(15);
    second->next = third;

    fourth = createNode(39);
    third->next = fourth;

    printf("Before insertion : \n");
    linkListTravers(head);

    int newData = 92;
    head = insertAfterNode(head, third, newData);
    printf("After insertion (insert %d after third node) : \n", newData);
    linkListTravers(head);
}
