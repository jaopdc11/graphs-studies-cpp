// prim_minimum_spanning_tree.cpp
// This file demonstrates Prim's algorithm for finding the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.
// Prim's algorithm grows the MST by always choosing the minimum weight edge that connects a vertex in the MST to a vertex outside the MST.
// This implementation uses an adjacency list and a priority queue (min-heap) for efficiency.

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

// Type alias for better readability
typedef pair<int, int> Edge; // (weight, vertex)

class Graph {
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<Edge>> adjacencyList; // Each vertex has a list of (weight, neighbor) pairs

public:
    // Constructor: initializes the graph with a given number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    // Adds an undirected edge between 'u' and 'v' with a given weight
    void addEdge(int u, int v, int weight) {
        adjacencyList[u].push_back(make_pair(weight, v));
        adjacencyList[v].push_back(make_pair(weight, u));
    }

    // Prim's algorithm to find the Minimum Spanning Tree (MST)
    void primMinimumSpanningTree() {
        vector<int> key(numVertices, numeric_limits<int>::max()); // Minimum weight edge to each vertex
        vector<int> parent(numVertices, -1); // Stores the parent of each vertex in the MST
        vector<bool> inMST(numVertices, false); // Tracks vertices included in MST

        // Min-heap priority queue: (key, vertex)
        priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;

        // Start from vertex 0
        key[0] = 0;
        minHeap.push(make_pair(0, 0));

        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;

            // Explore all neighbors of u
            for (const Edge& neighbor : adjacencyList[u]) {
                int weight = neighbor.first;
                int v = neighbor.second;

                // If v is not in MST and weight is smaller than current key[v]
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    minHeap.push(make_pair(key[v], v));
                }
            }
        }

        // Print the MST
        int totalWeight = 0;
        cout << "Edges in the Minimum Spanning Tree (Prim's Algorithm):" << endl;
        for (int v = 1; v < numVertices; ++v) {
            if (parent[v] != -1) {
                cout << parent[v] << " - " << v << " (weight: " << key[v] << ")" << endl;
                totalWeight += key[v];
            }
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    // Example: create a graph with 5 vertices
    Graph graph(5);

    // Add some undirected, weighted edges
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    // Find the Minimum Spanning Tree using Prim's algorithm
    graph.primMinimumSpanningTree();

    return 0;
}