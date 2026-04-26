#include <stdio.h>

#define V 5   // Number of vertices in the graph

// Function to find an approximate vertex cover
void findVertexCover(int graph[V][V])
{
    int visited[V];  // Array to keep track of selected vertices

    // Initialize all vertices as not visited (0 means not selected)
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Loop through all pairs of vertices
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // If there is an edge between u and v
            // and both vertices are not yet included in the cover
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Select both vertices into the vertex cover
                visited[u] = 1;
                visited[v] = 1;
            }
        }
    }

    printf("Approximate Vertex Cover: ");
    int count = 0;  // To count number of vertices in the cover

    // Print all selected vertices
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
            count++;  // Increase count for each selected vertex
        }
    }

    // Print total number of vertices in the cover
    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n");

    // Call the function to find vertex cover
    findVertexCover(graph);

    return 0;  // End of program
}
