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
    unordered_map<int, int> idxMap;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // reference: 0105
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        // for (auto s: preorder) cout << s << " ";
        // cout << endl;
        // for (auto s: inorder) cout << s << " ";
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