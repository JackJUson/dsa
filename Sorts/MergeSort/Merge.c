// Optimized implementation of Merge Sort
#include <stdio.h>
#include <stdbool.h>

// Merge Sort: Stable Non-Adapative O(n log n)
// Space complexity O(n)

// Merge the two subarrays into one in order
void merge(int array[], int low, int middle, int high) {
    int *temp = malloc((high - low + 1) * sizeof(int));

    int i = low;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= high) {
        if (array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    // Copy items from unfinished segment
    while (i <= mid) temp[k++] = array[i++];
    while (j <= high) temp[k++] = array[j++];

    // Copy temp back to main array
    for (i = low, k = 0; i <= high; i++, k++) {
        array[i] = temp[k];
    }
    free(temp);
}


// Divide the array into two subarrays, sort them and merge them
void mergeSort(int array[], int low, int high) {
    if (low < high) {

        // middle is the point where the array is divided into two subarrays
        int middle = (low + high) / 2;

        mergeSort(array, low, middle);
        mergeSort(array, middle + 1, high);

        // Merge the sorted subarrays
        merge(array, low, middle, high);
    }
}


// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);
}