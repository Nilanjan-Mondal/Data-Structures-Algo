#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minProduct(vector<int>& arr) {
    int countZero = 0;
    int countPos = 0;
    int countNeg = 0;
    int prod_pos = 1;
    int prod_neg = 1;

    int largestNeg = INT_MIN;

    for(int i=0; i<arr.size(); i++) {

        if(arr[i] == 0) countZero++;
        if(arr[i] < 0) {
            countNeg++;
            prod_neg *= arr[i];
            largestNeg = max(largestNeg, arr[i]);
        }
        if(arr[i] > 0) {
            countPos++;
            prod_pos *= arr[i];
        }
    }
    if(countNeg == 0) {
        if(countZero > 0) return 0;
        else {
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        }
    } else {
        if(countNeg % 2 == 0) {
            return (prod_neg / largestNeg) * prod_pos;
        } else {
            return prod_neg * prod_pos;
        }
    }
}

int main() {
    vector<int> arr {-2, -3, 1, 4, -2};
    cout<<minProduct(arr)<<endl;
}