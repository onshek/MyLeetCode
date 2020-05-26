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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> V;
        stack<TreeNode*> S;
        TreeNode* x = root;
        while (true) {
            if (x) {
                S.push(x);
                x = x->left;
            } else if (!S.empty()) {
                x = S.top();
                V.push_back(x->val);
                S.pop();
                x = x->right;
            } else {
                break;
            }
        }
        return V;
    }
};