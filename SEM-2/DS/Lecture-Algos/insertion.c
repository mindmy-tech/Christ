#include <stdio.h>

void insert(int arr[], int arr_size, int insert_index, int insert_value);

int main(void)
{
    int arr_size;
    int insert_index;
    int start_index, last_index, insert_value;
    printf("Enter the size of array: ");
    scanf("%i", &arr_size);

    // last_index = arr_size ;
    int arr[arr_size+5];

    for (int i = 0; i < arr_size; i++)
    {
        printf("Enter element [%i] :", i);
        scanf("%i", &arr[i]);
    }

    printf("Enter the element index which u wanna insert:");
    scanf("%i", &insert_index);

    printf("Enter Insert Value:");
    scanf("%i", &insert_value);

    insert(arr, arr_size, insert_index, insert_value);
}

void insert(int arr[], int arr_size, int insert_index, int insert_value)
{
    int last_index = arr_size;
    if (insert_index > arr_size)
    {
        printf("Not possible\n");
    }

    else 
    {
        for(int j = last_index; j >= insert_index ; j-- )
        {
            arr[j+1] = arr[j];
        }
        last_index++;
        arr[insert_index] = insert_value; 
        for (int i = 0; i < last_index; i++)
        {
            printf("[%i] %i\n", i, arr[i]);
        }
    }
}
