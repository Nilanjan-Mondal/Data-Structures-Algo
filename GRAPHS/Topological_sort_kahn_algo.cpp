#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // number of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void topoBFS() {

    vector<int> indegree(v, 0);
    for(int i=0; i<v; i++) {
        for(auto neighbour : graph[i]) {
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    unordered_set<int> visited;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            visited.insert(i);
        }
    }

    while(! q.empty()) {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(auto neighbour : graph[curr]) {
            if(visited.find(neighbour) == visited.end()) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}

int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int edges;
    cin>>edges;
    while(edges--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d, false);
    }
    topoBFS(); 
}
