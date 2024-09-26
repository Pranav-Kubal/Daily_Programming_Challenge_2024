#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

int divisorCount(int num) {
    int count = 0;
    int sqrtnum = static_cast<int>(sqrt(num));

    for(int i = 1; i <= sqrtnum; i++) {
        if(num % i == 0) {
            count++; // Count i
            if(i != num/i) {
                count++; // Adds count different than i
            }
        }
    }

    return count;
}
int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if(num < 1) { // avoiding negative number
        cout << "Kindly enter a positive number." << endl;
        return 1;
    }

    cout << "Output: " << divisorCount(num) << endl;
    return 0;
}
 
