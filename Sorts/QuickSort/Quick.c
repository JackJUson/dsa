// Optimized implementation of Quick sort
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void swapA(Item a[], int i, int j);
void swapD(int *x, int *y);

// Simple Quick Sort
void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pivot = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pivot - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pivot + 1, high);
  }
}

// Naive QuickSort: Partition from left most element as pivot
// Fastest for random sort O(n log n)
// Worst case sorted and reverse order O(n^2)
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

// Partition from right most element as pivot
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swapD(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swapD(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

/* 
    Partition gives quicksort advantage as the items are in the correct
    order in relation to the pivot. This means that we never have to
    compare elements on the left side of the partition to elements on the
    right side of the partition.
*/

/*
    Quicksort usually has an absolute worst-case time requirement of O(n^2).
    The worst case occurs when, at every step, the partition procedure splits
    an n-length array into arrays of size 1 and n - 1. This "unlucky" selection
    of pivot requires O(n) recursive calls, leading to a O(n^2) worst-case.

    Hence either choosing maximum or minimum element is the pivot will lead
    to worst case quicksort O(n^2).

    Sorted array -> left most or right most -> Worst case
    Reverse order array -> left most or right most -> Worst case
    All elements equal -> left most or right most -> Worst case

    Randomised quicksort -> unlikely to have worst case
    Median to Three quicksort -> unlikely to have worst case
*/

void swapA(Item a[], int i, int j) {
    Item temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void swapD(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}