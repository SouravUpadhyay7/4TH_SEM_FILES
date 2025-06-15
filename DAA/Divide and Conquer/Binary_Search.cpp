#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key)
            return mid;

        // If the key is smaller, search in the left subarray
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        // Otherwise, search in the right subarray
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 18, 20, 25}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
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
