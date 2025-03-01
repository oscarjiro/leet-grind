class Solution 
{
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size() - 1; ++i) 
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

        for (int i = 0, j = 0; i < nums.size() && j < nums.size(); ++j)
        {
            if (nums[i] != 0)
            {
                ++i;
                continue;
            }

            if (nums[j] != 0)
            {
                nums[i++] = nums[j];
                nums[j] = 0;
            }
        }

        return nums;
    }
};