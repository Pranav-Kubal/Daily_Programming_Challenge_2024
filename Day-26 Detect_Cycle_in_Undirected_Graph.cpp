#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Graph class to represent an undirected graph
class Graph {
public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) : V(V) {
        adjList.resize(V);
    }
    // Function to add an edge between vertices u and v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    bool hasCycle() {
        vector<bool> visited(V, false);

        // Check for cycles in each component of the graph
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

    // Helper function for DFS traversal
    bool dfs(int v, vector<bool>& visited, int parent) {
        visited[v] = true;
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, v)) {
                    return true; // Cycle detected in recursion
                }
            } else if (neighbor != parent) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle found
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V); // Create a graph with V vertices 

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.hasCycle()) {
        cout << "Output: true" << endl; // Cycle exists
    } else {
        cout << "Output: false" << endl; // Cycle doesn't exists
    }

    return 0;
}
