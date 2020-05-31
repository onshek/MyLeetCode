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
    int sumNumbers(TreeNode* root) {
        // divide and conquer
        if (!root) return 0;
        return getScore(root, 0);
    }

    int getScore(TreeNode* root, int score) {
        score = score * 10 + root->val;
        if (!root->left && !root->right) return score;
        else if (root->left && !root->right) return getScore(root->left, score);
        else if (!root->left && root->right) return getScore(root->right, score);
        else return getScore(root->left, score) + getScore(root->right, score);
    }
};