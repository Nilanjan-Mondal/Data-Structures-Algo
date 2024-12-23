#include <iostream>
#include <vector>
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



int main() {

    int n, m; // n = number of elements, m = number of queries
    cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }

    while(m--) {
        string str;
        cin>>str;
        if(str == "union") {
            int x, y;
            cin>>x>>y;
            Union(parent, rank, x, y);
        } else {
            int x;
            cin>>x;
            cout<<Find(parent, x)<<"\n";
        }
    }

}