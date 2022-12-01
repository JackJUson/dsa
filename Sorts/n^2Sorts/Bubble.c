// Optimized implementation of Bubble sort
#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y);

// Bubble Sort: Stable Adapative O(n^2)

// Bubble sort with second loop iterating backwards 
// and sorting section of array between low and high index
void BubbleSort(Item a[], int low, int high) {
    int nswaps;
    for (int i = low; i < high; i++) {
        nswaps = 0;
        for (int j = high; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                nswaps++;
            }
        }
        if (nswaps == 0) break; // All sorted and return
    }
}

// Bubble sort with second loop iterating forwards 
// and sorting entire array
void BubbleSort(int array[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]); // & Depends on the swap function
                swapped = true;
            }
        }
        if (!swapped) break; // All sorted and return
    }
}

//  Bubble sort with only swapped condition
void BubbleSort(int a[], int size) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            if (a[i] > a[i + 1]) {      // change > to < for descending array
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}