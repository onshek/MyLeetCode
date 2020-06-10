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
    vector<int> inOrder, postOrder;
    unordered_map<int, int> idxMap;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inOrder = inorder; postOrder = postorder; 
        int _size = postOrder.size();
        for (int idx=0; idx<_size; idx++) idxMap[inorder[idx]] = idx;
        return construct(_size-1, 0, _size-1);
    }

    TreeNode* construct(int postRoot, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        int inRoot = idxMap[postOrder[postRoot]];
        TreeNode* root = new TreeNode(postOrder[postRoot]);
        int rightChildSize = inRight - inRoot;
        root->left = construct(postRoot-rightChildSize-1, inLeft, inRoot-1);
        root->right = construct(postRoot-1, inRoot+1, inRight);
        return root;
    }
};