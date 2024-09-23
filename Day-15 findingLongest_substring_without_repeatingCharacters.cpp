#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(const string & s) {
    // Map to remember the last position of each character
    unordered_map<char, int> charIndexMap; 
    int maxLength = 0; // Variable to keep track of the longest length
    int start = 0; // Starting index of the current substring

    // Each character from the string will go through this loop
    for (int i = 0; i < s.length(); i++) {
        // Check if the character is already in the map
        // and if its last position is within the current substring
        if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= start) {
            // Move the start to one position right of the last occurrence
            start = charIndexMap[s[i]] + 1;
        }
        // Update the last seen index of the character
        charIndexMap[s[i]] = i;

        // Calculate the length of the current substring and update maxLength
        maxLength = max(maxLength, i - start + 1);
    }
    return maxLength; // Return the length of the longest substring
}

int main() {
    string S;
    cout << "Enter a string: "; // Input taken from user
    cin >> S;
    
    int result = lengthOfLongestSubstring(S); // Function call
    cout << "Length of the longest substring without repeating characters: " << result << endl; // Output
    
    return 0;
}
