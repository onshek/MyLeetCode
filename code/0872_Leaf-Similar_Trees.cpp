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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // inOrder traverse
        vector<int> tnV1, tnV2;
        inOrder(root1, tnV1);
        inOrder(root2, tnV2);
        if (tnV1 == tnV2) return true;
        return false;
    }

    void inOrder(TreeNode* root, vector<int>& tnV) {
        if (!root) return;
        stack<TreeNode*> tnStack;
        while (true) {
            if (root) {
                tnStack.push(root);
                root = root->left;
            } else if (!tnStack.empty()) {
                root = tnStack.top();
                if (!root->left & !root->right) tnV.push_back(root->val);
                tnStack.pop();
                root = root->right;
            } else break;
        }
    }
};