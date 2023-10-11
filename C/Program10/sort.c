
// Sorting algo
#include <stdio.h>
void swap( int *n1, int *n2);
void linear_sort(int arr[], int len);
void printArray(int arr[], int size);


int main(void)
{
    int unsorted_array[] = {4, 2, 6, 9, 10, 1, 7};
    int len_array = sizeof(unsorted_array)/ sizeof(int);
    printf("Original array: ");
    printArray(unsorted_array, len_array);
    linear_sort(unsorted_array, len_array);

}

void linear_sort(int arr[], int len)
{
    for (int i = 0; i < len ; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if ( arr[i] > arr[j] )
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    printf("sorted array: ");
    printArray(arr, len);
}

void swap( int *n1, int *n2)
{
    int buffer = *n1;
    *n1 =  *n2;
    *n2 = buffer;
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 