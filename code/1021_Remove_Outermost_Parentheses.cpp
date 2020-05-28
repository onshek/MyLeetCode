class Solution {
public:
    string removeOuterParentheses(string S) {
        int j = 0;
        stack<int> s;
        queue<int> q;
        string result;

        for (int i=0; i<S.size(); i++) {
            if (S[i] == '(') s.push(i);
            else s.pop();
            if (s.size() == 0) {
                q.push(j);
                j = i;
                q.push(j);
                j++;
            }
        }

        for (int i=0; i<S.size(); i++) {
            if (i == q.front()) q.pop();
            else result.push_back(S[i]);
        }
        return result;
    }
};