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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        vector<vector<int>> v;
        while (!q.empty()) {
            v.push_back(vector<int>());
            int _size = q.size();
            for (int i=0; i<_size; i++) {
                TreeNode* node = q.front(); q.pop();
                v.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return v.back().front();
    }
};