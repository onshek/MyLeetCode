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
    int countNodes(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        // inOrder traverse
        stack<TreeNode*> treeNodeStk; 
        while (true) {
            if (root) {
                treeNodeStk.push(root); res++;
                root = root->left;
            } else if (!treeNodeStk.empty()) {
                root = treeNodeStk.top(); treeNodeStk.pop();
                root = root->right;
            } else break;
        }
        return res;
    }
};