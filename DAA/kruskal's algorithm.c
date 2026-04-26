#include <stdio.h> 
#define V 5 
#define E 6 

// This array keeps track of who reports to whom.
// It’s basically the backbone of the Disjoint Set Union (DSU) data structure.
int parent[V]; 
 
// The 'Find' operation: it climbs up the family tree until it finds the "boss" (Leader)
int findLeader(int v) 
{ 
    while (parent[v] != v) 
        v = parent[v]; 
    return v; 
} 

// The 'Union' operation: makes one group report to the leader of the other group
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); 
    int b = findLeader(v); 
    parent[a] = b; 
}

// Kruskal's is "Greedy," so we HAVE to sort edges by weight first
void sortEdges(int edges[E][3]) 
{ 
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            if (edges[j][2] > edges[j + 1][2]) 
             { 
                // Swapping the whole edge (u, v, and weight)
                for (int k = 0; k < 3; k++) 
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 
 
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges); 
    
    // Every node starts as its own boss
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
 
    int count = 0, cost = 0; 
    printf("Selected Edges:\n"); 
 
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        int w = edges[i][2]; 

        /* CYCLE CHECK: If the leaders of both nodes are different, 
           it means they aren't connected yet. Adding this edge won't create a loop. */
        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 
            mergeSets(u, v); // Connect them!
            cost += w; 
            count++; 
        }

        // Optimization: An MST always has exactly V-1 edges. If we hit that, we're done.
        if (count == V - 1) 
            break; 
    } 
    printf("Total Cost: %d\n", cost); 
} 
 
int main() 
{ 
    // Edge list format: {Source, Destination, Weight}
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, {1, 3, 3}, {2, 4, 4}, {3, 4, 2}}; 
 
    kruskal(edges); 
    return 0; 
}
