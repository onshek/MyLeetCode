class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> tmpS;
        int i = 0;
        for (int j=0; j<pushed.size(); j++) {
            tmpS.push(pushed[j]);
            while (!tmpS.empty() && tmpS.top()==popped[i]) {
                tmpS.pop(); i++;
            }
        }
        return (tmpS.empty() && i==popped.size());
    }
};