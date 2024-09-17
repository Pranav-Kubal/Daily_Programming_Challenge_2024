#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }

    // Start with the first string in the array as the initial prefix
    string prefix = strs[0];

    // Iterate through the rest of the strings
    for (size_t i = 1; i < strs.size(); ++i) {
        const string& str = strs[i];
        // Check the common prefix between the current prefix and the new string
        size_t j = 0;
        while (j < prefix.length() && j < str.length() && prefix[j] == str[j]) {
            ++j;
        }
        // Update the prefix to the common part found
        prefix = prefix.substr(0, j);

        // If at any point the prefix becomes empty, return immediately
        if (prefix.empty()) {
            return "";
        }
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

    strs = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

    strs = {"apple", "ape", "april"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

    strs = {""};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

    strs = {"alone"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

    return 0;
}
