#include <iostream>
#include <vector>
using namespace std;

// Function to perform prime factorization
vector<int> primeFactorization(int N) {
    vector<int> factors;

    // Check for number of 2s that divide N
    while (N % 2 == 0) {
        factors.push_back(2);
        N = N / 2;
    }
    // Check for odd factors from 3 onwards
    for (int i = 3; i * i <= N; i = i + 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N = N / i;
        }
    }
    // If N becomes a prime number greater than 2
    if (N > 2) {
        factors.push_back(N);
    }
    return factors;
}

int main() {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;

    vector<int> factors = primeFactorization(N);
    cout << "Prime factorization of " << N << " is: [";
    for (size_t i = 0; i < factors.size(); ++i) {
        cout << factors[i];
        if (i < factors.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
