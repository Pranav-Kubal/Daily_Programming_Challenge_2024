#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> bracket_map = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s) {
        // If it's one of the closing brackets
        if (bracket_map.count(ch)) {
            if (stk.empty() || stk.top() != bracket_map[ch]) {
                return false; // Unmatched closing bracket
            }
            stk.pop(); // Pop the matching opening bracket
        } else {
            // If it's an opening bracket, push it onto the stack
            stk.push(ch);
        }
    }

    return stk.empty(); // If stack is empty, all brackets were matched
}

int main() {
    // Test cases
    cout << boolalpha; // To print boolean values as true/false
    cout << "case 1: Input = () \n \tOutput: " << isValid("()") << endl;
    cout << "case 2: Input = ([)] \n \tOutput: " << isValid("([)]") << endl;
    cout << "case 3: Input = [{()}] \n \tOutput: " << isValid("[{()}]") << endl;
    cout << "case 4: Input = '' \n \tOutput: " << isValid("") << endl;
    cout << "case 5: Input = {[} \n \tOutput: " << isValid("{[}") << endl;

    return 0;
}
