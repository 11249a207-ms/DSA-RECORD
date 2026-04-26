#include <stdio.h> 
#include <stdlib.h> 
#define V 5 
  
// Helper to find the next vertex to include. 
// It looks for the smallest "key" (weight) among vertices not yet in the MST.
int minKey(int key[], int visited[]) 
{ 
    int min = 999999; 
    int min_index = 0; 
 
    for (int i = 0; i < V; i++) 
    { 
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 
    return min_index; 
} 

// Just a helper to print the final tree and calculate the total weight.
void printPrimMST(int parent[], int graph[V][V]) 
{ 
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 
 
    int total = 0; 
    for (int i = 1; i < V; i++) // Start from 1 because index 0 has no parent
    { 
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        total += graph[i][parent[i]];
    } 
    printf("Total Cost = %d\n", total); 
} 

void primMST(int graph[V][V]) 
{ 
    int parent[V];  // Array to store the final structure of the MST
    int key[V];     // Values used to pick the minimum weight edge in the cut
    int visited[V]; // To keep track of vertices already included in MST

    // Step 1: Initialize everything to "Infinite" and "Unvisited"
    for (int i = 0; i < V; i++) 
    { 
        key[i] = 999999; 
        visited[i] = 0; 
    } 

    // Always start with the first vertex
    key[0] = 0; 
    parent[0] = -1; // Root node of the MST has no parent

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) 
    { 
        // Pick the cheapest edge connecting an unvisited vertex to the current tree
        int u = minKey(key, visited); 

        // Add the picked vertex to the MST set
        visited[u] = 1; 

        // Update the key values of the adjacent vertices
        for (int v = 0; v < V; v++) 
        { 
            /* RELAXATION-LIKE STEP:
               1. graph[u][v] is non-zero (there's an edge)
               2. v is not yet in the MST
               3. The weight of edge u-v is smaller than the current key of v
            */
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 

    // Final output
    printPrimMST(parent, graph); 
} 
 
int main() 
{ 
    // Using an Adjacency Matrix to represent the graph
    int graph[V][V] =
    { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0},
    }; 

    primMST(graph); 

    return 0; 
}
