#include <stdio.h>

void binarySearch(int array[], int len_array, int target);

int main(void)
{
    int array[] = {2,4,5,7,8,9,10,55};
    int len_array = 8;//sizeof(array) / sizeof(int);
    
    int target;
    printf("Targer num:");
    scanf("%i", &target);

    binarySearch(array, len_array, target);
}


void binarySearch(int array[], int len_array, int target)
{
    int start_index= 0;
    int end_index = len_array - 1;
    int mid_index = 0;
    while (start_index <= end_index)
    {
        mid_index = start_index + (end_index - start_index) / 2;
        if (target == array[mid_index])
        {
            printf("Item Found at index %i\n",mid_index);
            break;
        }
        else if (target > array[mid_index])
        {
            start_index = mid_index + 1;
        } else {
            end_index = mid_index - 1 ;  
        }
    }
}