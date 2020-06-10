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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // level order traverse
        vector<vector<int>> res;
        if (!root) return res;
        unordered_map<TreeNode*, TreeNode*> tnMap;
        vector<TreeNode*> leafNode;
        queue<TreeNode*> tnQueue; tnQueue.push(root);
        while (!tnQueue.empty()) {
            TreeNode* node = tnQueue.front(); tnQueue.pop();
            if (node->left) {
                tnQueue.push(node->left);
                tnMap.insert(pair<TreeNode*, TreeNode*>(node->left, node));
            }
            if (node->right) {
                tnQueue.push(node->right);
                tnMap.insert(pair<TreeNode*, TreeNode*>(node->right, node));
            }
            if (!node->left && !node->right) leafNode.push_back(node);
        }

        // for (auto p: tnMap) cout << p.first->val << "->" << p.second->val << endl;
        for (int i=0; i<leafNode.size(); i++) {
            TreeNode* node = leafNode[i];
            res.push_back(vector<int>()); 
            int sumOfNodes = 0;
            while (node) {
                sumOfNodes += node->val;
                res.back().insert(res.back().begin(), node->val);
                node = tnMap[node];
            }
            if (sumOfNodes != sum) res.pop_back();
        }
        return res;
    }
};