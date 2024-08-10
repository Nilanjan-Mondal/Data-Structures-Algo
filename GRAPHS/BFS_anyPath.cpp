#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // number of vertices
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

bool dfs(int curr, int end){
    if(curr == end) return true;
    visited.insert(curr); // mark visited
    for(auto neighbours : graph[curr]) {
        if(visited.find(neighbours) == visited.end()){
            bool result = dfs(neighbours,end);
            if(result) return true;
        }
    }
    return false;
} 

bool anyPath(int src, int dest){
    return dfs(src, dest);
}

int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int edges;
    cin>>edges;
    while(edges--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<" ";
}
