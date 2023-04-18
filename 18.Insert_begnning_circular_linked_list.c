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

void clltraversal(struct Node * head){
    int count = 0;
    struct Node * ptr = head;

    do{
        printf("Element %d : %d\t%x\n", count, ptr->data, ptr->next);
        ptr = ptr->next;
        count++;
    }while(ptr != head);
    printf("\n");
}

struct Node * insertFirst(struct Node * head, int data){
    struct Node * ptr = createNode(data);
    struct Node * p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

int main(){
    struct Node *head, *second, *third, *fourth, *fifth;

    head = createNode(4);
    second = createNode(8);
    head->next = second;
    third = createNode(11);
    second->next = third;
    fourth = createNode(5);
    third->next = fourth;
    fifth = createNode(9);
    fourth->next = fifth;
    fifth->next = head;

    printf("Travers Circular Linked List before Insertion : \n");
    clltraversal(head);
    int value1 = 23, value2 = 49;
    printf("Travers List after insert %d in begnning : \n", value1);
    head = insertFirst(head, value1);
    clltraversal(head);
    printf("Travers List after insert %d in begnning : \n", value2);
    head = insertFirst(head, value2);
    clltraversal(head);

    return 0;
}
