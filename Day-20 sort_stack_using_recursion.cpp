#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element into the sorted stack
void sortedInsert(stack<int> & st, int elem) {
    if (st.empty() || elem >= st.top()) {
        st.push(elem);
        return;
    }
    int topElem = st.top();
    st.pop();
    sortedInsert(st, elem);
    st.push(topElem);
}

// Recursive function to sort the stack
void sortStack(stack<int> & st) {
    if (st.empty()) {
        return;
    }
    int topElem = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, topElem);
}

// Print the stack
void printStack(stack<int> st) {
    if (st.empty()) {
        return;
    }
    int topElem = st.top();
    st.pop();
    printStack(st);
    cout << topElem << " ";
}

int main() {
    stack<int> st;
    int numElements, value;

    cout << "Enter number of elements: ";
    cin >> numElements;
    cout << "Enter elements: ";
    for (int i = 0; i < numElements; i++) {
        cin >> value;
        st.push(value);
    }

    // Sort the stack
    sortStack(st);
    cout << "Sorted Stack: ";
    printStack(st);
    cout << endl;

    return 0;
}
