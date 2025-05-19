// dijkstra_shortest_path.cpp
// This file demonstrates Dijkstra's algorithm for finding the shortest path from a source vertex to all other vertices in a weighted graph.
// Dijkstra's algorithm works only with non-negative edge weights.
// This implementation uses an adjacency list and a priority queue (min-heap) for efficiency.

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

// Type alias for better readability
typedef pair<int, int> Edge; // (neighbor, weight)

class Graph {
private:
    int numVertices; // Number of vertices in the graph
    vector<vector<Edge>> adjacencyList; // Adjacency list: each vertex has a list of (neighbor, weight) pairs

public:
    // Constructor: initializes the graph with a given number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    // Adds a directed edge from vertex 'u' to vertex 'v' with a given weight
    void addEdge(int u, int v, int weight) {
        adjacencyList[u].push_back(make_pair(v, weight));
        // For undirected graphs, uncomment the next line:
        // adjacencyList[v].push_back(make_pair(u, weight));
    }

    // Dijkstra's algorithm to find shortest paths from a source vertex
    void dijkstraShortestPath(int source) {
        // Vector to store the shortest distance from source to each vertex
        vector<int> distance(numVertices, numeric_limits<int>::max());
        distance[source] = 0;

        // Min-heap priority queue: (distance, vertex)
        priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
        minHeap.push(make_pair(0, source));

        while (!minHeap.empty()) {
            int currentDistance = minHeap.top().first;
            int currentVertex = minHeap.top().second;
            minHeap.pop();

            // If we have already found a better path, skip
            if (currentDistance > distance[currentVertex]) {
                continue;
            }

            // Explore all neighbors of the current vertex
            for (const Edge& neighbor : adjacencyList[currentVertex]) {
                int nextVertex = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path to nextVertex is found
                if (distance[nextVertex] > distance[currentVertex] + weight) {
                    distance[nextVertex] = distance[currentVertex] + weight;
                    minHeap.push(make_pair(distance[nextVertex], nextVertex));
                }
            }
        }

        // Print the shortest distances from the source to all vertices
        cout << "Shortest distances from vertex " << source << ":" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ": ";
            if (distance[i] == numeric_limits<int>::max()) {
                cout << "unreachable";
            } else {
                cout << distance[i];
            }
            cout << endl;
        }
    }
};

int main() {
    // Example: create a graph with 5 vertices
    Graph graph(5);

    // Add some weighted edges
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 4, 2);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 0, 7);
    graph.addEdge(3, 2, 6);
    graph.addEdge(4, 1, 3);
    graph.addEdge(4, 2, 9);
    graph.addEdge(4, 3, 2);

    // Find shortest paths from vertex 0
    graph.dijkstraShortestPath(0);

    return 0;
}