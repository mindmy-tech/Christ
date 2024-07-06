// Double linked list
#include <stdio.h>
#include <stdlib.h>

// fn Prototypes
void insert(int element);
void delete(int element);
void displaylinkedList(void);
void displaylinkedList_reverse(void);

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}node;

node* head = NULL;

int main(void)
{
    char continue_loop = 'y';
    do
    {
        printf("1] insert\n2] delete \n3] Display\n4] display reversed \n5] Exit\n");
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
            int delete_val;
            printf("Deletion\n");
            scanf("%i", &delete_val);
            delete(delete_val);
            break;
        case 3:
            printf("LinkedList Data \n");
            displaylinkedList();
            break;
        case 4:
            printf("reversed LinkedList Data \n");
            displaylinkedList_reverse();
            break;
        case 5:
            printf("exiting....");
            continue_loop = 'n';
            break;
        default:
            printf("not a option\n");
            break;
        }
    } while (continue_loop == 'y');
}

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(int element)
{
    if (head == NULL)
    {
        head = createNode(element);
    }
    else
    {
        node* newNode = createNode(element);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

}

void delete(int element)
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            if (temp->prev == NULL)
            {
                head = temp->next;
                head->prev = NULL;
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void displaylinkedList(void)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("        %i\n", temp->data);
        temp = temp->next;
    }

}
void displaylinkedList_reverse(void)
{
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("        %i\n", temp->data);
        temp = temp->prev;
    }
}