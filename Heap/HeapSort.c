// Optimized implementation of Heap Sort
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Heap.h"

void swap(Item a[], int i, int j);

// Heap Sort: O(n log n)

// Heap Sort using PQ/Heap functions
void HeapSort(Item a[], int low, int high) {
    int size = sizeof(a) / sizeof(Item);
    Heap h = newHeap(size);
    // Insert all items from a[] into Heap
    for (int i = low; i <= high; i++) {
        HeapInsert(h, a[i]);
    }

    // Reinsert all items from heap back into a[]
    for (int i = high; i >= low; i--) {
        Item it = HeapDelete(h);
        a[i] = it;
    }
}

// Direct Heap Sort
void HeapSort(Item a[], int low, int high) {
    int i, N = high - low + 1;
    Item *h = a[low - 1];
    for (i = N/2; i > 0; i--) {
        fixDown(h, i, N);
    }
    while (N > 1) {
        swap(h, 1, N);
        N--;
        fixDown(h, 1, N);
    }
}


void swap(Item a[], int i, int j) {
    Item temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}