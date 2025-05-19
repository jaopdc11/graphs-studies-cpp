// graph_example_generator.cpp
// This file provides utility functions to generate random or custom graphs for testing purposes.
// You can use this to quickly create graphs with a specified number of vertices and edges.

#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <set>

using namespace std;

// Structure to represent an edge with weight
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Function to generate a random undirected weighted graph
vector<Edge> generateRandomGraph(int numVertices, int numEdges, int maxWeight = 10) {
    set<pair<int, int>> existingEdges; // To avoid duplicate edges
    vector<Edge> edges;
    srand(time(0)); // Seed for randomness

    while ((int)edges.size() < numEdges) {
        int u = rand() % numVertices;
        int v = rand() % numVertices;
        if (u == v) continue; // No self-loops

        // Ensure each undirected edge is only added once
        pair<int, int> edge = (u < v) ? make_pair(u, v) : make_pair(v, u);
        if (existingEdges.count(edge)) continue;

        int weight = 1 + rand() % maxWeight; // Weight between 1 and maxWeight
        edges.push_back(Edge(u, v, weight));
        existingEdges.insert(edge);
    }
    return edges;
}

// Function to print the generated edges
void printEdges(const vector<Edge>& edges) {
    cout << "Generated edges (u, v, weight):" << endl;
    for (const Edge& edge : edges) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }
}

int main() {
    int numVertices = 5;
    int numEdges = 7;
    int maxWeight = 10;

    // Generate a random graph
    vector<Edge> edges = generateRandomGraph(numVertices, numEdges, maxWeight);

    // Print the generated edges
    printEdges(edges);

    // You can now use these edges to build a graph in your other algorithms
    return 0;
}