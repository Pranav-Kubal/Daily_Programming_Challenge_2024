#include <iostream>
#include <limits>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to validate the BST properties.
bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    // An empty tree is a valid BST.
    if (!node) return true;

    // Check if the current node's value is within the valid range.
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }

    // Recursively check the left and right subtrees.
    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}

// Main function to check if the tree is a valid BST.
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}

// Function to print the tree level by level.
void printTree(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl; // New line for the next level
    }
}

int main() {
    // Testcase 1:
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    cout << "Testcase 1:" << endl;
    printTree(root1);
    cout << "Is valid BST ? " << (isValidBST(root1) ? "true" : "false") << endl; 
    cout << endl;

    // Testcase 2:
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << "Testcase 2:" << endl;
    printTree(root2);
    cout << "Is valid BST ? " << (isValidBST(root2) ? "true" : "false") << endl; 
    cout << endl;

    // Testcase 3:
    TreeNode* root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(20);

    cout << "Testcase 3:" << endl;
    printTree(root3);
    cout << "Is valid BST ? " << (isValidBST(root3) ? "true" : "false") << endl; 
    cout << endl;
    return 0;
}
