#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int result = 0;
        for(int i=0; i<answers.size(); i++) {
            if(mp.find(answers[i]+1) == mp.end()) {
                result += answers[i]+1;
                if(answers[i] == 0) continue;
                mp[answers[i]+1] = 1;
            }
            else {
                mp[answers[i]+1]++;
                int key = answers[i]+1;
                int val = mp[key];
                if(key == val) mp.erase(key);
            }
        }
        return result;
    }
};