class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> candidateStack;
        string result;

        if (num.size() <= k) return "0";

        for (int i=0; i<num.size(); i++) {
            while ((k) && (!candidateStack.empty()) && (num[i] < candidateStack.top())) {
                // cout << "pop:" << candidateStack.top() << endl;
                candidateStack.pop();
                k--;
            }
            // cout << "push:" << num[i] << endl;
            candidateStack.push(num[i]);
        }

        while (k) {
            candidateStack.pop();
            k--;
        }

        while (!candidateStack.empty()) {
            result.insert(result.begin(), candidateStack.top()); 
            candidateStack.pop();
        }

        // for (int i=0; i<result.size(); i++) {
        //     cout << result[i];
        // }

        while (result[0] == '0') {
            result.erase(result.begin());
        }

        if (result.size() == 0) return "0";
        return result;
    }
};