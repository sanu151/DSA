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
        printf("Element %d : %d \t %d \n", count, ptr->data, ptr->next);
        ptr = ptr->next;
        count++;
    }while(ptr != head);
    printf("\n");
}

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    head = ptr->next;

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
    printf("Travers List after deletion of first node : \n");
    head = deleteFirst(head);
    clltraversal(head);

    return 0;
}
