#include <stdio.h>

// V is the number of vertices (nodes) in our graph
#define V 5
// INF is a "huge" number representing that we haven't found a path yet
#define INF 999999

// This helper function finds the node with the shortest distance that we haven't visited yet
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        // If it's not visited and its distance is smaller than our current min
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V])
{
    int dist[V], visited[V];

    // Initialization: set all distances to "infinity" and mark all as unvisited
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance to the starting point (source) is always 0
    dist[0] = 0;

    for (int count = 0; count < V; count++)
    {
        // Pick the "closest" node from the set of unvisited nodes
        int u = extractMin(dist, visited);

        // If we can't find a node, something's wrong or we're done
        if (u == -1)
            break;

        // Mark this node as "done" so we don't re-process it
        visited[u] = 1;

        // Check all neighbors of the current node 'u'
        for (int j = 0; j < V; j++)
        {
            /* Relax the edge:
               1. graph[u][j] > 0 means there's actually a path
               2. !visited[j] means we haven't finalized the neighbor yet
               3. dist[u] + graph[u][j] is the NEW possible distance to j
            */
            if (graph[u][j] > 0 && !visited[j])
            {
                // If the new path is shorter than the old one we knew, update it!
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Print the final leaderboard of shortest distances
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, dist[i]);
    }
}

int main()
{
    // Our map: 0 means no direct road, other numbers are the "cost" or "length"
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph);

    return 0;
}
