#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}



/*
Algorithm: Merge Sort (Divide and Conquer)

1. If the array has more than one element:
   a. Divide the array into two halves:
      - Find the middle point (mid = (left + right) / 2).
   b. Recursively apply merge sort to the left half.
   c. Recursively apply merge sort to the right half.
   d. Merge the two sorted halves into a single sorted array.

2. Merge Function:
   a. Create two temporary arrays for left and right subarrays.
   b. Copy data into these temporary arrays.
   c. Compare elements from both arrays and copy the smaller one back to the original array.
   d. Copy any remaining elements from the left or right temporary arrays.

3. This continues recursively until the whole array is sorted.
*/

