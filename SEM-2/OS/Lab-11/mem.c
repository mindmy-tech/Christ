#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Dynamic Memory Allocation
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 2. Memory Reallocation
    int new_size;
    printf("Enter the new size: ");
    scanf("%d", &new_size);

    int* temp = (int*)realloc(arr, new_size * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(arr); // Ensure to free the original memory before exiting
        return 1;
    }
    arr = temp;

    if (new_size > n) {
        printf("Enter %d new elements: ", new_size - n);
        for (int i = n; i < new_size; i++) {
            scanf("%d", &arr[i]);
        }
    }

    printf("The new elements are: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 3. Free the Memory
    free(arr);
    arr = NULL; // It's a good practice to set the pointer to NULL after freeing it

    return 0;
}
