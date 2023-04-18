#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};


void linkListTravers(struct Node *head){
    int count = 0;
    while(head != NULL){
        printf("Element %d : %d\n", count, head->data);
        head = head->next;
        count++;
    }
    printf("\n");
}

struct Node * insertionBetween(struct Node *head, int data, int index){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head;
    int i = 0;
    while(i < (index-1)){
        ptr = ptr->next;
        i++;
    }
    new_node->data = data;
    new_node->next = ptr->next;
    ptr->next = new_node;

    return head;
}

int main(){
    struct Node *head, *second, *third, *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 57;
    fourth->next = NULL;

    linkListTravers(head);
    int new_data = 11, index = 2;
    printf("Insert %d in index %d\n", new_data, index);
    head = insertionBetween(head, new_data, index);
    linkListTravers(head);

    return 0;
}
