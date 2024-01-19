#include <stdio.h>

#define MAX 5

struct stack
{
    int arr[MAX];
    int last_index;
};


void Push(int element);
void Pop(void);
void Display();

struct stack S;
int main(void)
{
    char continue_loop = 'y';
    S.last_index = -1;
    do
    {
        /* code */

        printf("1] Push\n2] Pop\n3] Display\n4] Exit\n");
        int opt;
        printf("Enter opt:");
        scanf("%i", &opt);
        switch (opt)
        {
        case 1:
            int element_val;
            printf("Pushing\n");
            printf("value to insert: ");
            scanf("%i", &element_val);
            Push(element_val);
            break;
        case 2:
            /* code */
            printf("poping\n");
            Pop();
            break;
        case 3:
            /* code */
            printf("displying\n");
            Display();
            break;
        case 4:
            /* code */
            printf("exiting....");
            continue_loop = 'n';
            break;
        
        default:
            printf("not a option");
            break;
        }
    } while (continue_loop == 'y');
    
}

void Push(int element)
{
    if (S.last_index == MAX -1 )
    {
        printf("Overflow ...\n");
    }
    else 
    {
        S.last_index += 1;
        S.arr[S.last_index] = element;
    }
}
 
void Pop(void)
{
    if (S.last_index == -1)
    {
        printf("underflow....\n");
    }
    else
    {
        printf("deleted element : %i\n", S.arr[S.last_index]);
        S.last_index--;
    }
}

void Display()
{
    printf("Array\n");
    for(int i = 0; i < S.last_index+1; i++)
    {
        printf("%i] %i\n", i+1, S.arr[i]);
    }
}

int isEmpty()
{
    if (S.last_index == -1)
    {
        return 1;
    }
    return 0;
}
