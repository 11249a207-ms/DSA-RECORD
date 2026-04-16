#include <stdio.h>
struct Item 
{
    int Weight;
    int Value;
    float PPW; // Profit Per Weight
};

void sort(struct Item items[], int n) 
{
    struct Item temp;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (items[j].PPW < items[j + 1].PPW) 
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

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

    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].Weight, &items[i].Value);
        items[i].PPW = (float)items[i].Value / items[i].Weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    sort(items, n);

    float totalProfit = 0.0;
    for (int i = 0; i < n; i++) 
    {
        if (capacity >= items[i].Weight) 
        {
      
            totalProfit += items[i].Value;
            capacity -= items[i].Weight;
        } 
        else
        {
          
            totalProfit += items[i].PPW * capacity;
            capacity = 0; // Knapsack is now full
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
