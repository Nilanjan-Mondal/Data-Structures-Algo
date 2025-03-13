#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>
using namespace std;

vector<list<pair<int, int>>> graph;
vector<int> distArr;
int v;

void add_edge(int src, int dest, int weight, bool bi_dir = true) {
  graph[src].push_back({dest, weight});
  if (bi_dir)
    graph[dest].push_back({src, weight});
}

void dijkstra(int src) {

  set<pair<int, int>> st;

  distArr.assign(v, 1e9);
  distArr[src] = 0;

  st.insert({0, src});

  while (!st.empty()) {

    auto it = *(st.begin());
    int node = it.second;
    int currDist = it.first;
    st.erase(it);

    for (auto &neighbor : graph[node]) {
      int adjNode = neighbor.first;
      int edgeWeight = neighbor.second;

      if (currDist + edgeWeight < distArr[adjNode]) {

        if (distArr[adjNode] != 1e9) {
          st.erase({distArr[adjNode], adjNode});
        }

        distArr[adjNode] = currDist + edgeWeight;
        st.insert({distArr[adjNode], adjNode});
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

  dijkstra(src);

  for (int i = 0; i < v; i++)
    cout << distArr[i] << " ";

  return 0;
}
