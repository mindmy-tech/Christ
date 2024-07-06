#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL; 

node* insert(int data, int index) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (index ==  0) {
        newNode->next = head;
        return newNode;
    }

    node* current = head;
    for (int i =  0; i < index -  1; i++) {
        if (current->next == NULL) {
            printf("Position out of range\n");
            return head;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

node* delete(int data) {
    node* current = head;
    node* prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("Element not found\n");
    return head;
}

void display() {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_reverse(node * head) {
    if (head == NULL) {
        return;
    }
    display_reverse(head->next);
    printf("%d ", head->data);
}


int main(void) {
    int option, data, index;

    do {
        printf("\n   1.Insert\n   2.Delete\n   3.Display\n   4.Display reverse\n   5.Exit\n Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case  1:
            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter index: ");
            scanf("%d", &index);
            head = insert( data, index);
            break;
        case  2:
            printf("Enter element to be deleted: ");
            scanf("%d", &data);
            head = delete(data);
            break;
        case  3:
            display(head);
            break;
        case  4:
            printf("Reverse list: ");
            display_reverse(head);
            printf("\n");
            break;
        case  5:
            printf("\n exiting...\n");
            break;
        default:
            printf("\n Invalid choice \n");
        }
    } while (option !=  5);

    return  0;
}
