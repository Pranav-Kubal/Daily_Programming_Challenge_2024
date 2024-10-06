#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two trees are mirror images of each other
bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true; // Both are null
    if (!left || !right) return false; // One is null, other is not
    return (left->val == right->val) && 
           isMirror(left->right, right->left) && 
           isMirror(left->left, right->right);
}

// Function to check if the binary tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (!root) return true; // An empty tree is symmetric
    return isMirror(root->left, root->right);
}

// Function to build the tree from user input
TreeNode* buildTree() {
    string input;
    cout << "Enter tree values in level order (use 'null' for empty nodes, separated by spaces): ";
    getline(cin, input);
    
    if (input.empty() || input == "null") return nullptr; // Handle empty input
    
    stringstream ss(input);
    string value;
    queue<TreeNode*> q;
    
    ss >> value; // Read the root value
    TreeNode* root = new TreeNode(stoi(value));
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Left child
        if (ss >> value && value != "null") {
            current->left = new TreeNode(stoi(value));
            q.push(current->left);
        }
        
        // Right child
        if (ss >> value && value != "null") {
            current->right = new TreeNode(stoi(value));
            q.push(current->right);
        }
    }
    
    return root;
}

int main() {
    TreeNode* root = buildTree();

    // Check if the tree is symmetric
    cout << (isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}
