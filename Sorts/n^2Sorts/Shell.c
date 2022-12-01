// Optimized implementation of Shell sort
#include <stdio.h>
#include <stdbool.h>

// Shell Sort: Non-Stable Adapative O(n log n) and worst case O(n^2)

/* Pseudocode
    shellSort(array, size)
    for interval i <- size/2n down to 1
        for each interval "i" in array
            sort all the elements at interval "i"
    end shellSort
*/

// Shell sort
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}