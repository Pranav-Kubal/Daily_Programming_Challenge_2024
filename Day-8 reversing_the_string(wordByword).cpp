#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(string s) {
    // Use string stream to split the words
    stringstream SS(s);
    string word;
    vector <string> words;
    
    // Store the words in a vector
    while (SS >> word) {
        words.push_back(word);
    }
    
    // Reverse the order of words and form the result
    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) {
            result += " ";
        }
    }
    return result;
}

int main() {
    string s1 = "the sky is blue";
    cout << reverseWords(s1) << endl;  

    return 0;
}
