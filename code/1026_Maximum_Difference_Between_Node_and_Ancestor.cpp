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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        getValue(root, root->val, root->val, res);
        return res;
    }

    void getValue(TreeNode* root, int minVal, int maxVal, int& res) {
        if (!root) return;
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        res = max(res, maxVal - minVal);
        getValue(root->left, minVal, maxVal, res);
        getValue(root->right, minVal, maxVal, res);
    }
};