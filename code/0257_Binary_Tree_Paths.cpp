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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        traverse(root, "", res);
        return res;
    }

    void traverse(TreeNode* root, string tmpRes, vector<string>& res) {
        if (!root->left & !root->right) {
            tmpRes += to_string(root->val);
            res.push_back(tmpRes);
        }
        tmpRes += to_string(root->val) + "->";
        if (root->left) traverse(root->left, tmpRes, res);
        if (root->right) traverse(root->right, tmpRes, res);
    }
};