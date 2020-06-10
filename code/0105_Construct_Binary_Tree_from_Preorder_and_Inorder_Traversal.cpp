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
    vector<int> preOrder, inOrder;
    unordered_map<int, int> idxMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preOrder = preorder; inOrder = inorder;
        int _size = preOrder.size();
        for (int idx=0; idx<_size; idx++) idxMap[inorder[idx]] = idx;
        return construct(0, 0, _size-1);
    }

    TreeNode* construct(int preRoot, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        int inRoot = idxMap[preOrder[preRoot]];
        TreeNode* root = new TreeNode(preOrder[preRoot]);
        int leftChildSize = inRoot - inLeft;
        root->left = construct(preRoot+1, inLeft, inRoot-1);
        root->right = construct(preRoot+leftChildSize+1, inRoot+1, inRight);
        return root;
    }
};