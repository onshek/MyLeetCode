class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = 0;
        vector<bool> res;
        for (int i: candies) maxNum = max(maxNum, i);
        for (int i: candies) {
            // cout << i << "+" << extraCandies << "->" << maxNum << endl;
            if ((i + extraCandies) >= maxNum) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};