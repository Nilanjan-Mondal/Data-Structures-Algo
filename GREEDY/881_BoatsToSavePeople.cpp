#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int left=0;
        int right = people.size()-1;
        int noOfBoats = 0;
        while(left<=right){
            if((people[left]+people[right])<=limit){
                noOfBoats++; // allocate a boat to the pair
                left++;
                right--;
            } else {
                noOfBoats++; // allocate a boat to the heaviest
                right--;
            }
        }
        return noOfBoats;
    }
};