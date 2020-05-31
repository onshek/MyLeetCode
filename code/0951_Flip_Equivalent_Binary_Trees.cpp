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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1, root2);
    }

    bool check(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!(root1 && root2)) return false;
        if (root1->val != root2->val) return false;
        return (check(root1->left, root2->right) && check(root1->right, root2->left) || check(root1->left, root2->left) && check(root1->right, root2->right));
    }
};