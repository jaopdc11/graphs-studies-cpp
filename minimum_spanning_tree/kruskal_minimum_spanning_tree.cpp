// kruskal_minimum_spanning_tree.cpp
// This file demonstrates Kruskal's algorithm for finding the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.
// Kruskal's algorithm sorts all edges by weight and adds them one by one, avoiding cycles, until the MST is complete.
// This implementation uses the Disjoint Set Union (Union-Find) data structure to efficiently detect cycles.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Comparator to sort edges by weight (ascending order)
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (Union-Find) data structure
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    // Initialize n disjoint sets (one for each vertex)
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find the representative (root) of the set containing 'u'
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    // Union the sets containing 'u' and 'v'
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;
        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

// Graph class for Kruskal's algorithm
class Graph {
private:
    int numVertices;
    vector<Edge> edges; // List of all edges

public:
    // Constructor: initializes the graph with a given number of vertices
    Graph(int vertices) : numVertices(vertices) {}

    // Adds an undirected edge between 'u' and 'v' with a given weight
    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(u, v, weight));
    }

    // Kruskal's algorithm to find the Minimum Spanning Tree (MST)
    void kruskalMinimumSpanningTree() {
        // Sort all edges by weight
        sort(edges.begin(), edges.end(), compareEdges);

        DisjointSet ds(numVertices);
        vector<Edge> mst; // Store the edges of the MST
        int totalWeight = 0;

        for (const Edge& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            // If u and v are in different sets, add the edge to the MST
            if (ds.find(u) != ds.find(v)) {
                mst.push_back(edge);
                totalWeight += weight;
                ds.unite(u, v);
            }
        }

        // Print the MST
        cout << "Edges in the Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
        for (const Edge& edge : mst) {
            cout << edge.u << " - " << edge.v << " (weight: " << edge.weight << ")" << endl;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    // Example: create a graph with 5 vertices
    Graph graph(5);

    // Add some undirected, weighted edges
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Find the Minimum Spanning Tree using Kruskal's algorithm
    graph.kruskalMinimumSpanningTree();

    return 0;
}