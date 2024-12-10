#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

vector<list<int>> graph; // Adjacency list
int v; // Number of vertices

// Function to add edges to the adjacency list
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) graph[dest].push_back(src);
}

// Function to find the shortest path using BFS
vector<int> shortestPath(int src) {
    // Distance array initialized to a very large value
    vector<int> dist(v, 1e9);
    dist[src] = 0;

    // BFS initialization
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Explore all neighbors
        for (auto neighbor : graph[curr]) {
            if (dist[curr] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    // Prepare the result array
    vector<int> result(v, -1);
    for (int i = 0; i < v; i++) {
        if (dist[i] != 1e9) {
            result[i] = dist[i];
        }
    }

    return result;
}

int main() {
    cin >> v;
    graph.resize(v);

    int edges_count, src;
    cin >> edges_count >> src;

    // Input edges using add_edge
    while (edges_count--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    vector<int> result = shortestPath(src);

    // Print result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
