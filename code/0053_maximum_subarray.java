class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int cur_sum = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < n; i++) {
            // System.out.printf(i + ", " + nums[i - 1] + ", " + nums[i] + "\n");
            nums[i] = nums[i - 1] < 0 ? nums[i] : nums[i - 1] + nums[i];
            // System.out.printf(i + ", " + nums[i - 1] + ", " + nums[i] + "\n");
            max_sum = Math.max(max_sum, nums[i]);
        }
        return max_sum;
    }
}