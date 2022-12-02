// Improvement on QuickSort
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "Insertion.h"
#include "Quick.h"
#include "Stack.h"

void swap(int a[], int i, int j);

/*
Little benefit from partitioning when array size < 5
Insertion sort on small partitions for efficiency
*/
void quickSort(int array[], int loww, int high) {
    if ((high - low) < Threshold) {
        insertionSort(array, low, high);
        return;
    }
    int pivot = partition(array, low + 1, high - 1);
    quickSort(array, low, pivot - 1);
    quickSort(array, pivot + 1, high);
}

// Quick Sort implemented using stack
void quickSortStack(int array[], int low, int high) {
    Stack s = newStack();
    StackPush(s, high); 
    StackPush(s, low);
    while (!StackEmpty(s)) {
        low = StackPop(s);
        high = StackPop(s);
        if (high > low) { 
            int pivot = partition (array, low, high);
            StackPush(s, high); StackPush(s, pivot + 1);
            StackPush(s, pivot - 1); StackPush(s,low);
        }
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}