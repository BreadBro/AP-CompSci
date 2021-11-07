#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int arr[] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21};
int binarySearch(int size, int num, int firstIndex) {
    int mid = (size+firstIndex)/2;
    if (num == arr[mid]) {
        return mid;g
    }
    else if (num > arr[mid]) {
        firstIndex = mid+1;
        return binarySearch(size, num, firstIndex);
    }
    else if (num < arr[mid]){
        size = mid-1;
        return binarySearch(size, num, firstIndex);
    }
    else {
        return -1;
    }
}

int linear(int size, int num) {
    int index;
    for (int i = 0; i < size; i++) {
        if (num == arr[i]) {
            index = i;
            break;
        }
        else {
            index = -1;
        }
    }
    return index;
}
void Insertion(int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int count = i - 1;
        while (count >= 0 && arr[count] > temp) {
            arr[count + 1] = arr[count];
            count--;
        }
        arr[count + 1] = temp;
    }
}
int main(void) {
    int num = get_int("Number: ");
    int size = sizeof(arr)/sizeof(arr[0]);
    int firstIndex = 0;
    int answ;
    clock_t start, end;
    do {
        answ = get_int("Binary (0) or linear (1). ");
    }
    while (answ != 0 && answ != 1);
    int index;
    if (answ == 0) {
        start = clock();
        Insertion(size);
        index = binarySearch(size, num, firstIndex);
        end = clock();
        if (index == -1) {
            printf("Number is not in the array. (time: %f)", (double)(end-start)/CLOCKS_PER_SEC);
        }
        else {
            printf("Index: %i (time: %f)\n", index, (double)(end-start)/CLOCKS_PER_SEC);
        }

    }
    if (answ == 1) {
        start = clock();
        index = linear(size, num);
        end = clock();
        if (index == -1) {
            printf("Number is not in the array. (time: %f)", (double)(end-start)/CLOCKS_PER_SEC);
        }
        else {
            printf("Index: %i (time: %f)\n", index, (double)(end-start)/CLOCKS_PER_SEC);
        }
    }
}