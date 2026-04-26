#include <stdio.h>

// Function to implement Best Fit algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];        // Array to store remaining capacity of each bin
    int binCount = 0;  // Number of bins used

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++) 
    {
        bin[i] = capacity;
    }

    // Loop through each item
    for (int i = 0; i < n; i++) 
    {
        int bestIndex = -1;        // Stores index of best bin
        int minSpace = capacity + 1;  // To track minimum leftover space

        // Check all existing bins
        for (int j = 0; j < binCount; j++) 
        {
            // If item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If suitable bin is found
        if (bestIndex != -1) 
        {
            bin[bestIndex] -= items[i];  // Reduce remaining space
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        // If no bin fits, create a new bin
        else
        {
            bin[binCount] = capacity - items[i];  // Assign item to new bin
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;  // Increase bin count
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main() 
{
    int n, capacity;

    // Get number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];  // Array to store item sizes

    // Get bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) 
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Check if item fits in bin
        if (itemSize <= capacity) 
        {
            items[i] = itemSize;
        } 
        else 
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--;  // Repeat input for this item
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);

    return 0;  // End of program
}
