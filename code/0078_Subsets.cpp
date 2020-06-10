class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // related: 0797
        int totalLength = nums.size();
        for (int targetLength=0; targetLength<=totalLength; targetLength++) 
            tryEveryChance(totalLength, targetLength, 0, vector<int>(), nums);
        return res;
    }

    void tryEveryChance(int totalLength, int targetLength, int firstIdx, vector<int> current, vector<int>& nums) {
        if (current.size() == targetLength) { 
            res.push_back(current); 
        }
        for (int j=firstIdx; j<totalLength; j++) {
            current.push_back(nums[j]);
            tryEveryChance(totalLength, targetLength, j+1, current, nums);
            current.pop_back();
        }
    }
};