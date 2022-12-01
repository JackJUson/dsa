// Optimized implementation of Insertion sort
#include <stdio.h>
#include <stdbool.h>

// Insertion Sort: Stable Adapative O(n^2)

// Insertion Sort with second loop iterating backwards
void InsertionSort(int a[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = a[i];
        for (int j = i; j > lo; j--) {
            if (!(key < a[j - 1])) break;
            a[j] = a[j - 1];
        }
        a[j] = key;
    }
}

// Insertion Sort with while loop
void InsertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}