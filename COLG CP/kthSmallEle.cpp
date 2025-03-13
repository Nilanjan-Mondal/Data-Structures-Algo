#include <iostream>
#include <queue>
using namespace std;

int main() {
  vector<int> arr = {2, 3, 1, 20, 15};

  priority_queue<int> pq;

  int k = 4;

  for (auto ele : arr) {

    pq.push(ele);
    if (pq.size() > k)
      pq.pop();
  }

  cout << pq.top();
}
