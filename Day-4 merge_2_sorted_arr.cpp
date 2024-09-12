#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void merge_two_sorted_array(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    
    for (int i = 0; i < n; i++) {
        if (arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            sort(arr2.begin(), arr2.end());
        }
    }
}

int main() {
    int n, m;

    cout << "Enter the number of elements in the first sorted array: ";
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter elements of the first array in sorted order: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements in the second sorted array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter elements of the second array in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    merge_two_sorted_array(arr1, arr2);

    cout << "Output:" << endl;

    cout << "First array: ";
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Second array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}
