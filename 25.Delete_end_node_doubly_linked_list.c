#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next, *prev;
};

struct Node * createNode(int data){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void dlltraversal(struct Node * head){
    int count = 0;
    struct Node * ptr = head;

    while(ptr != NULL){
        printf("Element %d : %x \t %d \t %x \n", count, ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
        count++;
    }
    printf("\n");
}

struct Node * deleteEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = p->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
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

    printf("List before insertion : \n");
    dlltraversal(head);
    int value = 23;
    head = deleteEnd(head);
    printf("List after deletion of end node : \n");
    dlltraversal(head);

    return 0;
}
