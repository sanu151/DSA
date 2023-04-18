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

    clltraversal(head);

    return 0;
}
