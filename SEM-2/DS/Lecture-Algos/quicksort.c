#include <stdio.h>

void swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high)
{
    // choose the pivot
    int pivot = arr[high];

    // Index of smaller element and Indicate
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Quicksort function Implement

void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    // Function call
    quickSort(arr, 0, n - 1);
  
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
