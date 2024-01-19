#include <stdio.h>

#define MAX 5

typedef struct
{
    int arr[MAX];
    int index;
} queue;

queue Q;

void enqueue(int arr[], int value);
void dequeue(int arr[]);
void display();

int main()
{

    Q.index = -1;
    do
    {
        printf("1] Push\n2] Pop\n3] Display\n4] Exit\n");
        int opt;
        printf("Enter opt:");
        scanf("%i", &opt);
        switch (opt)
        {
            case 1:
                printf("enqueue\n");
                printf("enter value :");
                int insert_value;
                scanf("%i", &insert_value);
                enqueue(Q.arr, insert_value);
                break;
            case 2:
                printf("dequeue\n");
                dequeue(Q.arr);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting....");
                return 0;
            default:
                break;
        }
    } while (1);
}

void enqueue(int arr[], int value)
{
    if (Q.index == MAX -1)
    {
        printf("Overflow ...\n");
    }
    else
    {
        Q.index++;
        Q.arr[Q.index] = value;
    }
}

void dequeue(int arr[])
{
    if (Q.index == -1)
    {
        printf("Underflow...\n");
    }
    else 
    {
        for(int i = 0; i < Q.index+1; i++)
        {
            Q.arr[i] = Q.arr[i + 1];
        }
        Q.index--;
    }
}

void display()
{
    printf("Displaying...\n");

    for (int i = 0; i < Q.index+1; i++)
    {
        printf("    %i] %i\n", i+1, Q.arr[i]);
    }
    printf("\n");
}