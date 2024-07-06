#include <stdio.h>

#define MAX_SIZE 10

void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[MAX_SIZE] = {64, 25, 12, 22, 11, 90, 37, 5, 18, 76};
    int n = MAX_SIZE;
    int choice;

    printf("Original Array:\n");
    printArray(arr, n);

    printf("\nSorting Menu:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertionSort(arr, n);
            printf("After Insertion Sort:\n");
            printArray(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            printf("After Selection Sort:\n");
            printArray(arr, n);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}