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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // inOrder traverse
        return construct(0, nums.size()-1, nums);
    }

    TreeNode* construct(int leftIdx, int rightIdx, vector<int>& nums) {
        if (leftIdx > rightIdx) return nullptr;
        int idx = (leftIdx + rightIdx) / 2;
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = construct(leftIdx, idx-1, nums);
        root->right = construct(idx+1, rightIdx, nums);
        return root;
    }
};