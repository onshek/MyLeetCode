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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode *res, *fakeNode, *firstNode, *secondNode;
        res = head->next ? head->next : head;
        fakeNode = new ListNode(); fakeNode->next = head;
        while (fakeNode) {
            if (fakeNode->next && fakeNode->next->next) {
                firstNode = fakeNode->next; secondNode = fakeNode->next->next;
                fakeNode->next = secondNode;
                firstNode->next = secondNode->next;
                secondNode->next = firstNode;
                fakeNode = fakeNode->next->next;
            } else break;
        }
        return res;
    }
};