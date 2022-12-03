// Optimized implementation of Median of three Quick sort
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int a[], int i, int j);

// Quick Sort with sorting low, middle and high values of array
void quickSort(int array[], int low, int high) {
    if (low < high) {
        medianOfThree(array, low, high);
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

// Median-of-three quicksort
void medianOfThree(int array[], int low, int high) {
    int middle = (low + high) / 2;
    if (array[middle] < array[low]) swap(array, low, middle);
    if (array[high] < array[middle]) swap(array, middle, high);
    if (array[middle] < array[low]) swap(array, low, middle);
    // Array should be sorted by array[low] < array[middle] < array[high]
    // swap array[middle] to array[low + 1] to use as pivot
    swap(array, middle, low + 1);
}

// Regular partition
int partition(int array[], int low, int high) {
    int pivot = array[(low + high) / 2];     // pivot
    int left = low;
    int right = high;
    while (left < right) {
        while (left < right && array[left] <= pivot) left++;
        while (left < right && array[right] >= pivot) right--;
        if (left == right) break;
        swap(array, left, right);
    }
    int middle = array[left] <= pivot ? left : left - 1;
    swap(array, low, middle);
    return middle;
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}