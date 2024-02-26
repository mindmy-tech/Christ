#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
} node;


void insert(int element);
void delete(void);
void displaylinkedList(void);


node *ptr = NULL;
int main(void)
{
    char continue_loop = 'y';
    do
    {
        printf("1] insert\n2] Dequeue\n3] Display\n4] Exit\n");
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
            printf("Dequeued\n");
            delete();
            break;
        case 3:
            printf("LinkedList Data \n");
            displaylinkedList();
            break;
        case 4:
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

void delete(void) {
    if (ptr == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *temp = ptr;
    ptr = ptr->prev;
    free(temp);
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
