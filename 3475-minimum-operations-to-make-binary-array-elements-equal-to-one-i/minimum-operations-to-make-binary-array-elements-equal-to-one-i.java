class Solution {
    public int minOperations(int[] nums) {
        int n = 0;
        for (int i = 0; i < nums.length - 2; ++i)
            if (nums[i] == 0) 
            {
                ++n;
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        return nums[nums.length - 1] == 1 && nums[nums.length - 2] == 1 ? n : -1;
    }
}