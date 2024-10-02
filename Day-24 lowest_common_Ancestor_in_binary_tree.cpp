#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If root is null, return null
        if (root == NULL) return NULL;

        // If either p or q is the root, return root
        if (root == p || root == q) return root;

        // Recur for left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, root is the LCA
        if (left != NULL && right != NULL) return root;

        // Otherwise, return non-null value from left or right
        return left != NULL ? left : right;
    }
};

int main() {
    // Example binary tree [3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;
    TreeNode* p = root->left;  
    TreeNode* q = root->right; 

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
