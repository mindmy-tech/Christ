#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* new_node(int data) {
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(node** front, node** rear, int data) {
    node* node = new_node(data);
    
    if (*rear == NULL) {
        *front = *rear = node;
        return;
    }
    
    (*rear)->next = node;
    *rear = node;
}

int dequeue(node** front, node** rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    
    node* temp = *front;
    int item = temp->data;
    
    *front = temp->next;
    
    if (*front == NULL) {
        *rear = NULL;
    }
    
    free(temp);
    return item;
}

void display(node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void menu() {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    node *front = NULL, *rear = NULL;
    int choice, data;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case  1: // Enqueue
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case  2: // Dequeue
                data = dequeue(&front, &rear);
                if (data != INT_MIN) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case  3: // Display
                printf("Queue: ");
                display(front);
                break;
            case  4: // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice !=  4);

    return  0;
}
