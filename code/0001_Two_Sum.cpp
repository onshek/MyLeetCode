class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> result;
        for (int i=0; i<nums.size(); i++) {
            auto it = result.find(target - nums[i]);
            if (it != result.end()) {
                return {it->second, i};
            }
            result[nums[i]] = i;
        }
    return {};
    }
};


/*
执行用时：8 ms, 在所有 C++ 提交中击败了75.34% 的用户
内存消耗：8.6 MB, 在所有 C++ 提交中击败了90.44% 的用户
*/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//         for (int i=0; i<nums.size()-1; i++) {
//             for (int j=i+1; j<nums.size(); j++) {
//                 if ((target - nums[i]) == nums[j]) {
//                     result.push_back(i); 
//                     result.push_back(j);
//                     return result;
//                 }
//             }
//         }
//         return result;
//     }
// };
