#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

vector<list<pair<int, int>>> graph;
int v;
int totalSum = 0;

void add_edge(int src, int dest, int weight, bool bi_dir = true) {
  graph[src].push_back({dest, weight});
  if (bi_dir)
    graph[dest].push_back({src, weight});
}

void prims(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  unordered_set<int> visited(v);

  pq.push({0, src});

  while (!pq.empty()) {
    int node = pq.top().second;
    int wt = pq.top().first;
    pq.pop();

    if (visited.find(node) == visited.end()) {
      totalSum += wt;
      visited.insert(node);
    } else
      continue;

    for (auto &neighbor : graph[node]) {
      if (visited.find(neighbor.first) == visited.end()) {
        int adjNode = neighbor.first;
        int adjWt = neighbor.second;
        pq.push({adjWt, adjNode});
      }
    }
  }
}

int main() {
  cin >> v;
  graph.resize(v);

  int edges;
  cin >> edges;
  while (edges--) {
    int s, d, w;
    cin >> s >> d >> w;
    add_edge(s, d, w);
  }

  int src;
  cin >> src;

  prims(src);

  cout << totalSum << ".....";

  return 0;
}
