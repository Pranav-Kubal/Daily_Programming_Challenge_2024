#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findFirstKTimes(const vector<int> & arr, int k) {
    unordered_map<int, int> countMap;

    // Count occurrences of each element
    for (int num : arr) {
        countMap[num]++;
    }

    // Find the first element that occurs exactly k times
    for (int num : arr) {
        if (countMap[num] == k) {
            return num; // Return the first element found
        }
    }

    return -1; // No element found that occurs exactly k times
}

int main() {
    int n, k;

    // Take input from user for the size of array
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    // Take input for the elements of array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Take input for k
    cout << "Enter the value of k: ";
    cin >> k;

    int result = findFirstKTimes(arr, k);
    cout << "The first element that appears exactly " << k << " times is: " << result << endl;

    return 0;
}
