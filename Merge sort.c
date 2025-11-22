AIM:
To write a C program to sort an array of elements using the Merge Sort algorithm, which works on the principle of Divide and Conquer.
ALGORITHM:
Merge Sort Algorithm

Start

If the left index is less than the right index:
a. Find mid = (left + right) / 2
b. Recursively apply mergeSort on left sub-array
c. Recursively apply mergeSort on right sub-array
d. Call merge() to combine both sorted halves
Stop
Merge Algorithm
1.Create temporary array temp[]
2.Use two pointers:
3.i → left sub-array
4.j → right sub-array
5.Compare elements and copy the smaller one into temp[]
6.Copy remaining elements from left or right sub-array
7.Copy temp[] back to original array
PROGRAM:
#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right)
{
    int i = left;        // pointer for left half
    int j = mid + 1;     // pointer for right half
    int k = 0;           // pointer for temp array
    int temp[right - left + 1]; // temporary array

    // Merge smaller elements first
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right half
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy merged data back to original array
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);      // Sort left half
        mergeSort(arr, mid + 1, right); // Sort right half
        merge(arr, left, mid, right);   // Merge sorted halves
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
RESULT:
The Merge Sort program was successfully implemented.
The program correctly divided the array into smaller sub-arrays, sorted them recursively, and merged them into a fully sorted array.
