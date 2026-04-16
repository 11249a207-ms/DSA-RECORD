#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF INT_MAX

int n;
int d[MAXN][MAXN];
int dp[MAXN][1 << MAXN];
int g(int i, int s)
{
    if (s == 0)
        return d[i][0];

    if (dp[i][s] != -1)
        return dp[i][s];

    int min_cost = INF;

    for (int k = 0; k < n; k++)
    {
        if (s & (1 << k))
        {
            int cost = d[i][k] + g(k, s & ~(1 << k));

            if (cost < min_cost)
                min_cost = cost;
        }
    }

    return dp[i][s] = min_cost;
}

int main()
{
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (1 << n); s++)
        {
            dp[i][s] = -1;
        }
    }

    int s = 0;
    for (int i = 1; i < n; i++)
    {
        s1= (1 << i);
    }

    printf("S value is: %d\n", s);

    int result = g(0, s);

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
