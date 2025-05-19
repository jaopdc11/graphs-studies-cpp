// graph_adjacency_list.cpp
// This file demonstrates how to represent a graph using an adjacency list in C++.
// The adjacency list is a common and efficient way to store sparse graphs.
// Each vertex has a list of its adjacent vertices.

#include <iostream>
#include <vector>

using namespace std;

// Graph class using adjacency list representation
class Graph {
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<int>> adjacencyList; // Vector of vectors to store adjacency list

public:
    // Constructor: initializes the graph with a given number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    // Adds an edge from vertex 'u' to vertex 'v'
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        // For undirected graphs, uncomment the next line:
        // adjacencyList[v].push_back(u);
    }

    // Prints the adjacency list of the graph
    void printGraph() {
        cout << "Adjacency List Representation:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
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

    // Print the adjacency list
    graph.printGraph();

    return 0;
}