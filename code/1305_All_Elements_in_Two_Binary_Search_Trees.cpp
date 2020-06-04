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
private:
    vector<int> res;
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // inOrder traverse
        inOrderTraverse(root1);
        inOrderTraverse(root2);
        sort(res.begin(), res.end());  // merge sort is better
        return res;
    }

    void inOrderTraverse(TreeNode* root) {
        stack<TreeNode*> tnStack;
        while (true) {
            if (root) {
                tnStack.push(root);
                root = root->left;
            } else if (!tnStack.empty()) {
                root = tnStack.top(); tnStack.pop();
                res.push_back(root->val);
                root = root->right;
            } else break;
        }
    }
};