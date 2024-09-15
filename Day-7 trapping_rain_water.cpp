#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int trap(const vector <int> & height) {
    int n = height.size();
    if (n <= 1) return 0; // No water can be trapped within 2 or less than 2 bars

    // Create arrays for max heights to the left and right of each bar
    vector <int> max_left(n);
    vector <int> max_right(n);

    // Fill the max_left array
    max_left[0] = height[0];
    for (int i = 1; i < n; ++i) {
        max_left[i] = max(max_left[i - 1], height[i]);
    }

    // Fill the max_right array
    max_right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_right[i] = max(max_right[i + 1], height[i]);
    }

    // Calculate the trapped water
    int total_water = 0;
    for (int i = 0; i < n; ++i) {
        total_water += min(max_left[i], max_right[i]) - height[i];
    }

    return total_water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trap(height);
    cout << "Total water trapped: " << result << endl;
    return 0;
}
