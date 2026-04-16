#include <stdio.h>

void firstFit(int items[], int n, int capacity) 
{
    int bin[n];
    int binCount = 0;

    printf("\nExecuting First Fit Algorithm\n");
    for (int i = 0; i < n; i++) 
    {
        bin[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        if (items[i] > capacity) 
        {
            printf("Item %d with size %d cannot be placed in any bin\n", i + 1, items[i]);
            continue;
        }

        int placed = 0;
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i]) 
            {
                bin[j] -= items[i];
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break;
            }
        }

        
        if (!placed) 
        {
            bin[binCount] = capacity;
            bin[binCount] -= items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
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

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    firstFit(items, n, capacity);

    return 0;
}
