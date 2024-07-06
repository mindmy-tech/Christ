
def main():
    arr = [12, 11, 13, 5, 6, 7, 88, 2, 1, -5, 12]
    print(quicksort(arr))

def quicksort(arr):
    arr_size = (len(arr))
    if arr_size <= 1:
        return arr
    
    pivot = arr[arr_size -1]
    
    left_arr = []
    right_arr = []
    
    for i in range(0, arr_size-1):
        if arr[i] < pivot:
            left_arr.append(arr[i])
        else:
            right_arr.append(arr[i])
    
    return quicksort(left_arr)+ [pivot] +quicksort(right_arr)


if __name__ == "__main__":
    main()