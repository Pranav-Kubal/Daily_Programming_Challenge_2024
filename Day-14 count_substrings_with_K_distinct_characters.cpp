#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int countSubstringsWithKDistinct(const string & s, int k) {
    int n = s.length();
    int count = 0;

    // Function to count substrings with at most k distinct characters
    auto atMostK = [&](int k) {
        unordered_map<char, int> charCount;
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right) {
            charCount[s[right]]++;

            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            result += right - left + 1;
        }

        return result;
    };

    // The number of substrings with exactly k distinct characters
    return atMostK(k) - atMostK(k - 1);
}

int main() {
    string s;
    int k;

    // Input string and integer k
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = countSubstringsWithKDistinct(s, k);
    cout << "The number of substrings with exactly " << k << " distinct characters is: " << result << endl;

    return 0;
}
