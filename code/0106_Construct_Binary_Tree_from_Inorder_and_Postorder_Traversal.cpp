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
        int _size = preorder.size();
        for (int i=0; i<_size; i++) idxMap[inorder[i]] = i;
        return construct(0, _size-1, 0, _size-1);
    }

    TreeNode* construct(int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return nullptr;
        int preRoot = preLeft;
        int inRoot = idxMap[preOrder[preRoot]];
        TreeNode* root = new TreeNode(preOrder[preRoot]);
        int leftChildSize = inRoot - inLeft;
        root->left = construct(preLeft+1, preLeft+leftChildSize, inLeft, inRoot-1);
        root->right = construct(preLeft+leftChildSize+1, preRight, inRoot+1, inRight);
        return root;
    }
};