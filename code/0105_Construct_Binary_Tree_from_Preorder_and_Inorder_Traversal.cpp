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
    map<int, int> idxMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int _size = preorder.size();
        for (int i=0; i<_size; i++) idxMap[inorder[i]] = i;
        return construct(preorder, inorder, 0, _size-1, 0, _size-1);
    }

    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return nullptr;
        int preRoot = preLeft;
        int inRoot = idxMap[preorder[preRoot]];
        TreeNode* root = new TreeNode(preorder[preRoot]);
        int leftChildSize = inRoot - inLeft;
        root->left = construct(preorder, inorder, preLeft+1, preLeft+leftChildSize, inLeft, inRoot-1);
        root->right = construct(preorder, inorder, preLeft+leftChildSize+1, preRight, inRoot+1, inRight);
        return root;
    }
};