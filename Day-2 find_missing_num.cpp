#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int> & arr) {
    int n = arr.size() + 1; // Because arr has n-1 elements
    int expectedSum = n * (n + 1) / 2; // Sum of the first n natural numbers formula
    int actualSum = 0;

    // Calculate actual sum of the elements present in the array
    for (int num : arr) {
        actualSum = actualSum + num;
    }
    // The missing number is the difference between expected and actual sum
    return expectedSum - actualSum;
}

int main() {
    vector<int> arr = { 1, 2, 4, 5 };
    cout << "Missing number from the array is: " << findMissingNumber(arr) <<endl; 
    return 0;
}
