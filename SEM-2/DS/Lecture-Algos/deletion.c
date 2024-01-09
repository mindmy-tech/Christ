#include <stdio.h>

int main(void)
{
    int arr_size;
    int delete_target;
    int start_index, last_index;
    printf("Enter the size of array: ");
    scanf("%i", &arr_size);

    last_index = arr_size;
    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        printf("Enter element [%i] :", i);
        scanf("%i", &arr[i]);
    }

    printf("Enter the element index which u wanna delete:");
    scanf("%i", &delete_target);

    if (delete_target >= arr_size)
    {
        printf("Not possible\n");
    }

    else 
    {
        for(int j = delete_target; j < arr_size ; j++ )
        {
            arr[j] = arr[j + 1 ];
        }
        last_index--;
        for (int i = 0; i < last_index; i++)
        {
            printf("[%i] %i\n", i, arr[i]);
        }
    }
}