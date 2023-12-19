#include <stdio.h>

int main(void)
{
    int array[] = {2, 4,5,7,8,9,10,55};
    int len_array = sizeof(array) / sizeof(int);
    
    int target = 9;
    int start_index= 0;
    int end_index = len_array ;
    printf("befor: %i\n", len_array);
    int mid_index = 0;
     while (len_array > 0)
    {
        mid_index = mid_index + (len_array / 2 );
        if (target == array[mid_index])
        {
            printf("Item Found\n");
            break;
        }
        else if (target > array[mid_index])
        {
            start_index = mid_index;
        } else {
            end_index = mid_index ;  
        }
        len_array = end_index - start_index;
        printf("mid :%i\nLen: %i\n",mid_index, len_array);
    }
}