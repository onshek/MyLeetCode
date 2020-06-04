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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        vector<ListNode*> lnVector;
        while (head) {
            lnVector.push_back(head);
            head = head->next;
        }
        k = k % lnVector.size();
        if (k==0) return lnVector[0];
        if (lnVector.size() == 1) return lnVector[0];
        int idx = lnVector.size() - k;
        lnVector[idx-1]->next = NULL;
        lnVector[lnVector.size()-1]->next = lnVector[0];
        return lnVector[idx];
    }
};