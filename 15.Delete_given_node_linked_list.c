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

struct Node * deleteGivenNode(struct Node * head,struct Node * ptr){
    struct Node * p = head;
    while(p->next != ptr){
        p = p->next;
    }
    p->next = ptr->next;
    free(ptr);

    return head;
}

int main(){
    struct Node *head, *second, *third, *fourth;

    head = createNode(7);
    second = createNode(23);
    head->next = second;
    third = createNode(12);
    second->next = third;
    fourth = createNode(56);
    third->next = fourth;

    printf("Linked List before deletion : \n");
    linkListTravers(head);
    head = deleteGivenNode(head, third);
    printf("Linked List after deletion of given node : \n");
    linkListTravers(head);

    return 0;
}
