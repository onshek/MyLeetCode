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
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        queue<TreeNode*> tnQueue;
        tnQueue.push(root);
        while (!tnQueue.empty()) {
            TreeNode* node = tnQueue.front(); tnQueue.pop();
            if (node->val % 2 == 0) {
                if (node->left) {
                    if (node->left->left) res += node->left->left->val;
                    if (node->left->right) res += node->left->right->val;
                }
                if (node->right) {
                    if (node->right->left) res += node->right->left->val;
                    if (node->right->right) res += node->right->right->val;
                }
            }
            if (node->left) tnQueue.push(node->left);
            if (node->right) tnQueue.push(node->right);
        }
        return res;
    }
};