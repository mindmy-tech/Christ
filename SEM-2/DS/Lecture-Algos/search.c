#include <stdio.h>


int search(int arr[], int target);

int main(void)
{
    int array[] = { 1,6,3,5,8,2};
    int target = 2;
    int target_index = search(array, target);
    if (target_index < 0)
    {
        printf("Element Not FOUND !!\n");
        return 0;
    }
    printf("Element Found at INDEX %i\n", target_index);
    return 0;
}


int search(int arr[], int target)
{
    int len_arr = sizeof(arr)/sizeof(int);
    for (int i = 0; i < len_arr; i++ )
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}