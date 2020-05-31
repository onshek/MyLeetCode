class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int num = nums.size() - 2;
        // cout << "nums.size=" << num << endl;
        for (int i = num; i >= 0; i--) {
            bool stop = true;
            for (int j = 0; j <= i; j++) {
                // cout << j << j + 1 << stop << endl;
                if (nums[j + 1] < nums[j]) {
                    int tmp = 0;
                    tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                    stop = false;
                }
            }
            if (stop == true) break;
        }
        for (int k = 0; k <= num; k++) {
            if (nums[k] == nums[k + 1]) return true;
        }
    return false;
    }
};