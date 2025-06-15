#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 23; // Key to search

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}



/*
Algorithm: Binary Search (Recursive Version)

1. Start

2. Define a function `binarySearch(arr[], left, right, key)`:
   a. If `left` is less than or equal to `right`, continue search:
      i.   Calculate mid as: `mid = left + (right - left) / 2`
      ii.  If `arr[mid] == key`, return `mid` (element found).
      iii. If `arr[mid] > key`, search in the left half:
           → Call `binarySearch(arr, left, mid - 1, key)`
      iv.  Else, search in the right half:
           → Call `binarySearch(arr, mid + 1, right, key)`
   b. If `left > right`, return -1 (element not found).

3. In `main()`:
   a. Declare and initialize a sorted array `arr[]`.
   b. Compute size of the array `n`.
   c. Ask the user to enter the element to search (`key`).
   d. Call the `binarySearch(arr, 0, n - 1, key)` function.
   e. If the result is not -1, print the index where the element is found.
   f. Otherwise, print that the element is not found.

4. End
*/

