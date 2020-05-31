/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // level order traverse + sort
        vector<int> res;
        queue<TreeNode*> q; q.push(root);
        TreeNode* tmpTreeNode;
        while (!q.empty()) {
            tmpTreeNode = q.front(); q.pop();
            res.push_back(tmpTreeNode->val);
            if (tmpTreeNode->right) q.push(tmpTreeNode->right);
            if (tmpTreeNode->left) q.push(tmpTreeNode->left);
        }
        sort(res.begin(), res.end());
        return res[k-1];
    }
};