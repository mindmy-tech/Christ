#include "mylib.h"

int main(void)
{
    int arr[] = {};
    int arr_size = sizeof(arr)/ sizeof(int);
    while (1)
    {
        int opt = menu();

        switch (opt)
        {
        case 1:
            int target = 1;
            search(arr, target, arr_size);
            break;
        case 2:
            target = 1;
            binarySearch(arr, target, arr_size);
            break;
        case 3:
            /* code */
            int insert_index = 0;
            int insert_value = 11;
            insert(arr, arr_size, insert_index,insert_value );
            break;
        case 4:
            /* code */
            break;
        case 5:
            break;
        default:
            break;
        }
    }
}