class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int n: nums) { if (to_string(n).size() % 2 == 0) res++; }
        return res;
    }
};