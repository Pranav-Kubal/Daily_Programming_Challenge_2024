#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> & arr, int k) 
{
    priority_queue<pair<int, int>> maxHeap;
    vector<int> result;

    // Fill the heap with the first k elements
    for (int i = 0; i < k && i < arr.size(); i++) 
    {
        maxHeap.push({arr[i], i});
    }

    // If k is valid
    if (k > 0 && !arr.empty())
        result.push_back(maxHeap.top().first);

    for (int i = k; i < arr.size(); i++) 
    {
        // Push the current element onto the heap
        maxHeap.push({arr[i], i});
        
        // Remove elements that are out of the current window
        while (maxHeap.top().second <= i - k) 
        {
            maxHeap.pop();
        }
        
        result.push_back(maxHeap.top().first);
    }

    return result;
}

int main() 
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter the window size (k): ";
    cin >> k;

    vector<int> result = slidingWindowMaximum(arr, k);
    cout << "Sliding window maximums: ";
    for (int num : result) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
