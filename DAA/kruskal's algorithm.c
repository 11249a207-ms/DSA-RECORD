#include <stdio.h> 
#define V 5 
#define E 6 
int parent[V]; 
 
int findLeader(int v) 
{ 
    while (parent[v] != v) 
        v = parent[v]; 
    return v; 
} 
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); 
    int b = findLeader(v); 
    parent[a] = b; 
}
void sortEdges(int edges[E][3]) 
{ 
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            if (edges[j][2] > edges[j + 1][2]) 
             { 
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
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
 
    int count = 0, cost = 0; 
    printf("Selected Edges:\n"); 
 
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        int w = edges[i][2]; 

        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 
            mergeSets(u, v); 
            cost += w; 
            count++; 
        }
        if (count == V - 1) 
            break; 
    } 
    printf("Total Cost: %d\n", cost); 
} 
 
int main() 
{ 
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, {1, 3, 3}, {2, 4, 4}, {3, 4, 2}}; 
 
    kruskal(edges); 
    return 0; 
}
