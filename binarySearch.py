arr = [34, 543, 2, 43, 45, 7, 1]
def sort(arr):
    for j in range(0, len(arr)):
        for i in range(1, len(arr)):
            if arr[i] < arr[i - 1]:
                temp = arr[i]
                arr[i] = arr[i - 1]
                arr[i - 1] = temp
    return arr
arr = sort(arr)
val = int(input("What number do you want to search for? "))
length = len(arr)
def binSearch(size, firstIndex):
    middle = int((size + firstIndex)/2)
    if size == 1:
        return -1
    if val == arr[middle]:
        return middle
    elif val > arr[middle]:
        firstIndex = middle + 1
        return binSearch(size, firstIndex)
    elif val < arr[middle]:
        size = middle - 1
        return binSearch(size, firstIndex)
    

index = binSearch(length, 0)
if index == -1:
    print("The number is not in the array.")
else:
    print("The number is at index %i." %index)