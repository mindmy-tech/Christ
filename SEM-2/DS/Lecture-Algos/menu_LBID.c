#include <stdio.h>


// Prototypes
int menu(void);

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
            int target = 1;
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

// Linear Search
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

// Binary Search
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

// Insertion
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

// Deletion 
void deletion(int arr[], int arr_size, int delete_index)
{
    int last_index = arr_size -1;
    if (delete_index >= arr_size)
    {
        printf("Not possible\n");
    }

    else 
    {
        for(int j = delete_index; j < arr_size ; j++ )
        {
            arr[j] = arr[j + 1 ];
        }
        last_index--;
        for (int i = 0; i <= last_index; i++)
        {
            printf("[%i] %i\n", i, arr[i]);
        }
    }
}


// Menu

int menu(void)
{
    int opt;
    printf("\n1] Linear Search\n2] Binary Search\n3] Insertion\n4] Deletion\n5] Exit\nYour Option: ");
    scanf("%i", &opt);
    return opt;
}