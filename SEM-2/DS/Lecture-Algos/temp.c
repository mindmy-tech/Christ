#include<stdio.h>

void insert(int a[], int high, int pos, int element, int n);

int main() {
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++) {
        printf("Enter the element %d: ", i);
        scanf("%d", &a[i]);
    }

    int element, pos;
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    printf("Enter the position: ");
    scanf("%d", &pos);

    insert(a, n - 1, pos, element, n);

    
    for (i = 0; i < n + 1; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void insert(int a[], int high, int pos, int element, int n) {
    int i;

    for (i = high; i >= pos; i--) {
        a[i + 1] = a[i];
    }

    a[pos] = element;
    n = n + 1;
}