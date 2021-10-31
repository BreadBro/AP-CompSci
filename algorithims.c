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

}

void bubbleSort(int size, int arr[]) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }
    for (int i = 0; i < size; i++) {
        printf ("%i ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int left, int endOfFirstArray, int right) {
    int size1 = endOfFirstArray - left + 1;
    int size2 = right - endOfFirstArray;

    int LeftArr[size1];
    int RightArr[size2];

    for (int i = 0; i < size1; i++) {
        LeftArr[i] = arr[left + i];
    }


    for (int i = 0; i < size2; i++) {
        RightArr[i] = arr[endOfFirstArray + 1 + i];
    }

    int firstOfFirst = 0;
    int firstOfSecond = 0;
    int x = left;
    while (firstOfFirst < size1 && firstOfSecond < size2) {
        if (LeftArr[firstOfFirst] <= RightArr[firstOfSecond]) {
            arr[x] = LeftArr[firstOfFirst];
            firstOfFirst++;
        }
        else {
            arr[x] = RightArr[firstOfSecond];
            firstOfSecond++;
        }
        x++;
    }

    while (firstOfFirst < size1) {
        arr[x] = LeftArr[firstOfFirst];
        firstOfFirst++;
        x++;
    }

    while (firstOfSecond < size2) {
        arr[x] = RightArr[firstOfSecond];
        firstOfSecond++;
        x++;
    }
}

void mergeSort(int right, int left, int arr[]) {
    if (left < right) {
        int endOfFirstArray = left + (right - left) / 2;
        mergeSort(endOfFirstArray, left, arr);
        mergeSort(right, endOfFirstArray + 1, arr);
        merge(arr, left, endOfFirstArray, right);
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
        answ = get_int("Do you want to use selection sort, insertion sort, bubble sort, or merge sort? (1, 2, 3, 4, or 5) ");
        if (answ == 1) {
            Selection(size, arr);
        }
        else if (answ == 2) {
            Insertion(size, arr);
        }
        else if (answ == 3) {
            bubbleSort(size, arr);
        }
        else if (answ == 4) {
            mergeSort(size-1, 0, arr);
            for (int i = 0; i < size; i++) {
                printf("%i ", arr[i]);
            }
            printf("\n");
        }
        else {
            x = 0;
        }
    }
}
