#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freqMap;
        priority_queue<pair<char, int>> pq;
        for(auto ele : s) freqMap[ele]++;
        for(auto ele : freqMap) pq.push(ele);
        string result = "";
        while(!pq.empty()) {
            auto largest = pq.top();
            pq.pop();
            int len = min(repeatLimit, largest.second);
            for(int i=0; i<len; i++) {
                result += largest.first;
            }
            pair<char, int> secondLargest;
            if(largest.second - len > 0) {
                if(!pq.empty()) {
                    secondLargest = pq.top();
                    pq.pop();
                    result += secondLargest.first;
                } else {
                    return result;
                }
                if(secondLargest.second - 1 > 0) {
                    pq.push({secondLargest.first, secondLargest.second - 1});
                }
                pq.push({largest.first, largest.second - len});
            }
        }
        return result;
    }
};