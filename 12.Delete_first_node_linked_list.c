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

struct Node * deleteFristNode(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

int main(){
    struct Node * head, *second, *third, *fourth;

    head = createNode(6);
    second = createNode(23);
    head->next = second;
    third = createNode(12);
    second->next = third;
    fourth = createNode(75);
    third->next = fourth;

    printf("Linked List before deletion : \n");
    linkListTravers(head);

    printf("Linked List after deletion First Node : \n");
    head = deleteFristNode(head);
    linkListTravers(head);

    return 0;
}
