#include <stdio.h>

int main(void)
{
    int arr_size;
    int delete_target;
    int start_index, last_index;
    printf("Enter the size of array: ");
    scanf("%i", &arr_size);

    last_index = arr_size-1;
    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        printf("Enter element [%i] :", i);
        scanf("%i", &arr[i]);
    }

    printf("Enter the element to check for duplicates delete it:");
    scanf("%i", &delete_target);

    int cnt = 0;

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] ==  delete_target)
        {
            cnt++;
            if (cnt > 1)
            {
                for(int j =  i; j <= last_index; j++)
                {
                    arr[j] = arr[j+1];
                }
                last_index--;
            }
        }


    }
    for (int i = 0; i < last_index; i++)
    {
        printf("[%i] %i\n", i, arr[i]);
    }
}