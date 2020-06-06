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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // inOrder traverse
        stack<TreeNode*> tnStack; 
        while (true) {
            if (cloned) {
                if (cloned->val == target->val) return cloned;
                tnStack.push(cloned);
                cloned = cloned->left;
            } else if (!tnStack.empty()) {
                cloned = tnStack.top(); tnStack.pop();
                cloned = cloned->right;
            }
        }
    }
};