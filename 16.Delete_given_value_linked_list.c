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

struct Node * deleteGivenValue(struct Node * head,int value){
    struct Node * p = head;
    struct Node * q = p->next;

    if(p->data == value){
        head = q;
        free(p);
        return head;
    }
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;

    }
    if(q->data == value){
        p->next = q->next;
        free(q);
        return head;
    }
    else{
        printf("%d is not present in this list\n", value);
    }
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
    printf("Linked List deletion of given value : \n");
    head = deleteGivenValue(head, 56);
    linkListTravers(head);

    return 0;
}

