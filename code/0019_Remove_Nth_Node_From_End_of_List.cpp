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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> lnVector;
        int idx;
        while (head) {
            lnVector.push_back(head);
            head = head->next;
        }
        idx = lnVector.size() - n;
        if (idx == 0) {
            if (lnVector.size() > 1) return lnVector[1];
            else return nullptr;
        };
        lnVector[idx-1]->next = lnVector[idx]->next;
        return lnVector[0];
    }
};