#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}node;

node* insertNode(node* head, int value);
void inorderTraversal(node* head);

node* createNode(int value)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(void)
{
    node* headNode = NULL;
    int opt, value;
    do
    {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%i", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            headNode = insertNode(headNode, value);
            break;
        case 2:
            inorderTraversal(headNode);
            break;
        case 3:
            break;
        case 4:
            /* code */
            break;
        default:
            break;
        }
    } while (opt!=5);
    
}


node* insertNode(node* head, int value)
{
    if (head == NULL)
    {
        return createNode(value);
    }
    if (value < head->data)
    {
        head->left = insertNode(head->left, value);
    }
    else
    {
        head->right = insertNode(head->right, value);
    }
    return head;
}

void inorderTraversal(node* head)
{
    if (head == NULL)
    {
        return;
    }
    inorderTraversal(head->left);
    printf("%d ", head->data);
    inorderTraversal(head->right);
}

