AIM:
To write a C program to sort a list of elements using the Quick Sort algorithm, which follows the divide-and-conquer approach and sorts an array efficiently by selecting a pivot and partitioning the elements.
ALGORITHM:
Step-1: Start
Step-2: Read the number of elements n.
Step-3: Input the array elements.
Step-4: Call quickSort(arr, 0, n−1)
   Inside Quick Sort:
If low < high
Find pivot position using partition()
Recursively apply Quick Sort to
Left subarray (low to pivot−1)
Right subarray (pivot+1 to high)
Step-5: partition() function:
Choose the last element as pivot
Arrange elements smaller than pivot to the left
Arrange larger elements to the right
Return final pivot index
Step-6: Print the sorted array
Step-7: Stop
PROGRAM:
#include <stdio.h>

// Function to swap two numbers using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function: places pivot at correct position
// and arranges smaller elements to the left, larger to the right
int partition(int list[], int low, int high)
{
    int pivot = list[high];  // choosing last element as pivot
    int i = low - 1;         // index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than the pivot
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]); // swap elements
        }
    }

    // Place pivot in correct sorted position
    swap(&list[i + 1], &list[high]);

    return (i + 1); // return pivot position
}

// Recursive Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high); // get pivot index

        // Recursively sort elements before and after pivot
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    // Call Quick Sort
    quickSort(list, 0, n - 1);

    // Print sorted array
    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
RESULT:
The program to sort the given list of numbers using the Quick Sort technique was successfully executed.
The elements entered by the user were processed using the partitioning method based on a pivot element, and the array was recursively divided into smaller subarrays.
After applying the Quick Sort algorithm, the final output displayed the elements in ascending sorted order.
