#include <iostream>
#include <vector>

using namespace std;

// Recursive Fibonacci with step counter
int recursiveFib(int n, int &stepCount) {
    stepCount++; // Increment the step count for each function call
    if (n <= 1) {
        return n;
    }
    return recursiveFib(n - 1, stepCount) + recursiveFib(n - 2, stepCount);
}

// Dynamic programming Fibonacci with step counter (using memoization)
int dpFib(int n, int &stepCount) {
    vector<int> fib(n + 1, 0); // Memoization array
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        stepCount++; // Increment the step count for each loop iteration
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Calculate Fibonacci number using recursion and count steps
    int recursiveSteps = 0;
    int fibRecursive = recursiveFib(n, recursiveSteps);
    cout << "Recursive Fibonacci(" << n << ") = " << fibRecursive 
    << " with " << recursiveSteps << " steps." << endl;

    // Calculate Fibonacci number using dynamic programming and count steps
    int dpSteps = 0;
    int fibDP = dpFib(n, dpSteps);
    cout << "DP Fibonacci(" << n << ") = " << fibDP 
    << " with " << dpSteps << " steps." << endl;

    return 0;
}