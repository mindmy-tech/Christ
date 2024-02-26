#include <stdio.h>

int n;

int insert(int a[], int high, int pos, int element);

int main()
{
    int a[100], pos, element, i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("\n Enter the position to insert the element: ");
    scanf("%d", &pos);
    if (pos >= 0 && pos <= n && n < 100) {
        n = insert(a, n, pos, element);
    } else {
        printf("Invalid position or array is full!\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("\n %d", a[i]);
    }
    return 0;
}

int insert(int a[], int high, int pos, int element)
{
    int i;
    if (high >= 100) { 
        return high; 
    }
    for (i = high; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = element;
    return high + 1;
}