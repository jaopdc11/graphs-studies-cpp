// breadth_first_search.cpp
// This file demonstrates the Breadth-First Search (BFS) algorithm for traversing or searching a graph.
// BFS explores the graph level by level, visiting all neighbors of a vertex before moving to the next level.
// This implementation uses an adjacency list representation for the graph.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph class using adjacency list representation
class Graph {
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<int>> adjacencyList; // Adjacency list

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

    // Performs Breadth-First Search starting from a given source vertex
    void breadthFirstSearch(int startVertex) {
        vector<bool> visited(numVertices, false); // Keeps track of visited vertices
        queue<int> vertexQueue; // Queue for BFS

        // Mark the start vertex as visited and enqueue it
        visited[startVertex] = true;
        vertexQueue.push(startVertex);

        cout << "BFS traversal starting from vertex " << startVertex << ": ";

        while (!vertexQueue.empty()) {
            int currentVertex = vertexQueue.front();
            vertexQueue.pop();
            cout << currentVertex << " ";

            // Visit all unvisited neighbors of the current vertex
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    vertexQueue.push(neighbor);
                }
            }
        }
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

    // Perform BFS starting from vertex 0
    graph.breadthFirstSearch(0);

    return 0;
}