#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;

// Function to evaluate the postfix expression
int evaluatePostfix(const string & expression) {
    stack<int> s;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        // Check if the token is an integer
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {
            // Convert the string to an integer and push it onto the stack
            s.push(stoi(token));
        } else {
            // It's an operator, pop two operands from the stack
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result;

            // Perform the operation
            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = (a / b);
                    if ((a < 0) != (b < 0) && a % b != 0) {
                        result++; 
                    }
                    break;
                default:
                    throw invalid_argument("Invalid operator");
            }
            // Push the result back onto the stack
            s.push(result);
        }
    }

    // The final result is the only element left in the stack
    return s.top();
}

int main() {
    string input;
    
    cout << "Enter a postfix expression (separated by spaces): ";
    getline(cin, input); // Read the entire line of input

    try {
        int result = evaluatePostfix(input);
        cout << "Output: " << result << endl;
    } catch (const exception & e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
