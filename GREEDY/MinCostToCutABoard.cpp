#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

bool cmp (int x, int y) {
    return x > y;
}

ll minCostToBreakGrid(int n, int m, vector<ll>&vertical, vector<ll>&horizontal) {
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(), cmp);
    int hz = 1;
    int vr = 1;
    int h = 0;
    int v = 0;
    int ans = 0;
    while(h < horizontal.size() && v < vertical.size()) {
        if(horizontal[h] > vertical[v]) {
            ans += horizontal[h]*hz;
            vr++;
            h++;
        } else {
            ans += vertical[v]*vr;
            hz++;
            v++;
        }
    }
    while(h < horizontal.size()) {
        ans += horizontal[h]*hz;
        vr++;
        h++;
    }
    while(h < vertical.size()) {
        ans += vertical[v]*vr;
        hz++;
        v++;
    }
    return ans;
}

int main() {
    int m,n;
    cin>>m>>n;
    vector<ll> horizontal, vertical;

    for(int i=0; i<m-1; i++) {
        int x;
        cin>>x;
        vertical.push_back(x);
    }
    for(int i=0; i<n-1; i++) {
        int x;
        cin>>x;
        horizontal.push_back(x);
    }
    cout<<minCostToBreakGrid(n, m, vertical, horizontal);
}




