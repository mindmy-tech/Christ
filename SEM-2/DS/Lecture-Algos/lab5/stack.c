#include <stdio.h>
#include <stdlib.h>

int choice, element;
struct node
{
    int data;
    struct node *next;
};
struct node *node1, *ptr;

void menu()
{
    printf("\n  1.Push");
    printf("\n  2.Pop");
    printf("\n  3.Display");
    printf("\n  4.Exit");
    printf("\n\nEnter Choice: ");
    scanf("%d", &choice);
}

void createqueue()
{
    ptr = NULL;
}

void push(int elm)
{
    node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = elm;
    node1->next = ptr;
    ptr = node1;
}

int pop()
{
    if (ptr == NULL)
    {
        printf("\n\tUNDERFLOW\n");
        return -1;
    }
    else
    {
        int obj = ptr->data;
        struct node *temp = ptr->next;
        free(ptr);
        ptr = temp;
        return obj;
    }
}

void display()
{
    printf("\n\t ");
    struct node *temp = ptr;
    while (temp != NULL)
    {
        printf("%i<-", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    do
    {
        menu();
        switch (  )
        {
        case  1:
            printf("Enter element: ");
            scanf("%d", &element);
            push(element);
            break;
        case  2:
            pop();
            break;
        case  3:
            display();
            break;
        case  4:
            break;
        default:
            printf("Enter a valid option.\n");
        }
    } while (choice !=  4);

    return  0;
}
