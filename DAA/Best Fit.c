#include <stdio.h>

void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];
    int binCount = 0;

    for (int i = 0; i < n; i++) 
    {
        bin[i] = capacity;
    }

    for (int i = 0; i < n; i++) 
    {
        int bestIndex = -1;
        int minSpace = capacity + 1;
      
        for (int j = 0; j < binCount; j++) 
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If a best bin was found, place the item in it
        if (bestIndex != -1) 
        {
            bin[bestIndex] -= items[i];
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        // Otherwise, open a new bin
        else
        {
            bin[binCount] = capacity - items[i];
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Total bins used = %d\n", binCount);
}

int main() 
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) 
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        if (itemSize <= capacity) 
        {
            items[i] = itemSize;
        } else 
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--;
        }
    }

    bestFit(items, n, capacity);

    return 0;
}
