/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        invert(root);
        return root;
    }

    void invert(TreeNode* root) {
        if (!root->left && !root->right) return;
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        if (root->left) invert(root->left);
        if (root->right) invert(root->right);
    }
};