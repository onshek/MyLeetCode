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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int _size = q.size(), _maxNum=q.front()->val;
            for (int i=0; i<_size; i++) {
                TreeNode* _node = q.front(); q.pop();
                _maxNum = max(_maxNum, _node->val);
                if (_node->left) q.push(_node->left);
                if (_node->right) q.push(_node->right);
            }
            res.push_back(_maxNum);
        }
        return res;
    }
};