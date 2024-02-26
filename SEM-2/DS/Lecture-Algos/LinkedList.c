#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
} node;


void displaylinkedList(node *current_ptr);

int main(void)
{
    node *ptr = NULL;

    for (int i = 0; i < 8; i++)
    {
        node *node1;
        node1 = (node *)malloc(sizeof(node));
        node1->data = i + 1;
        node1->prev = ptr;
        ptr = node1;
    }

    displaylinkedList(ptr);

    return 0;
}


void displaylinkedList(node *current_ptr)
{
    while (current_ptr != NULL)
    {
        int data = current_ptr->data;
        printf("%i\n", data);

        node *temp = current_ptr->prev;

        free(current_ptr);
        current_ptr = temp;
    }
}

void pop(node *current_ptr)
{
    if (current_ptr->prev == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        node *temp;
        temp = current_ptr;
        current_ptr = current_ptr->prev;
    }
}

