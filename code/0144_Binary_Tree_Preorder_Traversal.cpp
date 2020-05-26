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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> V;
        stack<TreeNode*> S;
        while (true) {
            visitAlongLeftBranch(root, V, S);
            if (S.empty()) return V;
            root = S.top(); S.pop();
        }
    }

    void visitAlongLeftBranch(TreeNode* root, vector<int>& v, stack<TreeNode*>& s) {
        while (root) {
            v.push_back(root->val);
            s.push(root->right);
            root = root->left;
        }
    }
};