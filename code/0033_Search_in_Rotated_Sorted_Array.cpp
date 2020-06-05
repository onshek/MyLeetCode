class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int idx, lastIdx = nums.size()-1;
        bool sorted = true;
        for (int i=0; i<lastIdx; i++) {
            if (nums[i] > nums[i+1]) {
                idx = i + 1; 
                sorted = false; 
                break;
            }
        }
        // cout << "idx=" << idx << endl;
        // resort vector
        if (!sorted) {
            for (int i=0; i<idx; i++) {
                int tmp = nums[0];
                nums.erase(nums.begin());
                nums.push_back(tmp);
            }
        }
        // for (auto s: nums) cout << s << " ";
        // cout << endl;
        int lo = 0, hi = lastIdx, mid = (lo+hi) / 2;
        while (lo <= hi) {
            if (target < nums[mid]) {
                hi = mid - 1;
                mid = (lo+hi) / 2;
            } else if (nums[mid] < target) {
                lo = mid + 1;
                mid = (lo+hi) / 2;            
            } else {
                // cout << "mid=" << mid << ", idx=" << idx << ", lastIdx=" << lastIdx;
                return (sorted) ? mid : (mid + idx) % nums.size();
            }
        }
        return -1;
    }
};  