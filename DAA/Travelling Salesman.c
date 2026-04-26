#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF INT_MAX

int n;
int d[MAXN][MAXN]; // The distance matrix between cities
int dp[MAXN][1 << MAXN]; // DP Table: [current_city][mask_of_visited_cities]

/* The recursive function 'g' stands for "Going through the remaining cities".
   'i' is where we are now.
   's' is a bitmask representing the set of cities we still need to visit.
*/
int g(int i, int s)
{
    // Base Case: If the set 's' is empty, we must go back to the start (city 0)
    if (s == 0)
        return d[i][0];

    // Memoization: If we've already solved this sub-problem, just return it
    if (dp[i][s] != -1)
        return dp[i][s];

    int min_cost = INF;

    // Try visiting every city 'k' that is still in our "to-visit" set 's'
    for (int k = 0; k < n; k++)
    {
        // This bitwise AND checks if the k-th bit is '1' (meaning city k is in set s)
        if (s & (1 << k))
        {
            /* The cost is: (Distance to k) + (Best way to visit everything else)
               's & ~(1 << k)' is a bitwise trick to "flip" the k-th bit to 0.
            */
            int cost = d[i][k] + g(k, s & ~(1 << k));

            if (cost < min_cost)
                min_cost = cost;
        }
    }

    // Save and return the best result for this state
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

    // Initialize DP table with -1 (meaning "unsolved")
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (1 << n); s++)
        {
            dp[i][s] = -1;
        }
    }

    /* We want to visit all cities except the starting one (city 0).
       If n=4, we want cities 1, 2, and 3.
       The mask would be 1110 in binary.
    */
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        s |= (1 << i); // Using OR to build the mask of cities to visit
    }

    printf("S value (mask) is: %d\n", s);

    // Start at city 0, with 's' cities left to visit
    int result = g(0, s);

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
