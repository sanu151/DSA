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

void linkListTravers(struct Node * head){
    int count = 0;
    while(head != NULL){
        printf("Element %d : %d\n", count, head->data);
        head = head->next;
        count++;
    }
    printf("\n");
}

struct Node * insertEnd(struct Node *head, int data){
    struct Node * newNode = createNode(data);
    struct Node * ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;

    return head;
}

int main(){
    struct Node *head, *second, *third, *fourth;

    head = createNode(7);
    second = createNode(25);
    head->next = second;
    third = createNode(12);
    second->next = third;
    fourth = createNode(56);
    third->next = fourth;

    linkListTravers(head);
    int newData = 83;
    printf("Insert %d at end : \n", newData);
    head = insertEnd(head, newData);
    linkListTravers(head);

    return 0;
}
