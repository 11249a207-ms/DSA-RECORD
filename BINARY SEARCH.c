AIM:
To write and execute a program that searches for a given element in a sorted array using the Binary Search technique.
ALGORITHM:
Step 1: Start
Step 2: Input the number of elements n
Step 3: Input the sorted array elements A[0] to A[n-1]
Step 4: Input the element to search, called key
Step 5: Initialize:
  low = 0
  high = n - 1
Step 6: Repeat Steps 7–10 while low <= high
Step 7: Calculate mid = (low + high) / 2
Step 8: If A[mid] == key, print "Element found at position mid" and go to Step 11
Step 9: If A[mid] < key, set low = mid + 1
Step 10: Else, set high = mid - 1
Step 11: If low > high, print "Element not found"
Step 12: Stop
PROGRAM:
#include <stdio.h>

int main() {
    int n, key, low, high, mid;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    // Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input the key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    // Binary search begins
    while (low <= high) {
        mid = (low + high) / 2;

        // If key is found at mid
        if (a[mid] == key) {
            printf("Element found at position %d\n", mid);
            return 0;
        }
        // If key is greater, ignore left half
        else if (a[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }

    // If key is not found
    printf("Element not found\n");

    return 0;
}
RESULT:
The Binary Search algorithm is successfully implemented.
The program efficiently searches a sorted array and correctly displays whether the element is found or not, along with its position.
