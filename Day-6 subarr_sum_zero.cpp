#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(const vector<int> & arr) {
    // To store the prefix-sum and corresponding indices
    unordered_map<int, vector<int>> prefixMap;
    vector<pair<int, int>> result;
    int prefix_sum = 0;

    // Handle the case where prefix-sum of 0 is from the start of the array
    prefixMap[0].push_back(-1);  // Prefix sum 0 is considered at index -1

    for (int i = 0; i < arr.size(); ++i) {
        prefix_sum += arr[i];

        if (prefixMap.find(prefix_sum) != prefixMap.end()) {
            for (int start_index : prefixMap[prefix_sum]) {
                result.push_back({start_index + 1, i});
            }
        }

        // Store the current index in the list of this prefix-sum
        prefixMap[prefix_sum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};

    vector<pair<int, int>> zeroSumSubarrays = findZeroSumSubarrays(arr);
    
    for (const auto & subarray : zeroSumSubarrays) {
        cout << "(" << subarray.first << ", " << subarray.second << ")" << " ";
    }
    return 0;
}
