/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int cnt = 0;
public:
    int goodNodes(TreeNode* root) {
        if (!root) return cnt;
        oneMoreGoodNode(root, root->val);
        return cnt;
    }

    void oneMoreGoodNode(TreeNode* root, int maxValue) {
        if (root->val >= maxValue) {
            cnt++;
            maxValue = root->val;
        }
        // still need to check children even if parent->val < grandparent->val
        if (root->left) oneMoreGoodNode(root->left, maxValue);
        if (root->right) oneMoreGoodNode(root->right, maxValue);
    }
};