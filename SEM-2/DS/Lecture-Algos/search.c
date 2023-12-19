#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_sen(int arr[], int target, int len_arr, int starting_index);
int search(int arr[], int target, int len_arr);

int main(void)
{
    int target = 3;
    int array[] = { 1,6,3,5,8,2, target};
    int len_arr = sizeof(array)/sizeof(int);
    int starting_index = 0;
    clock_t start_time = clock();
    int target_index = search_sen(array, target, len_arr, starting_index);
    clock_t end_time = clock();
    double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    clock_t start_time1 = clock();
    int target_index2 = search(array, target, len_arr);
    clock_t end_time1 = clock();
    double elapsed_time2 = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("%f - %f", elapsed_time, elapsed_time2);
    // printf('%i - %i', elapsed_time, elapsed_time2);
    // if (target_index < 0)
    // {
    //     printf("Element Not FOUND !!\n");
    //     return 0;
    // }
    // printf("Element Found at INDEX %i\n", target_index);
    // return 0;
}


int search_sen(int arr[], int target, int len_arr, int starting_index)
{
    int i ;
    for (i = starting_index; arr[i] != target ; i++ )
    {}
    if (i == len_arr)
    {
        return -1;   
    }
    return i;
}


int search(int arr[], int target, int len_arr)
{
    for (int i = 0; i < len_arr; i++ )
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}