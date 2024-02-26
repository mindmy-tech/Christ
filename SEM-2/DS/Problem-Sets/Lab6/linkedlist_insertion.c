#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
} node;

void insert(int element);
void displaylinkedList(void);


node *ptr = NULL;
int main(void)
{
    char continue_loop = 'y';
    do
    {
        printf("1] enqueue\n2] Display\n3] Exit\n");
        int opt;
        printf("Enter opt:");
        scanf("%i", &opt);
        switch (opt)
        {
        case 1:
            int element_val;
            printf("value to insert: ");
            scanf("%i", &element_val);
            insert(element_val);
            break;
        case 2:
            printf("LinkedList Data \n");
            displaylinkedList();
            break;
        case 3:
            printf("exiting....");
            continue_loop = 'n';
            break;
        default:
            printf("not a option\n");
            break;
        }
    } while (continue_loop == 'y');
    
}

void insert(int element)
{
    node *node1;
    node1 = (node *)malloc(sizeof(node));
    node1->data = element;
    node1->prev = ptr;
    ptr = node1;
    
}

void displaylinkedList(void)
{
    node *ptr_temp = ptr;
    while (ptr_temp != NULL)
    {
        int data = ptr_temp->data;
        printf("        %i\n", data);

        node *temp = ptr_temp->prev;

        ptr_temp = temp;
    }
}
