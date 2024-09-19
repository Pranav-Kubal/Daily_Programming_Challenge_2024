#include<iostream>
#include<vector>
using namespace std;

//function to sort an array containing only 0's, 1's and 2's 
void sortColors(vector<int>& arr) {
// initialize three pointers
    int low = 0, mid = 0, high = arr.size() - 1;
// loop through array until mid crosses high
    while (mid <= high) {
        if (arr[mid] == 0) { 
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
  // definig an array
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
  // sort array using sortColors function 
    sortColors(arr);
    
    cout << "Sorted array is: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
