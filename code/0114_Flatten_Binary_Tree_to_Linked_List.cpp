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
private:
    stack<TreeNode*> treeNodeStk;
    vector<TreeNode*> valVec;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        while (true) {
            visitAlongLeftBranch(root);
            if (treeNodeStk.empty()) break;
            root = treeNodeStk.top(); treeNodeStk.pop();
        }

        for (int i=0; i<valVec.size()-1; i++) {
            valVec[i]->left = NULL; 
            valVec[i]->right = valVec[i+1]; 
        }
        valVec[valVec.size()-1]->left= NULL;
        valVec[valVec.size()-1]->right= NULL;
    }

    void visitAlongLeftBranch(TreeNode* root) {
        if (!root) return;
        while (root) {
            valVec.push_back(root);
            treeNodeStk.push(root->right);
            root = root->left;
        }
    }
};