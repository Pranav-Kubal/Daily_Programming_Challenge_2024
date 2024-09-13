#include <iostream>
#include <vector>
#include <algorithm> //use this header for reverse() function
using namespace std;

vector<int> findLeaders(int arr[], int n) {
    vector<int> leaders;
    int max = arr[n - 1];
    
    // The last element in an array is always a leader
    leaders.push_back(max);
    
    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max) {
            leaders.push_back(arr[i]);
            max = arr[i];
        }
    }
    
    // The leaders are collected in reverse order, so reverse the list
    reverse(leaders.begin(), leaders.end());
    
    return leaders;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    vector<int> leaders = findLeaders(arr, n);
    
    cout << "Leaders: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }    
    return 0;
}
