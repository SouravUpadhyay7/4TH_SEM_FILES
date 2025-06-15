#include <stdio.h>

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;  // Pointer for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // If current element is smaller than pivot
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and pivot (arr[high])
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to implement Quick Sort using Divide and Conquer
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        quickSort(arr, low, pi - 1);  // Recursively sort left subarray
        quickSort(arr, pi + 1, high); // Recursively sort right subarray
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
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
