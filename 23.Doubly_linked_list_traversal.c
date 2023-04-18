// Travers Doubly Linked List from Beginning to End and End to Beginning.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};

struct Node * createNode(int data){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void dlltraversal(struct Node * head){
    int count = 0;
    printf("Travers List from Beginning : \n");
    struct Node * ptr = head;
    while(ptr != NULL){
        printf("Element %d : %x\t%d\t%x\n", count, ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
        if(ptr != NULL)
            head = ptr;
        count++;
    }
    printf("\n");


    printf("Travers List from End : \n");
    while(head != NULL){
        count--;
        printf("Element %d : %x\t%d\t%x\n", count, head->prev, head->data, head->next);
        head = head->prev;
    }
    printf("\n");
}

int main(){
    struct Node *head, *second, *third, *fourth, *fifth;

    head = createNode(4);
    second = createNode(8);
    head->next = second;
    second->prev = head;
    third = createNode(11);
    second->next = third;
    third->prev = second;
    fourth = createNode(5);
    third->next = fourth;
    fourth->prev = third;
    fifth = createNode(9);
    fourth->next = fifth;
    fifth->prev = fourth;

    dlltraversal(head);
}
