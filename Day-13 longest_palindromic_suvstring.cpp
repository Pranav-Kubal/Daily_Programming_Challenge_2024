#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to expand around center and find the longest palindrome
string expandAroundCenter(const string & s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

// Function to find the longest palindromic substring
string longestPalindrome(const string & s) {
    if (s.empty()) return "";

    string longest = "";
    for (int i = 0; i < s.length(); i++) {
        // Check for odd-length palindromes
        string oddPalindrome = expandAroundCenter(s, i, i);
        if (oddPalindrome.length() > longest.length()) {
            longest = oddPalindrome;
        }
        
        // Check for even-length palindromes
        string evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (evenPalindrome.length() > longest.length()) {
            longest = evenPalindrome;
        }
    }
    return longest;
}

// Function to run predefined test cases
void runTestCases() {
    vector<string> testCases = {
        "1: babad",
        "2: cbbd",
        "3: a",
        "4: aaaa",
        "5: abc"
    };

    cout << "Running test cases:\n";
    for (const auto & testCase : testCases) {
        string result = longestPalindrome(testCase);
        cout << "case " << testCase << "\t Output: " << result << endl;
    }
}

int main() {
    // Run predefined test cases
    runTestCases();

    return 0;
}
