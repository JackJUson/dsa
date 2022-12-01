// Optimized implementation of Heap Data Structure
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Item;

typedef struct HeapRep {
    Item *items;    // array of Items
    int nitems;     // #items in array -> Number of things in current heap
    int nslots;     // #elements in array -> Size of the array
} HeapRep;

typedef HeapRep *Heap;

// Priority Queue exactly the same as Heap
typedef Heap PQueue;

void printHeap(Heap h);
void fixDown(Item a[], int i, int N);
Item HeapDelete(Heap h);
void swap(Item a[], int i, int j);
void fixUp(Item a[], int i);
void HeapInsert(Heap h, Item it);
Heap newHeap(int N);

// Create Heap
Heap newHeap(int N) {
    Heap new = malloc(sizeof(HeapRep));
    Item *a = malloc((N + 1)*sizeof(Item));
    assert(new != NULL && a != NULL);
    new->items = a;
    new->nitems = 0;
    new->nslots = N;
    return new;
}

// Insert Heap -> 2 step process
// Move item up into correct position O(log n)
void HeapInsert(Heap h, Item it) {
    // Check for space in Heap
    assert(h->nitems < h->nslots);
    h->nitems++;

    // Add new item at end of array
    // (Add to the right-most bottom-most node)
    h->items[h->nitems] = it;
    
    // Move new item to its correct place
    fixUp(h->items, h->nitems);
}

void fixUp(Item a[], int i) {
    while (i > 1 && a[i/2] < a[i]) {
        swap(a, i, i/2);
        i = i/2;
    }
}

void swap(Item a[], int i, int j) {
    Item temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


// Delete root of Heap -> 3 step process
// Move new root down into correct position O(log n)
Item HeapDelete(Heap h) {
    Item top = h->items[1];

    // overwrite the first item by the last item
    // Replace the top node with bottom-most right-most node
    h->items[1] = h->items[h->nitems];
    h->nitems--;

    // Move new root to correct position
    fixDown(h->items, 1, h->nitems);

    // Return deleted item
    return top;
}

void fixDown(Item a[], int i, int N) {
    while (2*i <= N) {
        // Left child index
        int j = 2*i;
        // Choose larger of two children
        if (j < N && a[j] < a[j + 1]) j++;
        if (a[i] >= a[j]) break;
        swap(a, i, j);

        // Move one level down the heap
        i = j;
    }
}

// void join(PQueue pq, Item it) {
//     HeapInsert(pq, it);
// }

// Item leave(PQueue pq) {
//     return HeapDelete(pq);
// }