#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}




/*
Algorithm: Quick Sort (Divide and Conquer)

1. Choose a pivot element (commonly the last element in the array).

2. Partitioning:
   a. Initialize an index (i) to point to the position before the start of the array.
   b. Traverse the array from 'low' to 'high - 1':
      - If the current element is smaller than the pivot:
        - Increment index i.
        - Swap the current element with the element at index i.
   c. After traversal, place the pivot in its correct sorted position by swapping it with the element at index i+1.
   d. Return the index (i+1) as the partitioning index.

3. Recursively apply Quick Sort to:
   a. Left subarray (from 'low' to 'partition index - 1').
   b. Right subarray (from 'partition index + 1' to 'high').

4. The recursion continues until the base case (low >= high) is reached.
*/
