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
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* x = root;
        vector<vector<int>> V;
        queue<TreeNode*> Q;
        Q.push(x);
        while (!Q.empty() && (x)) {
            int _size = Q.size();
            V.push_back(vector<int> ());
            for (int i=0; i<_size; i++){
                x = Q.front();
                V.back().push_back(x->val);
                Q.pop();
                if (x->left) Q.push(x->left);
                if (x->right) Q.push(x->right);
            }
        }
        return V;
    }
};