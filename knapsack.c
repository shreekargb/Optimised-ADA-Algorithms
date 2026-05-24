#include <stdio.h>

void fractionalKnapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20];      // stores fraction of items taken
    float totalProfit = 0;
    int i;
    float remaining = capacity;

    // Initially take nothing
    for(i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    // Take items one by one
    for(i = 0; i < n; i++)
    {
        // If whole item can fit
        if(weight[i] <= remaining)
        {
            x[i] = 1.0;

            totalProfit += profit[i];

            remaining -= weight[i];
        }
        else
        {
            // Take fraction of item
            x[i] = remaining / weight[i];

            totalProfit += x[i] * profit[i];

            break;
        }
    }

    // Print result
    printf("\nFractions taken:\n");

    for(i = 0; i < n; i++)
    {
        printf("Item %d = %.2f\n", i + 1, x[i]);
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);
}

int main()
{
    int n, i, j;

    float weight[20];
    float profit[20];
    float ratio[20];
    float capacity;
    float temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Calculate profit/weight ratio
    for(i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items based on ratio (descending)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // Swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    fractionalKnapsack(n, weight, profit, capacity);

    return 0;
}