#include <iostream>
using namespace std;

#define MAX 100
#define INF 1000000

int main() {
    // Input parameters
    int V = 5, E = 6;
    int edges[][3] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},
        {3, 4, 1}
    };

    // Initialize adjacency matrix with INF
    int adj[MAX][MAX], dist[MAX], visited[MAX];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            adj[i][j] = (i == j) ? 0 : INF;
        dist[i] = INF;
        visited[i] = 0;
    }

    // Fill adjacency matrix
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][v] = w;
    }

    // Dijkstra's algorithm
    dist[0] = 0; // Source is vertex 0
    for (int count = 0; count < V - 1; count++) {
        int u = -1, minDist = INF;

        // Find the unvisited vertex with the smallest distance
        for (int i = 0; i < V; i++)
            if (!visited[i] && dist[i] < minDist)
                u = i, minDist = dist[i];

        if (u == -1) break; // No more reachable vertices
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++)
            if (!visited[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }

    // Output results
    cout << "Shortest distances from vertex 0:\n";
    for (int i = 0; i < V; i++)
        cout << i << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << "\n";

    return 0;
}
