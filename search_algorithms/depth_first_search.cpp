// depth_first_search.cpp
// This file demonstrates the Depth-First Search (DFS) algorithm for traversing or searching a graph.
// DFS explores as far as possible along each branch before backtracking.
// This implementation uses an adjacency list representation for the graph.

#include <iostream>
#include <vector>

using namespace std;

// Graph class using adjacency list representation
class Graph {
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<int>> adjacencyList; // Adjacency list

    // Helper function for recursive DFS
    void dfsRecursive(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        // Visit all unvisited neighbors of the current vertex
        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

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

    // Performs Depth-First Search starting from a given source vertex
    void depthFirstSearch(int startVertex) {
        vector<bool> visited(numVertices, false); // Keeps track of visited vertices
        cout << "DFS traversal starting from vertex " << startVertex << ": ";
        dfsRecursive(startVertex, visited);
        cout << endl;
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

    // Perform DFS starting from vertex 0
    graph.depthFirstSearch(0);

    return 0;
}