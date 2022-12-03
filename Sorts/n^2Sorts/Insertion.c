// Optimized implementation of Insertion sort
#include <stdio.h>
#include <stdbool.h>

// Insertion Sort: Stable Adapative O(n^2)
// Fastest Sort for already sorted list O(n)

// Insertion Sort with second loop iterating backwards
void InsertionSort(int array[], int low, int high) {
    int comparison = 0;
    for (int i = low + 1; i <= high; i++) {
        int key = array[i];
        int j;
        for (j = i; j > low; j--) {
            if (!(key < array[j - 1])) break;
            array[j] = array[j - 1];
            comparison++;
        }
        array[j] = key;
    }
    printf("%d: comparisons\n", comparison);
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

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int array[] = {4, 3, 6, 8, 2};
    int size = sizeof(array) / sizeof(array[0]);
    printArray(array, size);

    InsertionSort(array, 0, size - 1);
    
    printf("Sorted Array in Ascending Order:\n");
    printArray(array, size);
}
