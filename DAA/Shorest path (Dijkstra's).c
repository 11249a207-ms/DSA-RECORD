#include <stdio.h>
#define V 5
#define INF 999999
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
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
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = extractMin(dist, visited);

        if (u == -1)
            break;

        visited[u] = 1;
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] > 0 && !visited[j])
            {
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, dist[i]);
    }
}

int main()
{
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
