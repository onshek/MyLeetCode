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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        //cout << leftMax(root->left) << root->val << endl;
        //cout << root->val << rightMin(root) << endl;

        return ((root->left) ? (leftMax(root->left) < (root->val)) : true) && ((root->right) ? ((root->val) < rightMin(root->right)) : true) && isValidBST(root->left) && isValidBST(root->right);
    }
    int leftMax(TreeNode* root) {
        while (root->right) root = root->right;
        return root->val;
    }
    int rightMin(TreeNode* root) {
        while (root->left) root = root->left;
        return root->val;
    }
};