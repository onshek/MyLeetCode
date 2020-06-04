/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        if (!head) return res;
        while (head) {
            ListNode* tmp = head;
            int val = tmp->val;
            while (true) {
                if (!tmp->next) {
                    res.push_back(0);
                    break;
                } else {
                    if (tmp->next->val > val) {
                        res.push_back(tmp->next->val);
                        break;
                    } else tmp = tmp->next;
                }
            }
            head = head->next;
        }
        return res;
    }
};