#include<stdio.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

// Push Operation
void push(int data)
{
    if(top == SIZE-1)
        printf("Overflow\n");
    else
    {
        top += 1;
        stack[top] = data;
    }
}

// Pop Operation
void pop()
{
    if(top == -1)
        printf("Underflow\n");
    else
    {
        printf("Poped element : %d\n", stack[top]);
        top -= 1;
    }
}

// Display Operation
void display()
{
    if(top == -1)
        printf("Stack is empty!\n");
    else
    {
        printf("\nStack Elements : \n");
        for(int i=top; i>=0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int ch, item;
    for(;;)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            printf("\nElement to be pushed : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Selection! try again\n");
        }
    }
    return 0;
}
