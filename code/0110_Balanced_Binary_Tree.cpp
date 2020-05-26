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
    int getHeight(TreeNode* v) {
        if (!v) return -1;
        return max(getHeight(v->left), getHeight(v->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int height = getHeight(root->left) - getHeight(root->right);
        return (-1 <= height) && (height <= 1) && (isBalanced(root->left)) && (isBalanced(root->right));
    }
};