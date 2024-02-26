#include <stdio.h>
#include <stdlib.h>

// Stack structure

typedef struct Node
{
    int data;
    struct Node *prev;
} node;

node *ptr = NULL;

void push(int element);
void display();
int pop();
int dequeue();


int main(void)
{
    int option, element;
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
            printf("\n Element deleted : %i \n", dequeue());
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
    }
    while (option !=  4);
}

void push(int element)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = element;
    new_node->prev = ptr;
    ptr = new_node;
}


void display()
{
    node *temp = ptr;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->prev;
    }
}

int pop()
{
    if (ptr == NULL)
    {
        printf("\n Error: underflow \n");
        return -1;
    }
    node *temp = ptr;
    ptr = ptr->prev;
    int data = temp->data;
    free(temp);
    return data;
}

int dequeue()
{
    if (ptr == NULL)
    {
        printf("\n Error: underflow \n");
        return -1;
    }
    node *temp = ptr;
    node *prev_node = NULL;
    while (temp->prev != NULL)
    {
        prev_node = temp;
        temp = temp->prev;
    }
    int data = temp->data;
    ptr = prev_node;
    if (ptr != NULL)
    {
        ptr->prev = NULL;
    }
    free(temp);
    return data;
}