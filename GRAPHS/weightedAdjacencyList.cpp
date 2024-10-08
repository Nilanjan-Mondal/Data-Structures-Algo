#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<pair<int,int>>> graph;
int v; // number of vertices

void add_edge(int src, int dest, int wt, bool bi_dir = true){
    graph[src].push_back({dest,wt});
    if(bi_dir) graph[dest].push_back({src,wt});
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<"("<<ele.first<<" "<<ele.second<<"), ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v, list<pair<int,int>>());
    int edges;
    cin>>edges;
    while(edges--){
        int s,d,w;
        cin>>s>>d>>w;
        add_edge(s,d,w);
    }
    display();
}
