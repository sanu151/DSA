#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkListTravers(struct Node *ptr){
    int count = 1;
    while(ptr != NULL){
        printf("element %d : %d\n", count, ptr->data);
        ptr = ptr->next;
        count += 1;
    }
    printf("\n");
}

struct Node * insertHead(struct Node *head, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

int main(){
    struct Node *head, *first, *second, *third, *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 12;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 24;
    third->next = fourth;

    fourth->data = 27;
    fourth->next = NULL;

    printf("Travers Link List : \n");
    linkListTravers(head);

    int new_data = 45;
    printf("Insertion at beginning (new data = %d) : \n", new_data);
    head = insertHead(head, new_data);
    linkListTravers(head);

    return 0;
}
