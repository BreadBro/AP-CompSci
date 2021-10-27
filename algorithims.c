#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void Selection(int size, int arr[]) {
    int tempSmall;
    //int tempIndex;
    int count = 0;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                tempSmall = arr[i];
                arr[i] = arr[j];
                arr[j] = tempSmall;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%i ", arr[i]);
    }
}

void Insertion(int size, int arr[]) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int count = i - 1;
        while (count >= 0 && arr[count] > temp) {
            arr[count + 1] = arr[count];
            count--;
        }
        arr[count + 1] = temp;
    }
    for (int i = 0; i < size; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}


int main(void) {
    int arr[] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21};
    int size = sizeof(arr)/sizeof(arr[0]);
    int answ;
    int x = 1;
    while (x == 1) {
        answ = get_int("Do you want to use selection sort or insertion sort? (1 or 2) ");
        if (answ == 1) {
            Selection(size, arr);
        }
        else if (answ == 2) {
            Insertion(size, arr);
        }
        else {
            x = 0;
        }
    }
}
