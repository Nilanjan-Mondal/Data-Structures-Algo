#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
using namespace std;

vector<list<int>> graph;
int v; // number of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) graph[dest].push_back(src);
}

bool bfs(int src, int dest) {
    unordered_set<int> visited; // To keep track of visited nodes
    queue<int> q;              // Queue for BFS

    q.push(src);               // Start BFS from the source
    visited.insert(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == dest) {
            return true;       // Path found
        }

        // Explore neighbors
        for (auto neighbor : graph[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    return false; // No path found
}

bool anyPath(int src, int dest) {
    return bfs(src, dest);
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());
    int edges;
    cin >> edges;
    while (edges--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    int x, y;
    cin >> x >> y;
    cout << anyPath(x, y) << " ";
}
