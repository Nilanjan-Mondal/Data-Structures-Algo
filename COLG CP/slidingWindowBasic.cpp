#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void maxSlidingWindow(vector<int>& arr, int k) {
    priority_queue<pair<int, int>> pq; 
    int n = arr.size();

    for (int i = 0; i < k; i++)
        pq.push({arr[i], i});

    cout << pq.top().first << " ";

    for (int i = k; i < n; i++) {
        pq.push({arr[i], i}); 

        while (!pq.empty() && pq.top().second <= i - k)
            pq.pop();

        cout << pq.top().first << " ";
    }
}

int main() {
    vector<int> arr = {3, -1, 2, -1, 6, 7, 1}; 
    int k = 3;
    maxSlidingWindow(arr, k);
    return 0;
}
