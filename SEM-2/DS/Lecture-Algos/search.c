#include <stdio.h>


int main(void)
{
    int array[] = { 1,6,3,5,8,2};
    int target = 2;
    int len_arr = sizeof(array)/sizeof(int);
    for (int i = 0; i < len_arr; i++ )
    {
        if (array[i] == target)
        {
            printf("Element Found at INDEX %i\n", i);
            return 0;
        }
    }
    printf("Element Not FOUND !!\n");
}