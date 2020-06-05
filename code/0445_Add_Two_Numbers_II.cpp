/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *//**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int sum = 0;
    bool plusOne = false;
    ListNode* res, *nextNode, *newNode;

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int tmpSum;
        stack<int> s1, s2;

        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        sum = s1.top() + s2.top();
        s1.pop(); s2.pop();
        if (sum > 9) {
            plusOne = true;
            sum -= 10;
        }
        nextNode = new ListNode(sum);

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty() && !s2.empty()) {
                tmpSum = s1.top() + s2.top();
                s1.pop(); s2.pop();
                handle(tmpSum);
            } else if (s2.empty()) {
                tmpSum = s1.top(); s1.pop();
                handle(tmpSum);
            } else {
                tmpSum = s2.top(); s2.pop();
                handle(tmpSum);
            }
        }
        if (plusOne) {
            newNode = new ListNode(1); 
            newNode->next = nextNode;
            nextNode = newNode;
        }
        return nextNode;
    }

    void handle(int tmpSum) {
        sum = plusOne? tmpSum + 1 : tmpSum;
        plusOne = (sum > 9) ? true : false;
        sum = (sum > 9) ? sum - 10 : sum;
        newNode = new ListNode(sum); 
        newNode->next = nextNode;
        nextNode = newNode;
    }
};