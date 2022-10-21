#Python program to search for a element in a array using binary search algorithm

def binary_search(arr, low, high, item):
 
    if high >= low:
 
        mid = (high + low) // 2
 
        if arr[mid] == item:
            return mid

        elif arr[mid] > item:
            return binary_search(arr, low, mid - 1, item)
 
        else:
            return binary_search(arr, mid + 1, high, item)
 
    else:
        return -1

arr=[]
arr=[int(item) for item in input('Enter the elements of the array: ').split()]

item = int(input('Enter the element to search: '))
 
res = binary_search(arr, 0, len(arr)-1, item)
 
if res != -1:
    print("Element found in the array at index", str(res))
else:
    print("Element not found in the array")
