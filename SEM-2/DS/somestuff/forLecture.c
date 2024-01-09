#include <stdio.h>

void deletel(int a[], int high, int pos)
{
    int i, n;
    i = pos;
    while (i < high)
    {
        a[i] = a[i + 1];
        i = i + 1;
    }
    n = n - 1;
}
int main()
{
    int a[100], high, low, pos, n, i;
    printf("enter the number of elements");
    scanf("%d", &n);
    printf("Enter the position");
    scanf("%d", &pos);

    a[i] = n;
    low = 0;
    high = n - 1;
    deletel(a, high, pos);
}