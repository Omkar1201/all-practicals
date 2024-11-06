#include <iostream>
using namespace std;

// Recursive Fibonacci function with step counting
int fibonacci_recursive(int n, int &step_count) {
    step_count++; // Increment step count for each function call
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1, step_count) + fibonacci_recursive(n - 2, step_count);
}

// Iterative Fibonacci function with step counting
int fibonacci_iterative(int n, int &step_count) {
    if (n <= 1) return n;

    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        step_count++; // Increment step count for each loop iteration
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci number: ";
    cin >> n;

    int step_count_recursive = 0;
    int step_count_iterative = 0;

    // Recursive method
    int result_recursive = fibonacci_recursive(n, step_count_recursive);
    cout << "Recursive Fibonacci(" << n << ") = " << result_recursive << endl;
    cout << "Steps (Recursive): " << step_count_recursive << endl;

    // Iterative method
    int result_iterative = fibonacci_iterative(n, step_count_iterative);
    cout << "Iterative Fibonacci(" << n << ") = " << result_iterative << endl;
    cout << "Steps (Iterative): " << step_count_iterative << endl;

    return 0;
}
