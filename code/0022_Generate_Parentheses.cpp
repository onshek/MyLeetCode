class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // related: 0046
        vector<string> result;
        string current;
        tryEveryChance(0, 0, n, current, result);
        return result;
    }

    void tryEveryChance(int leftNum, int rightNum, int n, string& current, vector<string>& result) {
        if (current.size() == n*2) {
            result.push_back(current);
            return;
        }
        if (leftNum < n) {
            current.push_back('(');
            tryEveryChance(leftNum+1, rightNum, n, current, result);
            current.pop_back();
        }

        if (rightNum < leftNum) {
            current.push_back(')');
            tryEveryChance(leftNum, rightNum+1, n, current, result);
            current.pop_back();
        }
    }
};