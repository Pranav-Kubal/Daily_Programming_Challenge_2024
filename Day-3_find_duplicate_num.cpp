#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0;i < n - 1; i++) {
        for(int j = i + 1; j < n;j++) {
            if(arr[i] == arr[j]) {
                return arr[i]; // Return the duplicate value found
            }
        }
    }
    return -1; // return -1 if no duplicate is found
}
    
int main(){
    vector<int> arr = { 3, 1, 3, 4, 2};
   
    int result = findDuplicate(arr);
    cout<<"Duplicate value is: "<<result<<endl;
    return 0;
}
