class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // related: 0022
        vector<vector<int>> result;
        tryEveryChance(nums.size(), 0, nums, result);
        return result;
    }

    void tryEveryChance(int n, int firstIdx, vector<int>& current, vector<vector<int>>& result) {
        if (firstIdx == n) {
            result.push_back(current);
            return;
        }
        for (int i=firstIdx; i<current.size(); i++) {
            swap(current[i], current[firstIdx]);
            tryEveryChance(n, firstIdx+1, current, result);
            swap(current[firstIdx], current[i]);
        }
    }
};