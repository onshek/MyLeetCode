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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        queue<TreeNode*> treeNodeQ;
        TreeNode* tmp;
        treeNodeQ.push(root);
        while (!treeNodeQ.empty()) {
            tmp = treeNodeQ.front(); treeNodeQ.pop();
            if (tmp->left) {
                treeNodeQ.push(tmp->left);
                if (!tmp->left->left && !tmp->left->right) res += tmp->left->val;
            }
            if (tmp->right) treeNodeQ.push(tmp->right);
        }
        return res;
    }
};