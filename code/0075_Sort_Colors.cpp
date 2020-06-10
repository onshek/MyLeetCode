class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> cntMap;
        cntMap[0] = 0;
        cntMap[1] = 0;
        cntMap[2] = 0;
        for (int i=0; i<nums.size(); i++) {
            int num = nums[i], firstIdx;
            cntMap[num]++;
            if (num==0) firstIdx = cntMap[0];
            else if (num==1) firstIdx = cntMap[0] + cntMap[1];
            else firstIdx = cntMap[0] + cntMap[1] + cntMap[2];
            if (firstIdx == i+1) continue;

            for (int j=i; j>=firstIdx; j--) swap(nums[j], nums[j-1]);
            nums[firstIdx-1] = num;
            // for (auto item: nums) cout << item << " ";
            // cout << endl;
        }
    }
};