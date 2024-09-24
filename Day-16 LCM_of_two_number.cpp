#include <iostream>
using namespace std;

// Function to compute GCD using the Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM using GCD
long long lcm(long long n, long long m) {
    return (n / gcd(n, m)) * m; // To prevent overflow
}

int main() {
    long long N, M;
    cout << "Enter two integers: \n";
    cout << "First Number: ";
    cin >> N;
    cout << "Second Number: ";
    cin >> M;

    long long result = lcm(N, M);
    cout << "LCM of " << N << " and " << M << " is: " << result << endl;

    return 0;
}
