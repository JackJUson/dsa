

// Recursive Selection Sort
// Assumption: 0 <= a <= b < size of arr
int fnA(int arr[], int a, int b) {
    if (a == b) {
        return a;
    }
    int i = fnA(arr, a + 1, b);
    return (arr[a] < arr[i]) ? a : i;
}

// Assumption: 0 <= a <= b < size of arr
void fnB(int arr[], int a, int b) {
    if (a >= b) {
        return;
    }
    int i = fnA(arr, a, b);
    int temp = arr[a];
    arr[a] = arr[i];
    arr[i] = temp;
    fnB(arr, a + 1, b);
}

void fn(int arr[], int size) {
    fnB(arr, 0, size - 1);
}


// Iterative Selection Sort
void selectionSort(int a[], int lo, int hi) {
   int i, j, min;
   for (i = lo; i <= hi-1; i++) {
      min = i;
      for (j = i+1; j <= hi; j++) {
         if (less(a[j],a[min])) min = j;
      }
      swap(a[i], a[min]);
   }
}