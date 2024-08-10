#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // number of vertices
unordered_set<int> visited;
vector<vector<int>>result;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void dfs(int curr, int end, vector<int>& path){
    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // mark visited
    path.push_back(curr);
    for(auto neighbours : graph[curr]) {
        if(visited.find(neighbours) == visited.end()){
            dfs(neighbours,end,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int src, int dest){
    vector<int> v;
    dfs(src, dest, v);
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
    allPath(x,y);
    for(auto path : result){
        for(auto ele : path){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
