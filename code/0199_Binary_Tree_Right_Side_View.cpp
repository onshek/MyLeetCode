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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode* tmp;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int _size = q.size();
            for (int i=0; i<_size-1; i++) {
                tmp = q.front(); q.pop(); 
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            tmp = q.front(); q.pop(); 
            res.push_back(tmp->val); 
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        return res;
    }
};