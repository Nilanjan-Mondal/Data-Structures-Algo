
#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack problem using memoization
int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W,
                 vector<vector<int>> &dp) {

  if (ind == 0) {
    return (wt[0] <= W) ? val[0] : 0;
  }


  // If the result for this state is already calculated, return it
  if (dp[ind][W] != -1) {
    return dp[ind][W];
  }

  // Calculate the maximum value by either excluding the current item or
  // including it
  int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
  int taken = 0;

  // Check if the current item can be included without exceeding the knapsack's
  // capacity
  if (wt[ind] <= W) {
    taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);
  }

  // Store the result in the DP table and return
  return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int> &wt, vector<int> &val, int n, int W) {
  vector<vector<int>> dp(n, vector<int>(W + 1, -1));
  return knapsackUtil(wt, val, n - 1, W, dp);
}

int main() {
  vector<int> wt = {25,35,15,10};
  vector<int> val = {100,58,75,20};
  int W = 50;
  int n = wt.size();

  cout << "The Maximum value of items the thief can steal is "
       << knapsack(wt, val, n, W);

  return 0;
}
