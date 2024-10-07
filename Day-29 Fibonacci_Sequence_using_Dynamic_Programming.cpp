#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<long long> fib(n + 1);
    fib[0] = 0; // first number
    fib[1] = 1; // second number

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n]; 
}

int main() {
    int n;
    cout << "Enter an integer n (0-1000): ";
    cin >> n;

    if (n < 0 || n > 1000) {
        cout << "Input out of range. Please enter a value between 0 and 1000." << endl;
        return 1;
    }

    long long result = fibonacci(n);
    cout << "The " << n << "-th Fibonacci number is: " << result << endl;

    return 0;
}
