#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node *prev;
    struct node *next;
} node;

int main(void)
{
    node node1;
    node1.data = 21;
    node1.prev = NULL;
    node1.next = NULL;
    
    node node2;
    node2.data = 66;
    node2.next = NULL;
    node2.prev = NULL;

    node1.next = &node2;

    node node3;
    node3.data = 66;
    node3.next = NULL;
    node3.prev = NULL;

    node2.next = &node3;
    

    node *temp;
    temp = &node1;
    while (temp != NULL)
    {
        printf("data : %i\n", temp->data);
        node *buffer = temp->next;
        temp = buffer;
    }
    
}