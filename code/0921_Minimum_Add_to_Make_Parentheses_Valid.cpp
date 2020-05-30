class Solution {
public:
    int minAddToMakeValid(string S) {
        if (S.empty()) return 0;
        stack<char> pStack;
        for (char c: S) {
            if (!pStack.empty() && pStack.top()=='(' && c==')') pStack.pop();
            else pStack.push(c);
        }
        return pStack.size();
    }
};