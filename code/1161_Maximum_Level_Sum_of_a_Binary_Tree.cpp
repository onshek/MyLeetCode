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
    int maxLevelSum(TreeNode* root) {
        // level order traverse
        vector<int> res;
        queue<TreeNode*> tnQueue;
        int position = 0, maxNum;
        tnQueue.push(root);
        while (!tnQueue.empty()) {
            int size = tnQueue.size();
            int tmpSum = 0;
            for (int i=0; i<size; i++) {
                TreeNode* tn = tnQueue.front();
                tnQueue.pop();
                tmpSum += tn->val;
                if (tn->left) tnQueue.push(tn->left);
                if (tn->right) tnQueue.push(tn->right);
            }
            res.push_back(tmpSum);
        }
        maxNum = res[0];
        for (int i=0; i<res.size(); i++) {
            if (res[i] > maxNum) {
                maxNum = res[i];
                position = i;
            }
        }
        return position + 1;
    }
};