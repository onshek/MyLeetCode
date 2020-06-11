/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> valVector;
        while (head) {
            valVector.push_back(head->val);
            head = head->next;
        }
        return construct(0, valVector.size()-1, valVector);
    }
    TreeNode* construct(int leftIdx, int rightIdx, vector<int>& nums) {
        if (leftIdx > rightIdx) return nullptr;
        int midIdx = (leftIdx + rightIdx) / 2;
        TreeNode* root = new TreeNode(nums[midIdx]);
        root->left = construct(leftIdx, midIdx-1, nums);
        root->right = construct(midIdx+1, rightIdx, nums);
        return root;
    } 
};