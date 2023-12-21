#include <stdio.h>
#include <stdlib.h>


int search_sen(int arr[], int target, int len_arr, int starting_index);
void search(int arr[], int target, int len_arr);

int main(void)
{
    int target = 3;
    int array[] = { 1,6,3,5,8,2, target};
    int len_arr = sizeof(array)/sizeof(int);
    int starting_index = 0;
    int target_index = search_sen(array, target, len_arr, starting_index);

    search(array, target, len_arr);
    return 0;
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


void search(int arr[], int target, int len_arr)
{
    int cnt = 0;
    for (int i = 0; i < len_arr; i++ )
    {
        if (arr[i] == target)
        {
            printf("The element exists at %i", i);
            cnt ++;
        }
    }
    printf("the element exists %d tiems", cnt);
}