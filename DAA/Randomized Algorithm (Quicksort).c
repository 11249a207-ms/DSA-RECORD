#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This is where the magic happens. We pick a pivot and move everything 
   smaller to the left and everything bigger to the right.
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Using the last element as the pivot
    int i = (low - 1);     // Index of the "smaller element" area

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than the pivot, move it to the 'left' side
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Put the pivot in its final correct spot (between the small and large numbers)
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return the position of the pivot
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* RANDOMIZATION: This prevents the "Worst Case" (like O(n²) on already sorted lists).
           We pick a random spot, swap it with the end, then treat it like a normal pivot.
        */
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[high]);

        // pi is Partition Index
        int pi = partition(arr, low, high);

        // Recursively sort the left half and the right half
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    // Seed the random number generator so we get different results every run
    srand(time(NULL));

    printf("Enter number of elements: ");
    // Good practice: Checking if scanf actually got a number
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbersToSort[i]);
    }

    // Start the recursive sorting
    quickSort(numbersToSort, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbersToSort[i]);
    }

    return 0;
}
