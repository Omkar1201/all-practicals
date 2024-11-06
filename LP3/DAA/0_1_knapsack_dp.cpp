#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack problem using Recursion with Memoization
int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n, vector<vector<int>>& memo) {
    // Base case: If no items or no capacity left
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // Check if the value is already computed
    if (memo[n][capacity] != -1) {
        return memo[n][capacity];
    }

    // If the weight of the current item is more than the capacity, skip it
    if (weights[n - 1] > capacity) {
        memo[n][capacity] = knapsack(capacity, weights, values, n - 1, memo);
    } else {
        // Choice: include the item or skip it
        int includeItem = values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1, memo);
        int excludeItem = knapsack(capacity, weights, values, n - 1, memo);

        // Store the maximum of including or excluding the item in the memoization table
        memo[n][capacity] = max(includeItem, excludeItem);
    }

    return memo[n][capacity];
}

int main() {
    int capacity; // Maximum capacity of the knapsack
    int n;        // Number of items

    // Input: number of items and capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Initialize a memoization table with -1 (indicating uncomputed values)
    vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1));

    // Calculate the maximum value for the knapsack problem
    int max_value = knapsack(capacity, weights, values, n, memo);
    cout << "The maximum value in the knapsack is: " << max_value << endl;

    return 0;
}