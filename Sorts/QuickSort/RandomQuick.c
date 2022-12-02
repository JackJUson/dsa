// Optimized implementation of Randomised Quick sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(int a[], int i, int j);

// Randomised Quick Sort
void RandomQuickSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partitionRandom(array, low, high);
        RandomQuickSort(array, low, pivot);
        RandomQuickSort(array, pivot + 1, high);
    }
}

// Randomising pivot
int partitionRandom(int array[], int low, int high) {
    srand(time(0));
    int random = low + rand() % (high - low);

    swap(array, random, low);

    return partition(array, low, high);
}

// Regular partition
int partition(int array[], int low, int high) {
    int pivot = array[low];     // pivot
    int left = low + 1;
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