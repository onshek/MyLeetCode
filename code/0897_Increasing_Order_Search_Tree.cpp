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
    TreeNode* increasingBST(TreeNode* root) {
        // inOrder traverse
        TreeNode* fakeNode = new TreeNode(-1), *res = fakeNode;
        stack<TreeNode*> tnStack;
        while (true) {
            if (root) {
                tnStack.push(root);
                root = root->left;
            } else if (!tnStack.empty()) {
                root = tnStack.top(); tnStack.pop();
                fakeNode->right = new TreeNode(root->val);
                fakeNode = fakeNode->right;
                root = root->right;
            } else break;
        }
        return res->right;
    }
};