class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (auto item: intervals) {
            int lVal=item[0], rVal=item[1];
            if ((!result.empty()) && (result.back()[1]>=lVal)) {
                if (result.back()[1]<rVal) result.back()[1] = rVal;
            }
            else result.push_back(item);
        }
        return result;
    }
};