#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void permute(string s, int l, int r, set<string> & result) {
    if (l == r) {
        result.insert(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r, result);
            swap(s[l], s[i]); 
        }
    }
}

vector<string> uniquePermutations(string s) {
    set<string> result;
    permute(s, 0, s.size() - 1, result);
    return vector<string>(result.begin(), result.end());
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    vector<string> permutations = uniquePermutations(input);
    cout << "Total unique permutations: ";
    for (const auto & perm : permutations) {
        cout << perm << " ";
    }
    cout << endl;

    return 0;
}
