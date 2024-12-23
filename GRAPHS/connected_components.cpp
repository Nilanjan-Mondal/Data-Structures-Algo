#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
using namespace std;

vector<list<int>> graph;
int v; // number of vertices
unordered_set<int>visited;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) graph[dest].push_back(src);
}

void dfs(int curr) {
    visited.insert(curr);
    for(auto neighbours : graph[curr]) {
        if(visited.find(neighbours) == visited.end()) {
            dfs(neighbours);
        }
    }
}

int connected_components() {
    int result = 0;
    for(int i=0; i<v; i++) {
        if(visited.find(i) == visited.end()) {
            result++;
            dfs(i);
        }
    }
    return result;
}


int main() {
    cin >> v;
    graph.resize(v, list<int>());
    int edges;
    cin >> edges;
    while (edges--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d, false);
    }
    cout << connected_components() <<"\n";
}
