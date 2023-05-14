#include<stdio.h>
#define SIZE 5

struct stack
{
    int top;
    int data[SIZE];
};

typedef struct stack STACK;

// Push Operation
void push(STACK * s, int item)
{
    if(s->top == SIZE - 1)
        printf("\nStack Overflow\n");
    else
        s->data[++(s->top)] = item;
}

// Pop Operation
int pop(STACK * s)
{
    if(s->top == -1)
    {
        printf("\nStack Underflow\n");
        return;
    }
    else
        return s->data[(s->top)--];
}

void display(STACK s)
{
    if(s.top == -1)
        printf("\nStack is empty\n");
    else
    {
        printf("\nStack Elemets : \n");
        for(int i= s.top; i >= 0; i--)
        {
            printf("%d\n", s.data[i]);
        }
    }
}

int main()
{
    int ch, item, del;
    STACK s;
    s.top = -1;

    for(;;)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4, Exit");
        printf("\nRead choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            printf("\nEnter element to Push : ");
            scanf("%d", &item);
            push(&s, item);
            break;
        case 2:
            del = pop(&s);
            printf("\nPoPed element : %d", del);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong selection! Try again\n");
        }
    }
    return 0;
}
