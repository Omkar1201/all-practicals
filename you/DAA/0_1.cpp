#include <bits/stdc++.h>

using namespace std;

int solve(int capacity, vector<int>& val, vector<int>& wt, int n, vector<vector<int>>& dp) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // Check if result is already computed
    if (dp[n][capacity] != -1) {
        return dp[n][capacity];
    }

    // If the weight of the current item is more than the remaining capacity, skip it
    if (wt[n - 1] > capacity) {
        dp[n][capacity] = solve(capacity, val, wt, n - 1, dp);
    } else {
        // Option to include or exclude the item
        int includeItem = val[n - 1] + solve(capacity - wt[n - 1], val, wt, n - 1, dp);
        int excludeItem = solve(capacity, val, wt, n - 1, dp);
        dp[n][capacity] = max(includeItem, excludeItem);
    }

    return dp[n][capacity];
}

int knapSack(int capacity, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    // Initialize memoization table with -1
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    return solve(capacity, val, wt, n, dp);
}

int main() {
    
    int capacity;
    int n;

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> val(n), wt(n);
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int max_value = knapSack(capacity, val, wt);
    cout << "The maximum value in the knapsack is: " << max_value << endl;

    return 0;
    //Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
    // command to run cpp
    //g++ program.cpp -o program
    //./program


}