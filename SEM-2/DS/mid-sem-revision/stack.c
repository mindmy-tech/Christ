#include <stdio.h>

#define MAX  5

struct stack
{
    int a[MAX];
    int top;
} s;

// Function prototypes
void push(int element);
int pop();
void display();

int main()
{
    int option;
    int element;
    s.top = -1;
    do
    {
        printf("\n  1.Push \n  2.Pop \n  3.Display \n  4.Exit \n Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case  1:
            printf("Enter element to be inserted: ");
            scanf("%d", &element);
            push(element);
            break;
        case  2:
            printf("\n Element deleted- %d \n", pop());
            break;
        case  3:
            display();
            break;
        case  4:
            printf("\n Exiting...\n");
            break;
        default:
            printf("\n Invalid choice \n");
        }
    } while (option !=  4);

    return  0;
}

void push(int element)
{
    if (s.top >= MAX -  1)
        printf("\n Error: overflow \n");
    else
    {
        s.top = s.top +  1;
        s.a[s.top] = element;
    }
}

int pop()
{
    if (s.top == -1)
    {
        printf("\n Error: underflow \n");
        return -1; // Doesnt exist
    }
    else
    {
        s.top--;
        return s.a[s.top +  1]; // Return the popped element
    }
}

void display()
{
    if (s.top == -1)
        printf("\n No elements in stack \n");
    else
    {
        printf("\n Elements in the stack: \n");
        int i;
        for (i =  0; i <= s.top; i++)
            printf("%d \n", s.a[i]);
    }
}
