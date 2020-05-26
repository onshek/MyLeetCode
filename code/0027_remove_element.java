class Solution {
    public int removeElement(int[] nums, int val) {
        int j = 0;
        for (int k = 0; k < nums.length; k++) {
            if (nums[k] != val) {
                nums[j] = nums[k];
                j++;
            }
        }
        return j;
    }
}