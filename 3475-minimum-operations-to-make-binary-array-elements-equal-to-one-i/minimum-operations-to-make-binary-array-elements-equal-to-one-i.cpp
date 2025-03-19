class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n = 0;
        for (int i = 0; i < nums.size() - 2; ++i)
            if (nums[i] == 0)
                ++n,
                nums[i] = 1,
                nums[i + 1] ^= 1,    
                nums[i + 2] ^= 1;
        return nums[nums.size() - 1] && nums[nums.size() - 2] ? n : -1; 
    }
};