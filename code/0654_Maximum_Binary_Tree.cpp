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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // reference: 1008
        return construct(nums, 0, nums.size()-1);
    }

    TreeNode* construct(vector<int>& nums, int lIdx, int rIdx) {
        // cout << "lIdx=" << lIdx << ", rIdx=" << rIdx << endl;
        if (lIdx > rIdx) return nullptr;
        int idx = lIdx, maxNum = nums[idx];
        for (int i=lIdx; i<=rIdx; i++) {
            if (nums[i] > maxNum) {
                idx = i;
                maxNum = nums[idx];
            }
        }
        // int idx = distance(nums.begin(), max_element(nums.begin()+lIdx, nums.begin() + rIdx + 1));
        // cout << "maxNum=" <<  nums[idx] << ", lIdx="  << lIdx << ", idx-1=" << idx-1 << ", idx+1=" << idx+1  << ", rIdx=" << rIdx << endl;
        TreeNode* root = new TreeNode(maxNum);
        root->left = construct(nums, lIdx, idx-1);
        root->right = construct(nums, idx+1, rIdx);
        return root;
    }
};