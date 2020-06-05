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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        int sum;
        ListNode* fakeNode, *fakeNodeCopy;
        bool plusOne = false;
        queue<int> plusRes, res;

        while (true) {
            if (l1 && l2) { 
                plusRes.push(l1->val + l2->val);
                l1 = l1->next; l2 = l2->next;
            } else if (!l1 && l2) { plusRes.push(l2->val); l2 = l2->next; } 
            else if (l1 && !l2) { plusRes.push(l1->val); l1 = l1->next; } 
            else break;
        } 

        while (!plusRes.empty()) {
            sum = plusRes.front(); plusRes.pop();
            sum = plusOne ? sum + 1 : sum;
            plusOne = (sum >= 10) ? true : false;
            sum = (sum >= 10) ? sum - 10 : sum;
            res.push(sum);            
        } 

        if (plusOne) res.push(1);
        fakeNode = new ListNode(); fakeNodeCopy = fakeNode;
        while (!res.empty()) {
            ListNode* node = new ListNode(res.front()); res.pop();
            fakeNode->next = node;
            fakeNode = node;
        }
        return fakeNodeCopy->next;
    }
};