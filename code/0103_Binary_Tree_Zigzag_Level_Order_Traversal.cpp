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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool reverse = false;
        queue<TreeNode*> Q;
        vector<vector<int>> V;
        if (!root) return V;
        Q.push(root);
        while (!Q.empty()) {
            int _size = Q.size();
            V.push_back(vector<int> ());
            for (int i=0; i<_size; i++) {
                root = Q.front();
                Q.pop();
                if (!reverse) {
                    V.back().push_back(root->val);
                } else {
                    V.back().insert(V.back().begin(), root->val);
                }
                if (root->left) Q.push(root->left);
                if (root->right) Q.push(root->right);
            }
            reverse = !reverse; 
        }
        return V;
    }
};