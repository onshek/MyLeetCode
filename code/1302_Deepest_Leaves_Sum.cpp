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
    int deepestLeavesSum(TreeNode* root) {
        // level order traverse
        int res = 0;
        if (!root) return res;
        vector<vector<int>> valVector;
        queue<TreeNode*> tnQueue; tnQueue.push(root);
        while (!tnQueue.empty()) {
            int size= tnQueue.size();
            valVector.push_back(vector<int>());
            for (int i=0; i<size; i++) {
                TreeNode* node = tnQueue.front(); tnQueue.pop();
                valVector.back().push_back(node->val);
                if (node->left) tnQueue.push(node->left);
                if (node->right) tnQueue.push(node->right);
            }
        }

        for (int i=0; i<valVector.back().size(); i++) res += valVector.back()[i];
        return res;
        // return accumulate(valVector.back().begin(), valVector.back().end(), 0);
    }
};