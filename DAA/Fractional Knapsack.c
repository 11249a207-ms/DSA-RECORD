#include <stdio.h>
struct Item 
{
    int Weight;
    int Value;
    float PPW;
};

// Standard bubble sort to get the best items to the front of the list
void sort(struct Item items[], int n) 
{
    struct Item temp;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            // Sorting in descending order (highest ratio first)
            if (items[j].PPW < items[j + 1].PPW) 
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Just a quick print check to make sure the sorting actually worked
    printf("Items sorted by value/weight ratio:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: Weight = %d, Value = %d, Ratio = %.2f\n", 
                i + 1, items[i].Weight, items[i].Value, items[i].PPW);
    }
}

int main() 
{
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n]; // Array of structs based on the user's count

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].Weight, &items[i].Value);
        // Cast to float here or the division will cut off the decimals!
        items[i].PPW = (float)items[i].Value / items[i].Weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Call the sort before we start picking items
    sort(items, n);

    float totalProfit = 0.0;
    for (int i = 0; i < n; i++) 
    {
        // Case 1: The whole item fits, so just take it all
        if (capacity >= items[i].Weight) 
        {
            totalProfit += items[i].Value;
            capacity -= items[i].Weight;
        } 
        // Case 2: We can't fit the whole thing, so take a "slice" (Fractional Knapsack)
        else
        {
            // Remaining capacity * value per unit of weight
            totalProfit += items[i].PPW * capacity;
            capacity = 0; // Bag is full, we're done here
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
