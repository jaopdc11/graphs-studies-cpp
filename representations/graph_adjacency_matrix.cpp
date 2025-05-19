// graph_adjacency_matrix.cpp
// This file demonstrates how to represent a graph using an adjacency matrix in C++.
// The adjacency matrix is a 2D array where each cell (i, j) indicates the presence (or absence) of an edge between vertices i and j.
// This representation is efficient for dense graphs, but can use a lot of memory for sparse graphs.

#include <iostream>
#include <vector>

using namespace std;

// Graph class using adjacency matrix representation
class Graph {
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<int>> adjacencyMatrix; // 2D vector to store the adjacency matrix

public:
    // Constructor: initializes the graph with a given number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        // Initialize a numVertices x numVertices matrix filled with 0s
        adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    // Adds an edge from vertex 'u' to vertex 'v'
    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        // For undirected graphs, uncomment the next line:
        // adjacencyMatrix[v][u] = 1;
    }

    // Prints the adjacency matrix of the graph
    void printGraph() {
        cout << "Adjacency Matrix Representation:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example: create a graph with 5 vertices
    Graph graph(5);

    // Add some edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency matrix
    graph.printGraph();

    return 0;
}