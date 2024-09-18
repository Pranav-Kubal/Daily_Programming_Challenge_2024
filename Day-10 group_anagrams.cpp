#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> & strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (const string & str : strs) {
        // Sorting string to create a key
        string key = str;
        sort(key.begin(), key.end());
        
        // Grouping the anagrams using the sorted string as the key
        anagramMap[key].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto & pair : anagramMap) {
        result.push_back(pair.second);
    }

    return result;
}

void printGroupedAnagrams(const vector<vector<string>> & groupedAnagrams) {
    for (const auto & group : groupedAnagrams) {
        cout << "[";
        for (const string & word : group) {
            cout << "\"" << word << "\", ";
        }
        cout << "\b\b] "; // To remove the last comma and space
    }
    cout << endl;
}

int main() {
    vector<vector<string>> testCases = {
        {"eat", "tea", "tan", "ate", "nat", "bat"}, 
        {""},                                        
        {"a"},                                       
        {"abc", "bca", "cab", "xyz", "zyx", "yxz"}, 
        {"abc", "def", "ghi"},                      
        {"", "b", "c", "d", ""},                    
        {"listen", "silent", "enlist", "inlets"},  
    };

    for (const auto & strs : testCases) {
        vector<vector<string>> groupedAnagrams = groupAnagrams(const_cast<vector<string>&>(strs));
        printGroupedAnagrams(groupedAnagrams);
    }

    return 0;
}
