#include <iostream>
#include <vector>
# define ll long long int
using namespace std;

int Find(vector<int>& parent, int x) {
    // TC = log*n
    return (parent[x] == x) ? x : Find(parent, parent[x]);

}

void Union(vector<int>& parent, vector<int>& rank, int a, int b) {

    // TC = log*n
    a = Find(parent, a);
    b = Find(parent, b);

    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }
}

struct Edge {
    int src;
    int dest;
    int wt;
};

bool cmp (Edge a, Edge b) {
    return a.wt < b.wt;
}

ll kruskals(vector<Edge>& input, int n, int e) {
    sort(input.begin(), input.end(), cmp);
    vector<int> parent(n+1);
    vector<int> rank(n+1, 1);
    for(int i=0; i<=n; i++) { 
        parent[i] = i;
    }
    int edgeCount = 0;
    int i = 0;
    ll ans = 0;
    while(edgeCount < n-1 and i < input.size()) { 
        // in a spanning tree of a graph with n vertices, there will be n-1 edges
        Edge curr = input[i];
        int srcParent = Find(parent, curr.src);
        int destParent = Find(parent, curr.dest);
        if(srcParent != destParent) {
            // include edge as this will not  make cycle
            Union(parent, rank, srcParent, destParent);
            ans += curr.wt;
            edgeCount++;
        }
        i++; // doesnt matter if we include the last edge or not, we still need to go to the next edge
    }
    return ans;
}

int main() {

    int v, e; // v = number of vertices, m = number of edges
    cin>>v>>e;
    vector<Edge> Edges(e);

    for(int i=0; i<e; i++) {
        int src, dest, wt;
        cin>>src>>dest>>wt;
        Edges[i].src = src;
        Edges[i].dest = dest;
        Edges[i].wt = wt;
    }
    cout<< kruskals(Edges, v, e);

}