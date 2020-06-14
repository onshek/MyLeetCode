class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int tmp = 0;
        if (nums.empty()) return res;
        for (int num: nums) {
            tmp += num;
            res.push_back(tmp);
        }
        return res;
    }
};