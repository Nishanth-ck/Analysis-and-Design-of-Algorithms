#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
    return ((a > b) ? a : b);
}

int knapsack(int n,int values[],int weights[],int W)
{
    int i,w;
    int K[n+1][W+1];

    for (i = 0; i <= n;i++)
    {
        for (w = 0; w <= W;w++)
        {
            if(i==0 || w==0)
            {
                K[i][w] = 0;
            }

            else if(weights[i-1] <= w)
            {
                K[i][w] = max(K[i - 1][w], K[i - 1][w - weights[i - 1]] + values[i - 1]);
            }

            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return (K[n][W]);
}

int main()
{
    int i, n, W;

    printf("\nEnter the number of items (value of n) : \n");
    scanf("%d",&n);

    int values[n],weights[n];

    printf("\nEnter the item's profits and weights in the order:\n");

    for (i = 0;i<n;i++)
    {
        printf("\nEnter the %d item's profit :\n",i+1);
        scanf("%d", &values[i]);
        printf("\nEnter the %d item's weight :\n",i+1);
        scanf("%d", &weights[i]);
    }

    printf("\nEnter the capacity of the knapsack:\n");
    scanf("%d",&W);

    printf("\nThe maximum amount of profit that can be obtained using the 0/1 Knapsack dynamic programming method is : %d\n", knapsack(n, values, weights, W));

    return 0;
    
}