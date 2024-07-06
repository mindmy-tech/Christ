#include <stdio.h>

// Function declaration
int linearSearch(int arr[], int length, int key);

int main() 
{
    int arr[100];
    int i, n, key;
    
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Target value that has to be searche
    printf("Enter the element that has to be searched: ");
    scanf("%d", &key);

    // Function call
    int index = linearSearch(arr, n, key);

    if (index != -1)
    {
        printf("The element is found at index %d in the array.\n", index);
    }
    else
    {
        printf("The element is not found in the array.\n");
    }

    return 0;
}

// Function definition
int linearSearch(int arr[], int length, int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            return i; 
        }
    }

    return -1;
}