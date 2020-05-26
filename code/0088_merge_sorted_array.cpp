// #include <iostream>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m + n;
        while (total >= 1) {
            // std::cout << total << m << n << std::endl;
            if (m >= 1 && n >= 1) {
                if (nums1[m - 1] > nums2[n - 1]) {
                    nums1[total - 1] = nums1[m - 1];
                    m -= 1;
                } else {
                    nums1[total - 1] = nums2[n - 1];
                    n -= 1;
                }
            } else if (m == 0 && n >= 1) {
                nums1[total - 1] = nums2[n - 1];
                n -= 1;
            } else if (n == 0 && m >= 1){
                nums1[total - 1] = nums1[m - 1];
                m -= 1;
            }
        total -= 1;
        }
    }
};