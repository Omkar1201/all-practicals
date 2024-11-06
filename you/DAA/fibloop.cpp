#include <iostream>
using namespace std;

int loopFib(int n, int &stepCount) {
    if (n <= 1) {
        stepCount++;  // Only one step if n is 0 or 1
        return n;
    }

    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
        stepCount++; // Increment step count for each loop iteration
    }
    return fib;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int loopSteps = 0;
    int fibLoop = loopFib(n, loopSteps);
    cout << "Loop Fibonacci(" << n << ") = " << fibLoop << " with " 
    << loopSteps << " steps." << endl;

    return 0;
}