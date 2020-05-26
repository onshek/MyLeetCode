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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> V;
        if (!root) return V;
        Q.push(root);

        while (!Q.empty()) {
            V.insert(V.begin(), vector<int>());
            int _size = Q.size();
            for (int i=0; i<_size; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                V.front().push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
        }
        return V;
    }
};